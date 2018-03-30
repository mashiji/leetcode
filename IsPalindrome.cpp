#include<iostream>
using namespace std;
bool IsPalindrome(char *s, int n)
{
	if (s == NULL || n < 1)
		return false;
	char *front, *back;
	front = s;
	back = s + n - 1;
	while (front < back)
	{
		if (*front != *back)
			return false;
		front++;
		back--;
	}
	return true;
}
bool IsPalindrome2(char *s, int n)
{
	if (s == NULL || n < 1)
		return false;
	char *first, *second;
	int m = ((n >> 1) - 1 >=0) ? (n >> 1) - 1 : 0;
	first = s + m;
	second = s + n - 1 - m;
	while (first >= s)
	{
		if (*first-- != *second++)
			return false;
	}
	return true;
}
int main()
{
	char *s = "ab";
	cout << IsPalindrome2(s, strlen(s)) << endl;
	system("pause");
	return 0;
}
