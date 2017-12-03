target_sources(libabc PRIVATE src/map/mapper/mapper.c src/map/mapper/mapperCanon.c
        src/map/mapper/mapperCore.c src/map/mapper/mapperCreate.c src/map/mapper/mapperCut.c
        src/map/mapper/mapperCutUtils.c src/map/mapper/mapperLib.c src/map/mapper/mapperMatch.c
        src/map/mapper/mapperRefs.c src/map/mapper/mapperSuper.c src/map/mapper/mapperSwitch.c
        src/map/mapper/mapperTable.c src/map/mapper/mapperTime.c src/map/mapper/mapperTree.c
        src/map/mapper/mapperTruth.c src/map/mapper/mapperUtils.c src/map/mapper/mapperVec.c src/map/mio/mio.c
        src/map/mio/mioApi.c src/map/mio/mioFunc.c src/map/mio/mioParse.c src/map/mio/mioRead.c src/map/mio/mioSop.c
        src/map/mio/mioUtils.c src/map/super/super.c src/map/super/superAnd.c src/map/super/superGate.c
        src/map/if/ifCom.c src/map/if/ifCache.c src/map/if/ifCore.c src/map/if/ifCut.c src/map/if/ifData2.c
        src/map/if/ifDec07.c src/map/if/ifDec08.c src/map/if/ifDec10.c src/map/if/ifDec16.c src/map/if/ifDec75.c
        src/map/if/ifDelay.c src/map/if/ifDsd.c src/map/if/ifLibBox.c src/map/if/ifLibLut.c src/map/if/ifMan.c
        src/map/if/ifMap.c src/map/if/ifMatch2.c src/map/if/ifReduce.c src/map/if/ifSat.c src/map/if/ifSelect.c
        src/map/if/ifSeq.c src/map/if/ifTest.c src/map/if/ifTime.c src/map/if/ifTruth.c src/map/if/ifTune.c
        src/map/if/ifUtil.c src/map/amap/amapCore.c src/map/amap/amapGraph.c src/map/amap/amapLib.c
        src/map/amap/amapLiberty.c src/map/amap/amapMan.c src/map/amap/amapMatch.c src/map/amap/amapMerge.c
        src/map/amap/amapOutput.c src/map/amap/amapParse.c src/map/amap/amapPerm.c src/map/amap/amapRead.c
        src/map/amap/amapRule.c src/map/amap/amapUniq.c src/map/cov/covBuild.c src/map/cov/covCore.c
        src/map/cov/covMan.c src/map/cov/covMinEsop.c src/map/cov/covMinMan.c src/map/cov/covMinSop.c
        src/map/cov/covMinUtil.c src/map/scl/scl.c src/map/scl/sclBuffer.c src/map/scl/sclBufSize.c
        src/map/scl/sclDnsize.c src/map/scl/sclLiberty.c src/map/scl/sclLibScl.c src/map/scl/sclLibUtil.c
        src/map/scl/sclLoad.c src/map/scl/sclSize.c src/map/scl/sclUpsize.c src/map/scl/sclUtil.c src/map/mpm/mpmAbc.c
        src/map/mpm/mpmCore.c src/map/mpm/mpmDsd.c src/map/mpm/mpmGates.c src/map/mpm/mpmLib.c src/map/mpm/mpmMan.c
        src/map/mpm/mpmMap.c src/map/mpm/mpmMig.c src/map/mpm/mpmPre.c src/map/mpm/mpmTruth.c src/map/mpm/mpmUtil.c)