target_sources(libabc PRIVATE src/misc/extra/extraUtilBitMatrix.c src/misc/extra/extraUtilCanon.c src/misc/extra/extraUtilCube.c
        src/misc/extra/extraUtilDsd.c src/misc/extra/extraUtilEnum.c src/misc/extra/extraUtilFile.c
        src/misc/extra/extraUtilMemory.c src/misc/extra/extraUtilMisc.c src/misc/extra/extraUtilPerm.c
        src/misc/extra/extraUtilProgress.c src/misc/extra/extraUtilReader.c src/misc/extra/extraUtilSupp.c
        src/misc/extra/extraUtilTruth.c src/misc/extra/extraUtilUtil.c src/misc/mvc/mvcApi.c src/misc/mvc/mvcCompare.c
        src/misc/mvc/mvcContain.c src/misc/mvc/mvcCover.c src/misc/mvc/mvcCube.c src/misc/mvc/mvcDivide.c
        src/misc/mvc/mvcDivisor.c src/misc/mvc/mvcList.c src/misc/mvc/mvcLits.c src/misc/mvc/mvcMan.c
        src/misc/mvc/mvcOpAlg.c src/misc/mvc/mvcOpBool.c src/misc/mvc/mvcPrint.c src/misc/mvc/mvcSort.c
        src/misc/mvc/mvcUtils.c src/misc/st/st.c src/misc/st/stmm.c src/misc/util/utilBridge.c src/misc/util/utilCex.c
        src/misc/util/utilColor.c src/misc/util/utilFile.c src/misc/util/utilIsop.c src/misc/util/utilNam.c
        src/misc/util/utilSignal.c src/misc/util/utilSort.c src/misc/nm/nmApi.c src/misc/nm/nmTable.c
        src/misc/tim/timBox.c src/misc/tim/timDump.c src/misc/tim/timMan.c src/misc/tim/timTime.c src/misc/tim/timTrav.c
        src/misc/mem/mem.c src/misc/bar/bar.c src/misc/bbl/bblif.c src/misc/parse/parseEqn.c src/misc/parse/parseStack.c
    )

add_subdirectory(espresso)