#include<iostream>
typedef struct tagSNode
{
	int value;
	tagSNode *pNext;
	tagSNode(int v) :value(v), pNext(NULL)
	{

	}
}SNode;

//第一次很难理解
void Reverse1(SNode *pHead,int from, int to)
{
	SNode *pCur = pHead->pNext;
	int i;
	for (i = 0; i < from - 1; i++)
	{
		pHead = pCur;
		pCur = pCur->pNext;
		
	}
	SNode *pPre = pCur;
	pCur = pCur->pNext;
	SNode *pNext;
	for (;i < to-1; i++)
	{
		pNext = pCur->pNext;
		pCur->pNext = pHead->pNext;// 很重要
		pHead->pNext = pCur;
		pPre->pNext = pNext;
		pCur = pNext;
    }
}
//对链表从头到尾进行全部翻转
void Reverse2(SNode *pHead)
{
	SNode *pCur = pHead->pNext;
	SNode *pPre = pCur;
	pCur = pCur->pNext;
	SNode *Next;
	while (pCur)
	{
		Next = pCur->pNext;
		pCur->pNext = pHead->pNext;
		pHead->pNext = pCur;
		pPre->pNext = Next;
		pCur = Next;
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
	int i;
	//SNode *p1 = pHead1;
	for (i = 0; i < 10; i++)
	{
		SNode *p = new SNode(rand() % 10);  //尾插法
		//p1->pNext = p;
		//p1 = p;
		p->pNext =pHead->pNext;   //头插法
		pHead->pNext = p;
	}
	Print(pHead);
	Reverse1(pHead,3,10);
	Print(pHead);
	Destroy(pHead);
	system("pause");
	return 0;
}

