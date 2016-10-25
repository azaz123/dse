#include <stdlib.h>
#include <stdio.h> 
#include "linerlist.h"
#include <time.h>
#define JUDGE_PONITER(p) (p!=NULL)?true:false
int iElmCount = 0;

void InitialContainer(pDataContainer pContainer,int iSize)
{
    if(!JUDGE_PONITER(pContainer))
    {
        return;
    }
    pContainer->iSize = iSize;
    pContainer->Data.pStart = new int[iSize];
    iElmCount = 0;
}

void Insert(pDataContainer pContainer,int obj,int i)
{
    if(!JUDGE_PONITER(pContainer))
    {
        return;
    }
    for (int j=iElmCount;j<i;j--)
    {
        pContainer->Data.pStart[j] = pContainer->Data.pStart[j-1]; 
    }
    pContainer->Data.pStart[i] = obj;
    iElmCount++;
}

void Delete(pDataContainer pContainer,int i)
{
    if(!JUDGE_PONITER(pContainer))
    {
        return;
    }
    if(i == iElmCount-1)
    {
        iElmCount--;
        pContainer->Data.pStart[i] = 0;
        return;
    }
    for(int j=i;j<iElmCount;j++)
    {
        pContainer->Data.pStart[j] = pContainer->Data.pStart[j+1]; 
    }
    pContainer->Data.pStart[iElmCount-1] = 0; 
    iElmCount--;
    return;
}

void ClearData(pDataContainer pContainer)
{
    for(int i=0;i<8;i++)
    {
        Delete(pContainer,i);
    }
}

int Partition(pDataContainer pContainer,int iStart,int iEnd)
{
    if(!JUDGE_PONITER(pContainer))
    {
        return -1;
    }
    int iLeft = iStart;
    int iRight = iEnd;
    int iKey = pContainer->Data.pStart[iLeft];
    while(iLeft<iRight)
    {
        while((iLeft<iRight)&&(pContainer->Data.pStart[iRight] > iKey))
        {
            iRight--;
        }
        pContainer->Data.pStart[iLeft] = pContainer->Data.pStart[iRight];
        while((iLeft<iRight)&&(pContainer->Data.pStart[iLeft] < iKey))
        {
            iLeft++;
        }
        pContainer->Data.pStart[iRight] = pContainer->Data.pStart[iLeft];
    }
    pContainer->Data.pStart[iLeft] = iKey;
    return iLeft;
}

void Sort(pDataContainer pContainer,int iStart,int iEnd)
{
    if(!JUDGE_PONITER(pContainer))
    {
        return;
    }
    int iMid = 0;
    if(iStart<iEnd)
    {
        iMid = Partition(pContainer,iStart,iEnd);
        Sort(pContainer,iStart,iMid-1);
        Sort(pContainer,iMid+1,iEnd);
    }
}


int FindElmByPos(pDataContainer pContainer,int i)
{
    if(!JUDGE_PONITER(pContainer))
    {
        return -1;
    }
    return pContainer->Data.pStart[i];
}

int FindElmByValue_binarysearch(pDataContainer pContainer,int iValue)
{
    int iRet = 0;
    int iMid = 0;
    int iKey = 0;
    int iLow = 0;
    int iHigh = 0;
    if(!JUDGE_PONITER(pContainer))
    {
        return -1;
    }
    iHigh = iElmCount-1;
    while(iLow<=iHigh)
    {   
        iMid = (iHigh+iLow)/2;
        iKey = pContainer->Data.pStart[iMid];
        if(iValue < iKey)
        {
            iHigh = iMid-1;
        }
        else if(iValue > iKey)
        {
            iLow = iMid+1;
        }
        else
        {
            iRet = iMid;
            break;
        }
    }
    return iRet;
}

void Display(pDataContainer pContainer)
{
    printf("the elmentcontainer size[%d]\n",iElmCount);
    for(int i=0;i<iElmCount;i++)
    {
        printf("%d ",pContainer->Data.pStart[i]);
    }
    printf("\n");
}


int main(int argc,char * argv[])
{
    struct LinerList Container;
    int iElm = 0;
    InitialContainer(&Container,10);
    srand((unsigned) time(NULL));
    for(int i=0;i<8;i++)
    {
        iElm = rand() % 101; 
        Insert(&Container,iElm,i);
    }
    printf("Initial data\n");
    Display(&Container);
    printf("sorted data\n");
    Sort(&Container,0,iElmCount-1);
    Display(&Container);
    printf("find data elm[%d]=[%d]\n",6,FindElmByPos(&Container,6));
    printf("clear data\n");
    ClearData(&Container);
    Display(&Container);
    printf("reInitial data\n");
    for(int i=0;i<8;i++)
    {
        Insert(&Container,i,i);
    }
    Display(&Container);
    printf("find data elm[7]=[%d]\n",FindElmByValue_binarysearch(&Container,7));
    return 0;
}