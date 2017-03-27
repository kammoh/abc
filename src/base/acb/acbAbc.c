/**CFile****************************************************************

  FileName    [acbAbc.c]

  SystemName  [ABC: Logic synthesis and verification system.]

  PackageName [Hierarchical word-level netlist.]

  Synopsis    [Bridge.]

  Author      [Alan Mishchenko]
  
  Affiliation [UC Berkeley]

  Date        [Ver. 1.0. Started - July 21, 2015.]

  Revision    [$Id: acbAbc.c,v 1.00 2014/11/29 00:00:00 alanmi Exp $]

***********************************************************************/

#include "acb.h"
#include "base/abc/abc.h"
#include "aig/miniaig/ndr.h"
#include "acbPar.h"

ABC_NAMESPACE_IMPL_START

////////////////////////////////////////////////////////////////////////
///                        DECLARATIONS                              ///
////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////
///                     FUNCTION DEFINITIONS                         ///
////////////////////////////////////////////////////////////////////////

/**Function*************************************************************

  Synopsis    []

  Description []
               
  SideEffects []

  SeeAlso     []

***********************************************************************/
Acb_Ntk_t * Acb_NtkFromAbc( Abc_Ntk_t * p )
{
    Acb_Man_t * pMan = Acb_ManAlloc( Abc_NtkSpec(p), 1, NULL, NULL, NULL, NULL );
    int i, k, NameId = Abc_NamStrFindOrAdd( pMan->pStrs, Abc_NtkName(p), NULL );
    Acb_Ntk_t * pNtk = Acb_NtkAlloc( pMan, NameId, Abc_NtkCiNum(p), Abc_NtkCoNum(p), Abc_NtkObjNum(p) );
    Abc_Obj_t * pObj, * pFanin;
    assert( Abc_NtkIsSopLogic(p) );
    Abc_NtkForEachCi( p, pObj, i )
        pObj->iTemp = Acb_ObjAlloc( pNtk, ABC_OPER_CI, 0, 0 );
    Abc_NtkForEachNode( p, pObj, i )
        pObj->iTemp = Acb_ObjAlloc( pNtk, ABC_OPER_LUT, Abc_ObjFaninNum(pObj), 0 );
    Abc_NtkForEachCo( p, pObj, i )
        pObj->iTemp = Acb_ObjAlloc( pNtk, ABC_OPER_CO, 1, 0 );
    Abc_NtkForEachNode( p, pObj, i )
        Abc_ObjForEachFanin( pObj, pFanin, k )
            Acb_ObjAddFanin( pNtk, pObj->iTemp, pFanin->iTemp );
    Abc_NtkForEachCo( p, pObj, i )
        Acb_ObjAddFanin( pNtk, pObj->iTemp, Abc_ObjFanin(pObj, 0)->iTemp );
    Acb_NtkCleanObjTruths( pNtk );
    Abc_NtkForEachNode( p, pObj, i )
        Acb_ObjSetTruth( pNtk, pObj->iTemp, Abc_SopToTruth((char *)pObj->pData, Abc_ObjFaninNum(pObj)) );
    Acb_NtkSetRegNum( pNtk, Abc_NtkLatchNum(p) );
    Acb_NtkAdd( pMan, pNtk );
    return pNtk;
}

/**Function*************************************************************

  Synopsis    []

  Description []
               
  SideEffects []

  SeeAlso     []

***********************************************************************/
Abc_Ntk_t * Acb_NtkToAbc( Abc_Ntk_t * pNtk, Acb_Ntk_t * p )
{
    int i, k, iObj, iFanin;
    Abc_Ntk_t * pNtkNew = Abc_NtkStartFrom( pNtk, ABC_NTK_LOGIC, ABC_FUNC_SOP );
    Mem_Flex_t * pMan = (Mem_Flex_t *)pNtkNew->pManFunc;
    Acb_NtkCleanObjCopies( p );
    Acb_NtkForEachCi( p, iObj, i )
        Acb_ObjSetCopy( p, iObj, Abc_ObjId(Abc_NtkCi(pNtkNew, i)) );
    Acb_NtkForEachNode( p, iObj )
    {
        Abc_Obj_t * pObjNew = Abc_NtkCreateNode( pNtkNew );
        Acb_ObjForEachFanin( p, iObj, iFanin, k )
            Abc_ObjAddFanin( pObjNew, Abc_NtkObj(pNtkNew, Acb_ObjCopy(p, iFanin)) );
        pObjNew->pData = Abc_SopCreateFromTruth( pMan, Acb_ObjFaninNum(p, iObj), (unsigned *)Acb_ObjTruthP(p, iObj) );
    }
    Acb_NtkForEachCoDriver( p, iFanin, i )
        Abc_ObjAddFanin( Abc_NtkCo(pNtkNew, i), Abc_NtkObj(pNtkNew, Acb_ObjCopy(p, iFanin)) );
    if ( !Abc_NtkCheck( pNtkNew ) )
    {
        printf( "Acb_NtkToAbc: The network check has failed.\n" );
        Abc_NtkDelete( pNtkNew );
        return NULL;
    }
    return pNtkNew;
}

