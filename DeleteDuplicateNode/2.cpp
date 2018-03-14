//全部去重

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
//参考课件方法写的
void DeleteDuplicateNode(SNode *pHead)
{
	SNode *pPre = pHead;
	SNode *pCur = pHead->pNext;
	SNode *pNext;
	bool bDup;
	while (pCur)
	{
		pNext = pCur->pNext;
		bDup = false;
		while (pNext && (pCur->value == pNext->value))
		{
			pPre->pNext = pNext;
			delete pCur;
			pCur = pNext;
			pNext = pNext->pNext;
			bDup = true;
		}
		if (bDup)
		{
			pPre->pNext = pNext;
			delete pCur;
		}
		else
			pPre = pCur;
		pCur = pNext;
	}
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
	SNode *p1 = pHead;
	int data[] = { 2, 3, 3, 5, 7, 8, 8, 8, 9, 9 };
	int size = sizeof(data) / sizeof(int);
	for (int i = 0; i < size; i++)
	{
		SNode *p = new SNode(data[i]);
		pHead->pNext = p;;
		pHead = p;
	}
	Print(p1);
	DeleteDuplicateNode(p1);
	Print(p1);
	Destroy(p1);
	system("pause");
	return 0;
}
