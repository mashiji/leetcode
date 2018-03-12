//保留一个重复元素
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
void DeleteDuplicateNode1(SNode *pHead)
{
	SNode *pCur = pHead->pNext;
	SNode *pPre;
	while (pCur)
	{		
		pPre = pCur->pNext;
		if (pPre && (pPre->value == pCur->value))
		{
			pCur->pNext = pPre->pNext;
			delete pPre;  //必须删除重复节点
		}
		else
		{
			pCur = pPre;
		}	
	}
}
void DeleteDuplicateNode(SNode *pHead)
{
	SNode *pCur = pHead->pNext;
	SNode *pPre;
	while (pCur)
	{
		pPre = pCur->pNext;
		if (pPre && pPre->value == pCur->value)
		{
			pCur->pNext = pPre->pNext;
			delete pPre;
		}
		else
			pCur = pPre;
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
	int data[] = {2,3,3,5,7,8,8,9,0 };
	int size = sizeof(data) / sizeof(int);
	SNode *p1 = pHead;
	for (int i = 0; i < size; i++)
	{
		SNode *p = new SNode(data[i]);
	    p1->pNext=p;
		p1 = p;
	}
	Print(pHead);
	DeleteDuplicateNode(pHead);
	Print(pHead);
	Destroy(pHead);
	system("pause");
	return 0;
}
