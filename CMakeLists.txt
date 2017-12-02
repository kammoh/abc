cmake_minimum_required(VERSION 3.8.0)

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

include(sourcelist.cmake)

check_type_size("void*" SIZEOF_DATA_PTR)
CHECK_TYPE_SIZE("long" SIZEOF_LONG)
CHECK_TYPE_SIZE("int" SIZEOF_INT)

if(${SIZEOF_DATA_PTR} MATCHES 8)
    set(ARCH LIN64)
else()
    set(ARCH LIN)
endif()

set(SIZE_DEFS -D${ARCH} -DSIZEOF_VOID_P=${SIZEOF_DATA_PTR} -DSIZEOF_LONG=${SIZEOF_LONG} -DSIZEOF_INT=${SIZEOF_INT})

set(ABC_LIBS -lreadline -lpthread -ldl -lm)

set(OPT_FLAGS -O3 -march=native -mtune=native -fomit-frame-pointer -g0)

set(WARN_FLAGS -Wall -Wno-unused-function -Wno-write-strings -Wno-sign-compare) # -Wextra

set(ABC_CFLAGS ${SIZE_DEFS} ${OPT_FLAGS} ${WARN_FLAGS} -DABC_USE_CUDD=1 -DABC_USE_READLINE -DABC_USE_PTHREADS)

set(ABC_CXXFLAGS  ${OPT_FLAGS} ${WARN_FLAGS} ${SIZE_DEFS} -DABC_USE_CUDD=1 -DABC_USE_READLINE -DABC_USE_PTHREADS)


if(ABC_USE_NAMESPACE)
    set_source_files_properties(${ABC_SRC} PROPERTIES LANGUAGE CXX)
endif()

function(abc_properties target visibility)
    target_include_directories(${target} ${visibility} ${CMAKE_CURRENT_SOURCE_DIR}/src )
    target_compile_options_filtered(${target} ${visibility} ${ABC_CFLAGS} ${ABC_CXXFLAGS})
    target_link_libraries(${target} ${visibility} ${ABC_LIBS})
endfunction()

list(REMOVE_ITEM ABC_SRC src/base/main/main.c)

add_library(libabc SHARED EXCLUDE_FROM_ALL ${ABC_SRC})
abc_properties(libabc PUBLIC)
set_property(TARGET libabc PROPERTY OUTPUT_NAME abc)
set_property(TARGET libabc PROPERTY POSITION_INDEPENDENT_CODE ON)
