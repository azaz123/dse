struct Node
{
	int nValue;
	Node *next;
};

typedef struct DataContainer
{
	Node* pHead;
	int nSize;
}*pContainer;
