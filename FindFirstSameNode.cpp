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
int CalcLength(SNode *p)
{
	int nLen = 0;
	while (p)
	{	
		p = p->pNext;
		nLen++;
	}
	return nLen;
}
SNode *FindFirstSameNode(SNode *pA, SNode *pB)
{
	pA = pA->pNext;
	pB = pB->pNext;
	int nA = CalcLength(pA);
	cout << nA<<endl;
	int nB = CalcLength(pB);
	cout << nB << endl;
	if (nA < nB)
	{
		swap(pA, pB);
		swap(nA, nB);
	}
	for (int i = 0; i < nA - nB; i++)
		pA = pA->pNext;
	while (pB)
	{
		if (pA == pB)
			return pA;
		pA = pA->pNext;
		pB = pB->pNext;
	}
	return NULL;
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
	SNode *pA = new SNode(0);
	SNode *pB = new SNode(0);
	SNode *node1 = new SNode(1);
	SNode *node2 = new SNode(2);
	SNode *node3 = new SNode(3);
	SNode *node4 = new SNode(4);
	SNode *node5 = new SNode(5);
	SNode *node6 = new SNode(6);
	SNode *node7 = new SNode(7); 
	SNode *node8 = new SNode(8);
	pA->pNext = node1;
	node1->pNext = node2;
	node2->pNext = node3;
	node3->pNext = node4;
	node4->pNext = node5;
	node5->pNext = node6;
	node6->pNext = NULL;
	pB->pNext = node5;
	//这样做 同一个数内存不一样   pA->value == pB->value  理解错误
	/*int data1[] = { 6,5,4,3,2,1 };
	int data2[] = { 6,5,4,3,2};
	for (int i = 0; i < sizeof(data1)/sizeof(int); i++)
	{
		SNode *p = new SNode(data1[i]);
		p->pNext = pA->pNext;
		pA->pNext = p;
	}
	for (int j = 0; j < sizeof(data2) / sizeof(int); j++)
	{
		SNode *k = new SNode(data2[j]);
		k->pNext = pB->pNext;
		pB->pNext = k;
	}*/
	Print(pA);
	Print(pB);
	SNode *pFirstSname=FindFirstSameNode(pB, pA);
	if (pFirstSname)
	{
		cout << pFirstSname->value;
		if (CalcLength(pA->pNext) > CalcLength(pB->pNext))
			Destroy(pA);
		else
			Destroy(pB);
	}
	else
	{
		cout << "no found samenode";
		Destroy(pA);
		Destroy(pB);
	}
	system("pause");
	return 0;
}
