target_sources(libabc PRIVATE src/aig/aig/aigCheck.c src/aig/aig/aigCanon.c
        src/aig/aig/aigCuts.c src/aig/aig/aigDfs.c src/aig/aig/aigDup.c src/aig/aig/aigFanout.c src/aig/aig/aigFrames.c
        src/aig/aig/aigInter.c src/aig/aig/aigJust.c src/aig/aig/aigMan.c src/aig/aig/aigMem.c src/aig/aig/aigMffc.c
        src/aig/aig/aigObj.c src/aig/aig/aigOper.c src/aig/aig/aigOrder.c src/aig/aig/aigPack.c src/aig/aig/aigPart.c
        src/aig/aig/aigPartReg.c src/aig/aig/aigPartSat.c src/aig/aig/aigRepr.c src/aig/aig/aigRet.c
        src/aig/aig/aigRetF.c src/aig/aig/aigScl.c src/aig/aig/aigShow.c src/aig/aig/aigSplit.c src/aig/aig/aigTable.c
        src/aig/aig/aigTiming.c src/aig/aig/aigTruth.c src/aig/aig/aigTsim.c src/aig/aig/aigUtil.c src/aig/aig/aigWin.c
        src/aig/saig/saigCone.c src/aig/saig/saigConstr.c src/aig/saig/saigConstr2.c src/aig/saig/saigDual.c
        src/aig/saig/saigDup.c src/aig/saig/saigInd.c src/aig/saig/saigIoa.c src/aig/saig/saigIso.c
        src/aig/saig/saigIsoFast.c src/aig/saig/saigIsoSlow.c src/aig/saig/saigMiter.c src/aig/saig/saigOutDec.c
        src/aig/saig/saigPhase.c src/aig/saig/saigRetFwd.c src/aig/saig/saigRetMin.c src/aig/saig/saigRetStep.c
        src/aig/saig/saigScl.c src/aig/saig/saigSimFast.c src/aig/saig/saigSimMv.c src/aig/saig/saigSimSeq.c
        src/aig/saig/saigStrSim.c src/aig/saig/saigSwitch.c src/aig/saig/saigSynch.c src/aig/saig/saigTempor.c
        src/aig/saig/saigTrans.c src/aig/saig/saigWnd.c src/aig/gia/giaAig.c src/aig/gia/giaAgi.c src/aig/gia/giaAiger.c
        src/aig/gia/giaAigerExt.c src/aig/gia/giaBalAig.c src/aig/gia/giaBalLut.c src/aig/gia/giaBalMap.c
        src/aig/gia/giaBidec.c src/aig/gia/giaCCof.c src/aig/gia/giaCex.c src/aig/gia/giaClp.c src/aig/gia/giaCof.c
        src/aig/gia/giaCone.c src/aig/gia/giaCSatOld.c src/aig/gia/giaCSat.c src/aig/gia/giaCTas.c src/aig/gia/giaCut.c
        src/aig/gia/giaDfs.c src/aig/gia/giaDup.c src/aig/gia/giaEdge.c src/aig/gia/giaEmbed.c src/aig/gia/giaEnable.c
        src/aig/gia/giaEquiv.c src/aig/gia/giaEra.c src/aig/gia/giaEra2.c src/aig/gia/giaEsop.c src/aig/gia/giaExist.c
        src/aig/gia/giaFalse.c src/aig/gia/giaFanout.c src/aig/gia/giaForce.c src/aig/gia/giaFrames.c
        src/aig/gia/giaFront.c src/aig/gia/giaFx.c src/aig/gia/giaGig.c src/aig/gia/giaGlitch.c src/aig/gia/giaHash.c
        src/aig/gia/giaIf.c src/aig/gia/giaIff.c src/aig/gia/giaIiff.c src/aig/gia/giaIso.c src/aig/gia/giaIso2.c
        src/aig/gia/giaIso3.c src/aig/gia/giaJf.c src/aig/gia/giaKf.c src/aig/gia/giaLf.c src/aig/gia/giaMf.c
        src/aig/gia/giaMan.c src/aig/gia/giaMem.c src/aig/gia/giaMfs.c src/aig/gia/giaMini.c src/aig/gia/giaMuxes.c
        src/aig/gia/giaNf.c src/aig/gia/giaOf.c src/aig/gia/giaPack.c src/aig/gia/giaPat.c src/aig/gia/giaPf.c
        src/aig/gia/giaQbf.c src/aig/gia/giaResub.c src/aig/gia/giaRetime.c src/aig/gia/giaRex.c
        src/aig/gia/giaSatEdge.c src/aig/gia/giaSatLE.c src/aig/gia/giaSatLut.c src/aig/gia/giaSatMap.c
        src/aig/gia/giaSatoko.c src/aig/gia/giaSat3.c src/aig/gia/giaScl.c src/aig/gia/giaScript.c src/aig/gia/giaShow.c
        src/aig/gia/giaShrink.c src/aig/gia/giaShrink6.c src/aig/gia/giaShrink7.c src/aig/gia/giaSim.c
        src/aig/gia/giaSim2.c src/aig/gia/giaSort.c src/aig/gia/giaSpeedup.c src/aig/gia/giaSplit.c src/aig/gia/giaStg.c
        src/aig/gia/giaStr.c src/aig/gia/giaSupMin.c src/aig/gia/giaSupp.c src/aig/gia/giaSweep.c
        src/aig/gia/giaSweeper.c src/aig/gia/giaSwitch.c src/aig/gia/giaTim.c src/aig/gia/giaTis.c
        src/aig/gia/giaTruth.c src/aig/gia/giaTsim.c src/aig/gia/giaUnate.c src/aig/gia/giaUtil.c
        src/aig/ioa/ioaReadAig.c src/aig/ioa/ioaWriteAig.c src/aig/ioa/ioaUtil.c src/aig/ivy/ivyBalance.c
        src/aig/ivy/ivyCanon.c src/aig/ivy/ivyCheck.c src/aig/ivy/ivyCut.c src/aig/ivy/ivyCutTrav.c src/aig/ivy/ivyDfs.c
        src/aig/ivy/ivyDsd.c src/aig/ivy/ivyFanout.c src/aig/ivy/ivyFastMap.c src/aig/ivy/ivyFraig.c
        src/aig/ivy/ivyHaig.c src/aig/ivy/ivyMan.c src/aig/ivy/ivyMem.c src/aig/ivy/ivyMulti.c src/aig/ivy/ivyObj.c
        src/aig/ivy/ivyOper.c src/aig/ivy/ivyResyn.c src/aig/ivy/ivyRwr.c src/aig/ivy/ivySeq.c src/aig/ivy/ivyShow.c
        src/aig/ivy/ivyTable.c src/aig/ivy/ivyUtil.c src/aig/hop/hopBalance.c src/aig/hop/hopCheck.c
        src/aig/hop/hopDfs.c src/aig/hop/hopMan.c src/aig/hop/hopMem.c src/aig/hop/hopObj.c src/aig/hop/hopOper.c
        src/aig/hop/hopTable.c src/aig/hop/hopTruth.c src/aig/hop/hopUtil.c)
