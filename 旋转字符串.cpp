//题目描述：
//给定一个字符串，要求把字符串前面的若干个字符移动到字符串的尾部，如把字符串“abcdef”前
//面的 2 个字符'a'和'b'移动到字符串的尾部，使得原字符串变成字符串“cdefab”。请写一个函数完
//成此功能，要求对长度为 n 的字符串操作的时间复杂度为 O(n)，空间复杂度为 O(1)。

#include<iostream>
using namespace std;
//实现：字符串循环左移


//第一种方法
void LeftStringOne(char *s, int n)
{
	char t = s[0];
	for (int i = 1; i < n; i++)
	{
		s[i - 1] = s[i];
	}
	s[n - 1] = t;
}
void LeftRotateString1(char *s, int n, int m)
{
	while (m--)
	{
		LeftStringOne(s, n);
	}
}
//第二种方法
void ReverseString(char *s, int from, int to)
{
	while (from <= to)
	{
		char t = s[from];
		s[from++] = s[to];
		s[to--] = t;
	}
}
void LeftRotateString2(char *s, int n, int m)
{
	m = m%n;
	ReverseString(s, 0, m - 1);
	ReverseString(s, m, n - 1);
	ReverseString(s, 0, n - 1);

}
int main()
{
	char s[] = "abcdef";  //char *s='abcdef';  这是错误的，s为const char *，不可以修改
	cout << s << endl;;
	LeftRotateString2(s,strlen(s),20);
    cout << s;
	system("pause");
	return 0;
}
