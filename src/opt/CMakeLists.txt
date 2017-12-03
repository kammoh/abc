target_sources(libabc PRIVATE src/opt/cut/cutApi.c src/opt/cut/cutCut.c src/opt/cut/cutMan.c src/opt/cut/cutMerge.c src/opt/cut/cutNode.c
        src/opt/cut/cutOracle.c src/opt/cut/cutPre22.c src/opt/cut/cutSeq.c src/opt/cut/cutTruth.c src/opt/fxu/fxu.c
        src/opt/fxu/fxuCreate.c src/opt/fxu/fxuHeapD.c src/opt/fxu/fxuHeapS.c src/opt/fxu/fxuList.c
        src/opt/fxu/fxuMatrix.c src/opt/fxu/fxuPair.c src/opt/fxu/fxuPrint.c src/opt/fxu/fxuReduce.c
        src/opt/fxu/fxuSelect.c src/opt/fxu/fxuSingle.c src/opt/fxu/fxuUpdate.c src/opt/fxch/Fxch.c
        src/opt/fxch/FxchDiv.c src/opt/fxch/FxchMan.c src/opt/fxch/FxchSCHashTable.c src/opt/rwr/rwrDec.c
        src/opt/rwr/rwrEva.c src/opt/rwr/rwrExp.c src/opt/rwr/rwrLib.c src/opt/rwr/rwrMan.c src/opt/rwr/rwrPrint.c
        src/opt/rwr/rwrUtil.c src/opt/mfs/mfsCore.c src/opt/mfs/mfsDiv.c src/opt/mfs/mfsInter.c src/opt/mfs/mfsMan.c
        src/opt/mfs/mfsResub.c src/opt/mfs/mfsSat.c src/opt/mfs/mfsStrash.c src/opt/mfs/mfsWin.c src/opt/sim/simMan.c
        src/opt/sim/simSeq.c src/opt/sim/simSupp.c src/opt/sim/simSwitch.c src/opt/sim/simSym.c src/opt/sim/simSymSat.c
        src/opt/sim/simSymSim.c src/opt/sim/simSymStr.c src/opt/sim/simUtils.c src/opt/ret/retArea.c
        src/opt/ret/retCore.c src/opt/ret/retDelay.c src/opt/ret/retFlow.c src/opt/ret/retIncrem.c src/opt/ret/retInit.c
        src/opt/ret/retLvalue.c src/opt/fret/fretMain.c src/opt/fret/fretFlow.c src/opt/fret/fretInit.c
        src/opt/fret/fretTime.c src/opt/res/resCore.c src/opt/res/resDivs.c src/opt/res/resFilter.c src/opt/res/resSat.c
        src/opt/res/resSim.c src/opt/res/resStrash.c src/opt/res/resWin.c src/opt/lpk/lpkCore.c src/opt/lpk/lpkAbcDec.c
        src/opt/lpk/lpkAbcMux.c src/opt/lpk/lpkAbcDsd.c src/opt/lpk/lpkAbcUtil.c src/opt/lpk/lpkCut.c
        src/opt/lpk/lpkMan.c src/opt/lpk/lpkMap.c src/opt/lpk/lpkMulti.c src/opt/lpk/lpkMux.c src/opt/lpk/lpkSets.c
        src/opt/nwk/nwkAig.c src/opt/nwk/nwkCheck.c src/opt/nwk/nwkBidec.c src/opt/nwk/nwkDfs.c src/opt/nwk/nwkFanio.c
        src/opt/nwk/nwkFlow.c src/opt/nwk/nwkMan.c src/opt/nwk/nwkMap.c src/opt/nwk/nwkMerge.c src/opt/nwk/nwkObj.c
        src/opt/nwk/nwkSpeedup.c src/opt/nwk/nwkStrash.c src/opt/nwk/nwkTiming.c src/opt/nwk/nwkUtil.c
        src/opt/rwt/rwtDec.c src/opt/rwt/rwtMan.c src/opt/rwt/rwtUtil.c src/opt/cgt/cgtAig.c src/opt/cgt/cgtCore.c
        src/opt/cgt/cgtDecide.c src/opt/cgt/cgtMan.c src/opt/cgt/cgtSat.c src/opt/csw/cswCore.c src/opt/csw/cswCut.c
        src/opt/csw/cswMan.c src/opt/csw/cswTable.c src/opt/dar/darBalance.c src/opt/dar/darCore.c src/opt/dar/darCut.c
        src/opt/dar/darData.c src/opt/dar/darLib.c src/opt/dar/darMan.c src/opt/dar/darPrec.c src/opt/dar/darRefact.c
        src/opt/dar/darScript.c src/opt/dau/dauCanon.c src/opt/dau/dauCore.c src/opt/dau/dauDivs.c src/opt/dau/dauDsd.c
        src/opt/dau/dauEnum.c src/opt/dau/dauGia.c src/opt/dau/dauMerge.c src/opt/dau/dauNonDsd.c src/opt/dau/dauTree.c
        src/opt/dsc/dsc.c src/opt/sfm/sfmArea.c src/opt/sfm/sfmCnf.c src/opt/sfm/sfmCore.c src/opt/sfm/sfmDec.c
        src/opt/sfm/sfmLib.c src/opt/sfm/sfmNtk.c src/opt/sfm/sfmSat.c src/opt/sfm/sfmTim.c src/opt/sfm/sfmMit.c
        src/opt/sfm/sfmWin.c src/opt/sbd/sbd.c src/opt/sbd/sbdCnf.c src/opt/sbd/sbdCore.c src/opt/sbd/sbdCut.c
        src/opt/sbd/sbdCut2.c src/opt/sbd/sbdLut.c src/opt/sbd/sbdPath.c src/opt/sbd/sbdSat.c src/opt/sbd/sbdWin.c)
