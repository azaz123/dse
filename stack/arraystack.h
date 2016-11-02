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

typedef struct Stack
{
	int nTop;
	int nBottom;
	pDataContainer pSData;
}*pStack;


