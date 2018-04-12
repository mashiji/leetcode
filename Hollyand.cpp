#include<iostream>
#include<algorithm>
using namespace std;

void Holland(int *a, int length)
{
	int begin = 0;
	int current = 0;
	int end = length - 1;
	while (current <= end)
	{
		if (a[current] == 2)
		{
			swap(a[current], a[end]);
			end--;
		}
		else if (a[current] == 1)
		{
			current++;
		}
		else
		{
			if (a[current] != a[begin])
				swap(a[current], a[begin]);
			begin++;
			current++;
		}
	}
}
//初值如下：begin=0,cur=N-1，end=N-1；
void Holland2(int *a, int length)
{
	int begin = 0;
	int current = length-1;
	int end = length - 1;
	while (begin <= current)
	{
		if (a[current] == 0)
		{
			swap(a[begin], a[current]);
			begin++;
		}
		else if (a[current] == 1)
		{
			current--;
		}
		else
		{
			if (a[current] != a[end])
				swap(a[current], a[end]);
			current--;
			end--;

		}
	}
}
int main()
{
	int a[] = { 0,2,1,1,2,0,2,0,1,2,0 };
	int size = sizeof(a) / sizeof(int);
	Holland2(a, size);
	for (int i = 0; i < size; i++)
		cout << a[i] << ' ' << endl;
	system("pause");
	return 0;
}
