cmake_minimum_required(VERSION 3.10.0)

include(CMakeParseArguments)
include(CheckCCompilerFlag)
include(CheckCXXCompilerFlag)
include(CheckTypeSize)


function(addprefix var prefix)
    foreach( s ${ARGN} )
        list(APPEND tmp "-I${s}")
    endforeach()
    set(${var} ${tmp} PARENT_SCOPE)
endfunction()

# filter out flags that are not appropriate for the compiler being used
function(target_compile_options_filtered target visibility)
    foreach( flag ${ARGN} )
        if( flag MATCHES "^-D.*" )
            target_compile_options( ${target} ${visibility} ${flag} )
        else()
            check_c_compiler_flag( ${flag} C_COMPILER_SUPPORTS__${flag} )
            if( C_COMPILER_SUPPORTS__${flag} )
                target_compile_options( ${target} ${visibility} $<$<COMPILE_LANGUAGE:C>:${flag}> )
            endif()

            check_cxx_compiler_flag( ${flag} CXX_COMPILER_SUPPORTS__${flag} )
            if( CXX_COMPILER_SUPPORTS__${flag} )
                target_compile_options( ${target} ${visibility} $<$<COMPILE_LANGUAGE:CXX>:${flag}>  )
            endif()
        endif()
    endforeach()
endfunction()

project(abc)

if(READLINE_FOUND MATCHES TRUE)
    addprefix(ABC_READLINE_INCLUDES_FLAGS "-I" ${READLINE_INCLUDE})
    string(REPLACE ";" " " ABC_READLINE_INCLUDES_FLAGS "${ABC_READLINE_INCLUDES_FLAGS}")
    list(APPEND ABC_READLINE_FLAGS "ABC_READLINE_INCLUDES=${ABC_READLINE_INCLUDES_FLAGS}")

    string(REPLACE ";" " " ABC_READLINE_LIBRARIES_FLAGS "${READLINE_LIBRARIES}")
    list(APPEND ABC_READLINE_FLAGS "ABC_READLINE_LIBRARIES=${ABC_READLINE_LIBRARIES_FLAGS}")
elseif(READLINE_FOUND MATCHES FALSE)
    list(APPEND ABC_READLINE_FLAGS "ABC_USE_NO_READLINE=1")
endif()

if(ABC_USE_NAMESPACE)
    set(ABC_USE_NAMESPACE_FLAGS "ABC_USE_NAMESPACE=${ABC_USE_NAMESPACE}")
endif()

check_type_size("void*" SIZEOF_DATA_PTR)
check_type_size("long" SIZEOF_LONG)
check_type_size("int" SIZEOF_INT)

if(${SIZEOF_DATA_PTR} MATCHES 8)
    set(ARCH LIN64)
else()
    set(ARCH LIN)
endif()

find_package( ZLIB REQUIRED )
find_package( BZip2 REQUIRED )


set(SIZE_DEFS -D${ARCH} -DSIZEOF_VOID_P=${SIZEOF_DATA_PTR} -DSIZEOF_LONG=${SIZEOF_LONG} -DSIZEOF_INT=${SIZEOF_INT})

set(ABC_LIBS ${ZLIB_LIBRARIES} ${BZIP2_LIBRARIES} -lreadline -lpthread -ldl -lm)

set(OPT_FLAGS -O3 -march=native -mtune=native -fomit-frame-pointer -g0)

set(WARN_FLAGS -Wall -Wno-unused-function -Wno-write-strings -Wno-sign-compare) # -Wextra

set(ABC_CFLAGS ${SIZE_DEFS} ${OPT_FLAGS} ${WARN_FLAGS} -DABC_USE_CUDD=1 -DABC_USE_READLINE -DABC_USE_PTHREADS)

set(ABC_CXXFLAGS  ${OPT_FLAGS} ${WARN_FLAGS} ${SIZE_DEFS} -DABC_USE_CUDD=1 -DABC_USE_READLINE -DABC_USE_PTHREADS)


if(ABC_USE_NAMESPACE)
    set_source_files_properties(${ABC_SRC} PROPERTIES LANGUAGE CXX)
endif()



# use, i.e. don't skip the full RPATH for the build tree
SET(CMAKE_SKIP_BUILD_RPATH  FALSE)

# when building, don't use the install RPATH already
# (but later on when installing)
SET(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)

SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

# add the automatically determined parts of the RPATH
# which point to directories outside the build tree to the install RPATH
SET(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)


# the RPATH to be used when installing, but only if it's not a system directory
LIST(FIND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES "${CMAKE_INSTALL_PREFIX}/lib" isSystemDir)
IF("${isSystemDir}" STREQUAL "-1")
    SET(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
ENDIF("${isSystemDir}" STREQUAL "-1")

add_library(libabc SHARED)

include_directories(src)

target_include_directories(libabc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src ${ZLIB_INCLUDE_DIRS} ${BZIP2_INCLUDE_DIR})
target_compile_options_filtered(libabc PUBLIC ${ABC_CFLAGS} ${ABC_CXXFLAGS})
target_link_libraries(libabc PUBLIC ${ABC_LIBS})

set_property(TARGET libabc PROPERTY OUTPUT_NAME abc)
set_target_properties(libabc PROPERTIES VERSION 0.1.0)
set_target_properties(libabc PROPERTIES SOVERSION 0.1.0)
set_property(TARGET libabc PROPERTY POSITION_INDEPENDENT_CODE ON)

add_subdirectory(src)

add_executable(abc src/base/main/main.c)
target_include_directories(abc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(abc libabc)

add_executable(demo src/demo.c)
target_include_directories(demo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(demo libabc)