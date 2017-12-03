target_sources(libabc PRIVATE src/sat/bsat/satMem.c src/sat/bsat/satInter.c src/sat/bsat/satInterA.c src/sat/bsat/satInterB.c
        src/sat/bsat/satInterP.c src/sat/bsat/satProof.c src/sat/bsat/satSolver.c src/sat/bsat/satSolver2.c
        src/sat/bsat/satSolver2i.c src/sat/bsat/satSolver3.c src/sat/bsat/satStore.c src/sat/bsat/satTrace.c
        src/sat/bsat/satTruth.c src/sat/bsat/satUtil.c src/sat/xsat/xsatSolver.c src/sat/xsat/xsatSolverAPI.c
        src/sat/xsat/xsatCnfReader.c src/sat/satoko/solver.c src/sat/satoko/solver_api.c src/sat/satoko/cnf_reader.c
        src/sat/csat/csat_apis.c src/sat/msat/msatActivity.c src/sat/msat/msatClause.c src/sat/msat/msatClauseVec.c
        src/sat/msat/msatMem.c src/sat/msat/msatOrderH.c src/sat/msat/msatQueue.c src/sat/msat/msatRead.c
        src/sat/msat/msatSolverApi.c src/sat/msat/msatSolverCore.c src/sat/msat/msatSolverIo.c
        src/sat/msat/msatSolverSearch.c src/sat/msat/msatSort.c src/sat/msat/msatVec.c src/sat/cnf/cnfCore.c
        src/sat/cnf/cnfCut.c src/sat/cnf/cnfData.c src/sat/cnf/cnfFast.c src/sat/cnf/cnfMan.c src/sat/cnf/cnfMap.c
        src/sat/cnf/cnfPost.c src/sat/cnf/cnfUtil.c src/sat/cnf/cnfWrite.c src/sat/bmc/bmcBCore.c src/sat/bmc/bmcBmc.c
        src/sat/bmc/bmcBmc2.c src/sat/bmc/bmcBmc3.c src/sat/bmc/bmcBmcAnd.c src/sat/bmc/bmcBmci.c src/sat/bmc/bmcBmcG.c
        src/sat/bmc/bmcBmcS.c src/sat/bmc/bmcCexCare.c src/sat/bmc/bmcCexCut.c src/sat/bmc/bmcCexDepth.c
        src/sat/bmc/bmcCexMin1.c src/sat/bmc/bmcCexMin2.c src/sat/bmc/bmcCexTools.c src/sat/bmc/bmcChain.c
        src/sat/bmc/bmcClp.c src/sat/bmc/bmcEco.c src/sat/bmc/bmcExpand.c src/sat/bmc/bmcFault.c src/sat/bmc/bmcFx.c
        src/sat/bmc/bmcGen.c src/sat/bmc/bmcICheck.c src/sat/bmc/bmcInse.c src/sat/bmc/bmcLoad.c src/sat/bmc/bmcMaj.c
        src/sat/bmc/bmcMaj2.c src/sat/bmc/bmcMaxi.c src/sat/bmc/bmcMesh.c src/sat/bmc/bmcMesh2.c src/sat/bmc/bmcMulti.c
        src/sat/bmc/bmcUnroll.c src/sat/glucose/AbcGlucose.cpp src/sat/glucose/AbcGlucoseCmd.cpp
        src/sat/glucose/Glucose.cpp src/sat/glucose/Options.cpp src/sat/glucose/SimpSolver.cpp
        src/sat/glucose/System.cpp)
