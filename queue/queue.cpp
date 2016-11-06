#include <stdlib.h>
#include <stdio.h> 
#include "queue.h"
#include <time.h>

void InitialContainer(pQueue pQContainer,int nSize)
{
    pQContainer->nHead = pQContainer->nTail =0;
    if(pQContainer == NULL)
    {
        return;
    }
    pQContainer->nTotalCount = nSize;
    pQContainer->pData = new LinerList;
    pQContainer->pData->iSize = nSize;
    pQContainer->pData->Data.pStart = new int[nSize];
    for(int i=0;i<nSize;i++)
    {
        pQContainer->pData->Data.pStart[i] = -1;
    }
}

void DestoryContainer(pQueue pQContainer)
{
    if(pQContainer == NULL)
    {
        return;
    }
    if(pQContainer->pData == NULL)
    {
        return;
    }
    if(pQContainer->pData->Data.pStart == NULL)
    {
        return;
    }
    delete [](pQContainer->pData->Data.pStart);
    delete pQContainer->pData;
}

bool IsEmpty(pQueue pQContainer)
{
    if(pQContainer == NULL)
    {
        return true;
    }
    if(pQContainer->nHead == pQContainer->nTail)
    {
        return true;
    }
    return false;
}

bool IsFull(pQueue pQContainer)
{
    if(pQContainer == NULL)
    {
        return false;
    }
    if(((pQContainer->nHead+1)% pQContainer->nTotalCount) == pQContainer->nTail)
    {
        return true;
    }
    return false;
}

void EnQueue(pQueue pQContainer,int nValue)
{
    if(pQContainer == NULL)
    {
        return;
    }
    if(IsFull(pQContainer))
    {
        printf("Queue is Full\n");
        return;
    }
    int iPos = pQContainer->nHead;
    pQContainer->pData->Data.pStart[iPos] = nValue;
    pQContainer->nHead++;
}

int DeQueue(pQueue pQContainer)
{
    int nRet = -1;
    if(pQContainer == NULL)
    {
        return nRet;
    }
    if(IsEmpty(pQContainer))
    {
        printf("Queue is Empty\n");
        return nRet;
    }
    int iPos = pQContainer->nTail;
    nRet = pQContainer->pData->Data.pStart[iPos];
    pQContainer->pData->Data.pStart[iPos] = -1;
    pQContainer->nTail++;
    return nRet;
}

void Display(pQueue pQContainer)
{
    if(pQContainer == NULL)
    {
        return;
    }
    for(int i=0;i<pQContainer->nTotalCount;i++)
    {
        int nValue = pQContainer->pData->Data.pStart[i];
        printf("Elm[%d]=%d\n",i,nValue);
    }
}

int main(int argc,char * argv[])
{
    Queue QueueContainer;
    InitialContainer(&QueueContainer,10);
    printf("Initial\n");
    Display(&QueueContainer);
    DeQueue(&QueueContainer);
    srand((unsigned) time(NULL));
    for(int i=0;i<10;i++)
    {
        int iElm = rand() % 101; 
        EnQueue(&QueueContainer,iElm);
    }
    EnQueue(&QueueContainer,1000);
    printf("EnQueue\n");
    Display(&QueueContainer);
    printf("DeQueue Elm[%d]\n",DeQueue(&QueueContainer));
    return 0;
}

