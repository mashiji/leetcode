#include<iostream>
using namespace std;
//返回调整后基准数的位置
//方法1
int AdjustArray(int s[], int l, int r)
{
	int i = l, j = r;
	int x = s[l];
	while (i < j)
	{
		while (i < j &&s[j] >= x)
			j--;
		if (i < j)
		{
			s[i++] = s[j];
		}
		while (i < j && s[i] <= x)
			i++;
		if (i < j)
		{
			s[j--] = s[i];
		}
	}
	s[i] = x;
	return i;
}

//分治法
void quick_sort1(int s[], int l, int r)
{
	if (l < r)
	{
		int i = AdjustArray(s, l, r);
		quick_sort1(s, l, i - 1);
		quick_sort1(s, i + 1, r);
	}
}


//方法1 变体
int partitions2(int data[], int l, int h)
{
	int i = l;
	int j = h;
	int privot = data[l];
	while (i < j)
	{
		while (i < j && data[j] >= privot)
			j--;
		data[i] = data[j];
		while (i < j && data[i] <= privot)
			i++;
		data[j] = data[i];
	}
	data[i] = privot;
	return i;
}

void quick_sort2(int data[], int l, int h)
{
	if (l < h)
	{
		int i = partitions2(data, l, h);
		quick_sort2(data, l, i - 1);
		quick_sort2(data, i + 1, h);
	}
}


//方法1变体
void quick_sort3(int s[], int l, int r)
{
	if (l < r)
	{
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while (i < j &&s[j] >= x)
				j--;
			if (i < j)
			{
			s[i++] = s[j];
			}
			while (i < j && s[i] <= x)
				i++;
			if (i < j)
			{
			s[j--] = s[i];
			}
		}
		s[i] = x;
		quick_sort3(s, l, i - 1);
		quick_sort3(s, i + 1, r);
	}
}
//第二种方法
//设置头尾两个指针i, j分别指向第二个元素和最后一个元素。
//不断向右移动i, 找到第一个大于nums[0]的元素；
//不断向左移动j, 找到第一个小于nums[0]的元素；
//将nums[i]和nums[j]互换。
//重复上述过程直到i>j, 然后将此时的nums[0]和nums[j]互换。
//分别将j左边的一组数和右边的一组数分别进行上述递归。

void quicksort4(int data[], int first, int last)
{
	if (first < last)
	{

		int i = first + 1, j = last;
		while (true)
		{
			while (i <= j && data[j] >= data[first])
				j--;
			while (i <= j  && data[i] <= data[first])
				i++;
			if (i < j)
				swap(data[i], data[j]);
			else
				break;
		}
		swap(data[first], data[j]);  //必须与j交换，不能是i，可能出现i>j.
		// first到j - 1是小于，j到last部分是大于等于，再划分成等于和大于两段
		quicksort4(data, first, j - 1);
		quicksort4(data, j + 1, last);
	}
}


//第三种方法

//PARTITION(A, p, r)
//1 x ← A[r] //以最后一个元素，A[r]为主元
//2 i ← p - 1
//3 for j ← p to r - 1 //注，j从p指向的是r-1，不是r。
//4 do if A[j] ≤ x
//5 then i ← i + 1
//6 exchange A[i] <->A[j]
//7 exchange A[i + 1] <->A[r]
//8 return i + 1


int quick_sort5(int s[], int l, int r)
{
	
	int i = l - 1;
	int j;
	int x = s[r]; 
	for (j = l; j<r; j++ )
	{

		if (s[j] <= x)
		{
			i++;
			swap(s[i], s[j]);
		}
	}
	swap(s[i + 1], s[r]);
	return  i+1;
	
}
void partion5(int s[], int l, int r)
{
if (l < r)
	{
	int k = quick_sort5(s, l, r);
	partion5(s, l, k - 1);
	partion5(s, k + 1, r);
	}
}


//第四种方法

//PARTITION(A, p, r) //请读者思考版本。
//1 x ← A[r]
//2 i ← p - 1
//3 for j ← p to r //让j 从p指向了最后一个元素r
//4 do if A[j] ≤ x
//5 then i ← i + 1
//6 exchange A[i] <->A[j]
////7 exchange A[i + 1] <-> A[r] 去掉此最后的步骤
//8 return i //返回 i，不再返回 i+1.


int quick_sort6(int s[], int l, int r)
{

	int p = l - 1;
	int q;
	int x = s[r];
	for (q = l; q<=r; q++)
	{

		if (s[q] <= x)
		{
			p++;
			swap(s[q], s[p]);
		}
	}
	return p;
	
}
void partion6(int s[], int l, int r)
{
if (l < r)
	{
		int k = quick_sort6(s, l, r);
		partion6(s, l, k - 1);
		partion6(s, k + 1, r);
	}
}

int main()
{
	int s[] = {5,4,8,3,9,7};
	partion6(s, 0, 5);
	for (int i = 0; i < 6; i++)
		cout << s[i] << ' ';
	system("pause");
	return 0;

}