/**Function*************************************************************

  Synopsis    []

  Description []
               
  SideEffects []

  SeeAlso     []

***********************************************************************/
Acb_Ntk_t * Acb_NtkFromNdr( char * pFileName, void * pModule, Abc_Nam_t * pNames, Vec_Int_t * vWeights, int nNameIdMax )
{
    Ndr_Data_t * p   = (Ndr_Data_t *)pModule; 
    Acb_Man_t * pMan = Acb_ManAlloc( pFileName, 1, Abc_NamRef(pNames), NULL, NULL, NULL );
    int k, NameId = Abc_NamStrFindOrAdd( pMan->pStrs, pMan->pName, NULL );
    int Mod = 0, Obj, Type, nArray, * pArray, ObjId;
    Acb_Ntk_t * pNtk = Acb_NtkAlloc( pMan, NameId, Ndr_DataCiNum(p, Mod), Ndr_DataCoNum(p, Mod), Ndr_DataObjNum(p, Mod) );
    Vec_Int_t * vMap = Vec_IntStart( nNameIdMax );
    Acb_NtkCleanObjWeights( pNtk );
    Acb_NtkCleanObjNames( pNtk );
    Ndr_ModForEachPi( p, Mod, Obj )
    {
        NameId = Ndr_ObjReadBody( p, Obj, NDR_OUTPUT );
        ObjId  = Acb_ObjAlloc( pNtk, ABC_OPER_CI, 0, 0 );
        Vec_IntWriteEntry( vMap, NameId, ObjId );
        Acb_ObjSetName( pNtk, ObjId, NameId );
        Acb_ObjSetWeight( pNtk, ObjId, vWeights ? Vec_IntEntry(vWeights, NameId) : 0 );
    }
    Ndr_ModForEachTarget( p, Mod, Obj )
    {
        NameId = Ndr_DataEntry( p, Obj );
        ObjId  = Acb_ObjAlloc( pNtk, ABC_OPER_CONST_F, 0, 0 );
        Vec_IntWriteEntry( vMap, NameId, ObjId );
        Acb_ObjSetName( pNtk, ObjId, NameId );
        Vec_IntPush( &pNtk->vTargets, ObjId );
    }
    Ndr_ModForEachNode( p, Mod, Obj )
    {
        NameId = Ndr_ObjReadBody( p, Obj, NDR_OUTPUT );
        nArray = Ndr_ObjReadArray( p, Obj, NDR_INPUT, &pArray );
        Type   = Ndr_ObjReadBody( p, Obj, NDR_OPERTYPE );
        ObjId  = Acb_ObjAlloc( pNtk, Type, nArray, 0 );
        Vec_IntWriteEntry( vMap, NameId, ObjId );
        Acb_ObjSetName( pNtk, ObjId, NameId );
    }
    Ndr_ModForEachNode( p, Mod, Obj )
    {
        NameId = Ndr_ObjReadBody( p, Obj, NDR_OUTPUT );
        ObjId  = Vec_IntEntry( vMap, NameId );
        nArray = Ndr_ObjReadArray( p, Obj, NDR_INPUT, &pArray );
        for ( k = 0; k < nArray; k++ )
            Acb_ObjAddFanin( pNtk, ObjId, Vec_IntEntry(vMap, pArray[k]) );
        Acb_ObjSetWeight( pNtk, ObjId, vWeights ? Vec_IntEntry(vWeights, NameId) : 0 );
    }
    Ndr_ModForEachPo( p, Mod, Obj )
    {
        nArray = Ndr_ObjReadArray( p, Obj, NDR_INPUT, &pArray );
        assert( nArray == 1 );
        ObjId  = Acb_ObjAlloc( pNtk, ABC_OPER_CO, 1, 0 );
        Acb_ObjAddFanin( pNtk, ObjId, Vec_IntEntry(vMap, pArray[0]) );
        Acb_ObjSetName( pNtk, ObjId, pArray[0] );
    }
    Vec_IntFree( vMap );
    Acb_NtkSetRegNum( pNtk, 0 );
    Acb_NtkAdd( pMan, pNtk );
    return pNtk;
}

/**Function*************************************************************

  Synopsis    [Setup parameter structure.]

  Description []

  SideEffects []

  SeeAlso     []

***********************************************************************/
void Acb_ParSetDefault( Acb_Par_t * pPars )
{
    memset( pPars, 0, sizeof(Acb_Par_t) );
    pPars->nLutSize     =    4;    // LUT size
    pPars->nTfoLevMax   =    3;    // the maximum fanout levels
    pPars->nTfiLevMax   =    3;    // the maximum fanin levels
    pPars->nFanoutMax   =   10;    // the maximum number of fanouts
    pPars->nDivMax      =   16;    // the maximum divisor count
    pPars->nTabooMax    =    4;    // the minimum MFFC size
    pPars->nGrowthLevel =    0;    // the maximum allowed growth in level
    pPars->nBTLimit     =    0;    // the maximum number of conflicts in one SAT run
    pPars->nNodesMax    =    0;    // the maximum number of nodes to try
    pPars->iNodeOne     =    0;    // one particular node to try
    pPars->fArea        =    0;    // performs optimization for area
    pPars->fMoreEffort  =    0;    // enables using more effort
    pPars->fVerbose     =    0;    // enable basic stats
    pPars->fVeryVerbose =    0;    // enable detailed stats
}

/**Function*************************************************************

  Synopsis    []

  Description []
               
  SideEffects []

  SeeAlso     []

***********************************************************************/
Abc_Ntk_t * Abc_NtkOptMfse( Abc_Ntk_t * pNtk, Acb_Par_t * pPars )
{
    extern void Acb_NtkOpt( Acb_Ntk_t * p, Acb_Par_t * pPars );
    Abc_Ntk_t * pNtkNew;
    Acb_Ntk_t * p = Acb_NtkFromAbc( pNtk );
    Acb_NtkOpt( p, pPars );
    pNtkNew = Acb_NtkToAbc( pNtk, p );
    Acb_ManFree( p->pDesign );
    return pNtkNew;
}

////////////////////////////////////////////////////////////////////////
///                       END OF FILE                                ///
////////////////////////////////////////////////////////////////////////


ABC_NAMESPACE_IMPL_END

