#include <stdlib.h>
#include <stdio.h> 
#include "linkstorge.h"
#include <time.h>


void Initial(pContainer pContainerData)
{
    pContainerData->pHead = new Node;
    pContainerData->nSize = 1;

}

void Destory(pContainer pContainerData)
{
    if(pContainerData->pHead == NULL)
    {
        return;
    }
    Node *pCur = pContainerData->pHead;
    Node *pNext = pCur;
    while(pNext!=NULL)
    {
        pCur = pNext;
        pNext = pCur->next;
        if(pCur!=NULL)
        {
            pCur->next == NULL;
            delete pCur;
            pContainerData->nSize--;
        }  
    }
    pContainerData->pHead = NULL;
}

bool IsEmpty(pContainer pContainerData)
{
    int nCount = 0;
    if(pContainerData->pHead == NULL)
    {
        return false;
    }
    Node *pCur = pContainerData->pHead;
    Node *pNext = pCur;
    while(pNext!=NULL)
    {
        pCur = pNext;
        pNext = pCur->next;
        if(pCur!=NULL)
        {
            nCount++;
        }  
    }
    if(nCount > 0)
    {
        return false;
    }
    else
    {
        return true;
    }
    
}

void ClearAllData(pContainer pContainerData)
{
    Destory(pContainerData);
}

void Insert(pContainer pContainerData,int iPos,int nValue)
{
    int nCount = 0;
    if((pContainerData->pHead == NULL)&&(iPos<=0))
    {
        return;
    }
    Node * pNewNode = new Node;
    pNewNode->next = NULL;
    pNewNode->nValue = nValue;
    
    Node *pCur = pContainerData->pHead;
    Node *pNext = pCur;
    if(pContainerData->nSize <= iPos)
    {
        //add in tail
        iPos = pContainerData->nSize+1;
    }
    while(pNext!=NULL)
    {
        pCur = pNext;
        pNext = pCur->next;
        if(pCur!=NULL)
        {
            nCount++;
            if(nCount == (iPos -1) )
            {
                Node *pTmp = pCur->next;
                pCur->next = pNewNode;
                pNewNode->next = pTmp;
                pContainerData->nSize++;
                break;
            }
        }  
    }
    return;
}

void Delete(pContainer pContainerData,int iPos)
{
    int nCount = 0;
    if((pContainerData->pHead == NULL)&&(iPos<=0))
    {
        return;
    }
    Node *pCur = pContainerData->pHead;
    Node *pNext = pCur;
    if(pContainerData->nSize <= iPos)
    {
        return;
    }
    while(pNext!=NULL)
    {
        pCur = pNext;
        pNext = pCur->next;
        if(pCur!=NULL)
        {
            nCount++;
            if(nCount == (iPos-1))
            {
                Node *pOperObj = NULL;
                pOperObj = pCur->next;
                pCur->next = pOperObj->next;
                pOperObj->next = NULL;
                delete pOperObj;
                pContainerData->nSize--;
                break;
            }
        }  
    }
    return;
}

int GetData(pContainer pContainerData,int iPos)
{
    int nCount = 0;
    int nRet = 0;
    if((pContainerData->pHead == NULL)&&(iPos<=0))
    {
        return -1;
    }
    Node *pCur = pContainerData->pHead;
    Node *pNext = pCur;
    if(pContainerData->nSize <= iPos)
    {
        return -1;
    }
    while(pNext!=NULL)
    {
        pCur = pNext;
        pNext = pCur->next;
        if(pCur!=NULL)
        {
            nCount++;
            if(nCount == iPos)
            {
                nRet = pCur->nValue;
                break;
            }
        }  
    }
    return nRet;
}

void Display(pContainer pContainerData)
{
    printf("DataContainer Display begin\n");
    int nCount = 0;
    if(pContainerData->pHead == NULL)
    {
        printf("DataContainer is NULL\n");
        return;
    }
    Node *pCur = pContainerData->pHead;
    Node *pNext = pCur;
    while(pNext!=NULL)
    {
        pCur = pNext;
        pNext = pCur->next;
        if(pCur!=NULL)
        {
            nCount++;
            printf("elm[%d]=[%d]\n",nCount,pCur->nValue);
        }  
    }
    printf("DataContainer Display end\n");
}


int main(int argc,char * argv[])
{
    pContainer pDataContainer = new DataContainer;
    int iElm = 0;
    printf("DataContainer is NULL[%d]\n",IsEmpty(pDataContainer));
    Initial(pDataContainer);
    for(int i=0;i<10;i++)
    {
        iElm = rand() % 101; 
        Insert(pDataContainer,i,iElm);
    }
    Display(pDataContainer);
    printf("get elm[%d]\n",GetData(pDataContainer,6));
    Delete(pDataContainer,6);
    Display(pDataContainer);
    ClearAllData(pDataContainer);
    Display(pDataContainer);
    return 0;
}


