#include <stdlib.h>
#include <stdio.h> 
#include "binarytree.h"
#include <time.h>

TreeNode * Initial(int nRootValue)
{
    TreeNode * pRet = NULL;
    pRet = new TreeNode;
    pRet->nValue = nRootValue;
    pRet->LChild = NULL;
    pRet->RChild = NULL;
    return pRet;
    
}

void Destory(TreeNode *pBtn)
{
    if(pBtn!=NULL)
    {
        if(pBtn->LChild!=NULL)
        {
            Destory(pBtn->LChild);
        }
        if(pBtn->RChild!=NULL)
        {
            Destory(pBtn->RChild);
        }
        delete pBtn;
        pBtn = NULL;
    }
}

bool IsEmpty(TreeNode *pBtn)
{
    if(pBtn == NULL)
    {
        printf("IsEmptypBtn NULL\n");
        return true;
    }
    return false;
}

int GetDeep(TreeNode *pBtn)
{
    int i = 0;
    int j = 0;
    if(pBtn==NULL)
    {
        printf("GetDeep pBtn NULL\n");
        return 0;
    }
    
    if(pBtn->LChild!=NULL)
    {
        GetDeep(pBtn->LChild);
    }
    else
    {
        i = 0;
    }

    if(pBtn->RChild!=NULL)
    {
        GetDeep(pBtn->RChild);
    }
    else
    {
        j = 0;
    }
    return (i<j)?(i+1):(j+1);
}

void Insert(TreeNode *pBtn,int nValue)
{
    if(pBtn == NULL)
    {
        printf("Insert value pBtn NULL\n");
        return;
    }
    if(pBtn->nValue < nValue)
        {
            if(pBtn->LChild == NULL)
            {
                pBtn->LChild = new TreeNode;
                pBtn->LChild->nValue = nValue;
                pBtn->LChild->LChild = pBtn->LChild->RChild = NULL;
                return;
            }
            else
            {
                Insert(pBtn->LChild,nValue);
            }
        }
        else
        {
            if(pBtn->RChild == NULL)
            {
                pBtn->RChild = new TreeNode;
                pBtn->RChild->nValue = nValue;
                pBtn->RChild->LChild = pBtn->RChild->RChild = NULL;
                return;
            }
            else
            {
                Insert(pBtn->RChild,nValue);
            }
        }
}


void preOrder_traverse(TreeNode *pBtn)
{
    if(pBtn == NULL)
    {
        return;
    }
    printf("preOrder_traverse value %d\n",pBtn->nValue);
    preOrder_traverse(pBtn->LChild);
    preOrder_traverse(pBtn->RChild);
}

void InOrder_traverse(TreeNode *pBtn)
{
    if(pBtn == NULL)
    {
        return;
    }
    
    InOrder_traverse(pBtn->LChild);
    printf("InOrder_traverse value %d\n",pBtn->nValue);
    InOrder_traverse(pBtn->RChild);
}

void PostOrder_traverse(TreeNode *pBtn)
{
    if(pBtn == NULL)
    {
        return;
    }
    
    PostOrder_traverse(pBtn->LChild);
    PostOrder_traverse(pBtn->RChild);
    printf("PostOrder_traverse value %d\n",pBtn->nValue);
}

int main(int argc,char * argv[])
{
    TreeNode *pRoot = NULL;
    pRoot = Initial(10);
    printf("pRoot %p\n",pRoot);
    Insert(pRoot,8);
    Insert(pRoot,9);
    Insert(pRoot,11);
    Insert(pRoot,12);
    preOrder_traverse(pRoot);
    InOrder_traverse(pRoot);
    PostOrder_traverse(pRoot);
    getchar();
    return 0;
}


