//链表划分
#include<iostream>
using namespace std;
typedef struct tagSNode
{
	int value;
	tagSNode *pNext;
	tagSNode(int v) :value(v), pNext(NULL)
	{

	}
}SNode;

//重复元素保留一个
void Partition(SNode *pHead,int pivotKey)
{
	SNode *pLeftHead = new SNode(0);
	SNode *Left = pLeftHead;
	SNode *pRightHead = new SNode(0);
	SNode *Right = pRightHead;
	SNode *p = pHead->pNext;
	while (p)
	{
		if (p->value < pivotKey)
		{
			Left->pNext = p;
			//Left = Left->pNext;
			Left = p;
		}
		else
		{
			Right->pNext = p;
			//Right = Right->pNext;
			Right = p;
		}
		p = p->pNext;
	}
	Left->pNext = pRightHead->pNext;
	Right->pNext = NULL;
	pHead->pNext = pLeftHead->pNext;
	delete pLeftHead;
	delete pRightHead;
}


void Print(SNode *pHead)
{
	pHead = pHead->pNext;
	while (pHead != NULL)
	{
		std::cout << pHead->value << " ";
		pHead = pHead->pNext;
	}
	std::cout << std::endl;
}
void Destroy(SNode *p)
{
	SNode *next;//借助中间变量
	while (p)
	{
		next = p->pNext;
		delete p;
		p = next;
	}
}

int main()
{
	SNode *pHead = new SNode(0);
	for (int i = 0; i < 10; i++)
	{
		SNode *p = new SNode(rand()%100);
		p->pNext = pHead->pNext;
		pHead->pNext = p;
	}
	Print(pHead);
	Partition(pHead,50);
	Print(pHead);
	Destroy(pHead);
	system("pause");
	return 0;
}
