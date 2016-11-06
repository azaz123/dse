//collenction data
struct collection_data
{
	int *pStart;
};

typedef  struct LinerList
{
    struct collection_data Data;
    int iSize;
}*pDataContainer;

typedef struct Queue
{
    int nHead;
	int nTail;
	int nTotalCount;
	pDataContainer pData;
}*pQueue;