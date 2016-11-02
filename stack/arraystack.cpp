#include <stdlib.h>
#include <stdio.h> 
#include "arraystack.h"
#include <time.h>

void InitialStack(pStack pStackData,int iSize)
{
    pStackData->pSData = new LinerList;
    pStackData->pSData->iSize= iSize;
    pStackData->pSData->Data.pStart = new int[iSize];
    pStackData->nTop = pStackData->nBottom = -1;
}

void Destory(pStack pStackData)
{
    pStackData->nTop = pStackData->nBottom = -1;
    pStackData->pSData->iSize = 0;
    delete [](pStackData->pSData->Data.pStart);
    delete pStackData->pSData;
}

void ClearData(pStack pStackData)
{
    pStackData->nTop = 0;
}

bool IsEmpty(pStack pStackData)
{
    if(pStackData->nTop == pStackData->nBottom)
    {
        return true;
    }
    return false;
}

bool IsFull(pStack pStackData)
{
    if((pStackData->nTop) == (pStackData->pSData->iSize-1))
    {
        return true;
    }
    return false;
}

void Push(pStack pStackData,int nValue)
{
    if(IsFull(pStackData))
    {
        return;
    }
    pStackData->nTop++;
    pStackData->pSData->Data.pStart[pStackData->nTop] = nValue;
}

int Pop(pStack pStackData)
{
    int nRet = 0;
    if(IsEmpty(pStackData))
    {
        return -1;
    }
    nRet = pStackData->pSData->Data.pStart[pStackData->nTop];
    pStackData->nTop--;
    return nRet;
    
}

int GetData(pStack pStackData)
{
    int nRet = 0;
    if(IsEmpty(pStackData))
    {
        return -1;
    }
    nRet = pStackData->pSData->Data.pStart[pStackData->nTop];
    return nRet;
}

void DisPlay(pStack pStackData)
{
    if(IsEmpty(pStackData))
    {
        printf("Stack is empty\n");
        return;
    }
    int nSize = pStackData->nTop;
    for(int i=0;i<=nSize;i++)
    {
        printf("elm[%d]=%d\n",i,pStackData->pSData->Data.pStart[i]);
    }
    return;
}

int main(int argc,char * argv[])
{
    Stack StackObj;
    int iElm = 0;
    InitialStack(&StackObj,10);
    DisPlay(&StackObj);
    srand((unsigned) time(NULL));
    for(int i=0;i<8;i++)
    {
        iElm = rand() % 101; 
        Push(&StackObj,iElm);
    }
    printf("Initial data\n");
    DisPlay(&StackObj);
    printf("top elm = %d\n",GetData(&StackObj));
    iElm = Pop(&StackObj);
    printf("pop elm = %d\n",iElm);
    return 0;
}


