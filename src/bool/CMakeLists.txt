target_sources(libabc PRIVATE src/bool/bdc/bdcCore.c src/bool/bdc/bdcDec.c src/bool/bdc/bdcSpfd.c
        src/bool/bdc/bdcTable.c src/bool/dec/decAbc.c src/bool/dec/decFactor.c src/bool/dec/decMan.c
        src/bool/dec/decPrint.c src/bool/dec/decUtil.c src/bool/kit/kitAig.c src/bool/kit/kitBdd.c
        src/bool/kit/kitCloud.c src/bool/kit/cloud.c src/bool/kit/kitDsd.c src/bool/kit/kitFactor.c
        src/bool/kit/kitGraph.c src/bool/kit/kitHop.c src/bool/kit/kitIsop.c src/bool/kit/kitPla.c src/bool/kit/kitSop.c
        src/bool/kit/kitTruth.c src/bool/lucky/lucky.c src/bool/lucky/luckyFast16.c src/bool/lucky/luckyFast6.c
        src/bool/lucky/luckyRead.c src/bool/lucky/luckySimple.c src/bool/lucky/luckySwapIJ.c src/bool/lucky/luckySwap.c
        src/bool/rsb/rsbDec6.c src/bool/rsb/rsbMan.c src/bool/rpo/rpo.c)