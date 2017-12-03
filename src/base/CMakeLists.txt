target_sources(libabc PRIVATE src/base/abc/abcAig.c src/base/abc/abcBarBuf.c src/base/abc/abcBlifMv.c src/base/abc/abcCheck.c
        src/base/abc/abcDfs.c src/base/abc/abcFanio.c src/base/abc/abcFanOrder.c src/base/abc/abcFunc.c
        src/base/abc/abcHie.c src/base/abc/abcHieCec.c src/base/abc/abcHieGia.c src/base/abc/abcHieNew.c
        src/base/abc/abcLatch.c src/base/abc/abcLib.c src/base/abc/abcMinBase.c src/base/abc/abcNames.c
        src/base/abc/abcNetlist.c src/base/abc/abcNtk.c src/base/abc/abcObj.c src/base/abc/abcRefs.c
        src/base/abc/abcShow.c src/base/abc/abcSop.c src/base/abc/abcUtil.c src/base/abci/abc.c
        src/base/abci/abcAttach.c src/base/abci/abcAuto.c src/base/abci/abcBalance.c src/base/abci/abcBidec.c
        src/base/abci/abcBm.c src/base/abci/abcBmc.c src/base/abci/abcCas.c src/base/abci/abcCascade.c
        src/base/abci/abcCollapse.c src/base/abci/abcCut.c src/base/abci/abcDar.c src/base/abci/abcDebug.c
        src/base/abci/abcDec.c src/base/abci/abcDetect.c src/base/abci/abcDress.c src/base/abci/abcDress2.c
        src/base/abci/abcDress3.c src/base/abci/abcDsd.c src/base/abci/abcEco.c src/base/abci/abcExact.c
        src/base/abci/abcExtract.c src/base/abci/abcFraig.c src/base/abci/abcFx.c src/base/abci/abcFxu.c
        src/base/abci/abcGen.c src/base/abci/abcHaig.c src/base/abci/abcIf.c src/base/abci/abcIfif.c
        src/base/abci/abcIfMux.c src/base/abci/abcIvy.c src/base/abci/abcLog.c src/base/abci/abcLut.c
        src/base/abci/abcLutmin.c src/base/abci/abcMap.c src/base/abci/abcMerge.c src/base/abci/abcMfs.c
        src/base/abci/abcMini.c src/base/abci/abcMiter.c src/base/abci/abcMulti.c src/base/abci/abcNtbdd.c
        src/base/abci/abcNpn.c src/base/abci/abcNpnSave.c src/base/abci/abcOdc.c src/base/abci/abcOrder.c
        src/base/abci/abcPart.c src/base/abci/abcPrint.c src/base/abci/abcProve.c src/base/abci/abcQbf.c
        src/base/abci/abcQuant.c src/base/abci/abcRec3.c src/base/abci/abcReconv.c src/base/abci/abcReach.c
        src/base/abci/abcRefactor.c src/base/abci/abcRenode.c src/base/abci/abcReorder.c src/base/abci/abcRestruct.c
        src/base/abci/abcResub.c src/base/abci/abcRewrite.c src/base/abci/abcRpo.c src/base/abci/abcRr.c
        src/base/abci/abcSat.c src/base/abci/abcSaucy.c src/base/abci/abcScorr.c src/base/abci/abcSense.c
        src/base/abci/abcSpeedup.c src/base/abci/abcStrash.c src/base/abci/abcSweep.c src/base/abci/abcSymm.c
        src/base/abci/abcTim.c src/base/abci/abcTiming.c src/base/abci/abcUnate.c src/base/abci/abcUnreach.c
        src/base/abci/abcVerify.c src/base/abci/abcXsim.c src/base/cmd/cmd.c src/base/cmd/cmdAlias.c
        src/base/cmd/cmdApi.c src/base/cmd/cmdAuto.c src/base/cmd/cmdFlag.c src/base/cmd/cmdHist.c
        src/base/cmd/cmdLoad.c src/base/cmd/cmdPlugin.c src/base/cmd/cmdStarter.c src/base/cmd/cmdUtils.c
        src/base/io/io.c src/base/io/ioJson.c src/base/io/ioReadAiger.c src/base/io/ioReadBaf.c
        src/base/io/ioReadBblif.c src/base/io/ioReadBench.c src/base/io/ioReadBlif.c src/base/io/ioReadBlifAig.c
        src/base/io/ioReadBlifMv.c src/base/io/ioReadDsd.c src/base/io/ioReadEdif.c src/base/io/ioReadEqn.c
        src/base/io/ioReadPla.c src/base/io/ioReadPlaMo.c src/base/io/ioReadVerilog.c src/base/io/ioUtil.c
        src/base/io/ioWriteAiger.c src/base/io/ioWriteBaf.c src/base/io/ioWriteBblif.c src/base/io/ioWriteBench.c
        src/base/io/ioWriteBlif.c src/base/io/ioWriteBlifMv.c src/base/io/ioWriteBook.c src/base/io/ioWriteCnf.c
        src/base/io/ioWriteDot.c src/base/io/ioWriteEqn.c src/base/io/ioWriteGml.c src/base/io/ioWriteList.c
        src/base/io/ioWritePla.c src/base/io/ioWriteVerilog.c src/base/io/ioWriteSmv.c
        src/base/main/mainFrame.c src/base/main/mainInit.c src/base/main/mainLib.c src/base/main/mainReal.c
        src/base/main/libSupport.c src/base/main/mainUtils.c src/base/exor/exor.c src/base/exor/exorBits.c
        src/base/exor/exorCubes.c src/base/exor/exorLink.c src/base/exor/exorList.c src/base/exor/exorUtil.c
        src/base/ver/verCore.c src/base/ver/verFormula.c src/base/ver/verParse.c src/base/ver/verStream.c
        src/base/wlc/wlcAbs.c src/base/wlc/wlcAbs2.c src/base/wlc/wlcAbc.c src/base/wlc/wlcPth.c src/base/wlc/wlcBlast.c
        src/base/wlc/wlcCom.c src/base/wlc/wlcGraft.c src/base/wlc/wlcJson.c src/base/wlc/wlcNtk.c
        src/base/wlc/wlcReadSmt.c src/base/wlc/wlcReadVer.c src/base/wlc/wlcSim.c src/base/wlc/wlcShow.c
        src/base/wlc/wlcStdin.c src/base/wlc/wlcUif.c src/base/wlc/wlcWin.c src/base/wlc/wlcWriteVer.c
        src/base/acb/acbAbc.c src/base/acb/acbAig.c src/base/acb/acbCom.c src/base/acb/acbFunc.c src/base/acb/acbMfs.c
        src/base/acb/acbPush.c src/base/acb/acbSets.c src/base/acb/acbUtil.c src/base/bac/bacBlast.c
        src/base/bac/bacBac.c src/base/bac/bacCom.c src/base/bac/bacLib.c src/base/bac/bacNtk.c
        src/base/bac/bacPrsBuild.c src/base/bac/bacPrsTrans.c src/base/bac/bacPtr.c src/base/bac/bacPtrAbc.c
        src/base/bac/bacReadBlif.c src/base/bac/bacReadSmt.c src/base/bac/bacReadVer.c src/base/bac/bacWriteBlif.c
        src/base/bac/bacWriteSmt.c src/base/bac/bacWriteVer.c src/base/cba/cbaBlast.c src/base/cba/cbaCba.c
        src/base/cba/cbaCom.c src/base/cba/cbaNtk.c src/base/cba/cbaReadBlif.c src/base/cba/cbaReadVer.c
        src/base/cba/cbaWriteBlif.c src/base/cba/cbaWriteVer.c src/base/pla/plaCom.c src/base/pla/plaHash.c
        src/base/pla/plaMan.c src/base/pla/plaMerge.c src/base/pla/plaSimple.c src/base/pla/plaRead.c
        src/base/pla/plaWrite.c src/base/test/test.c)