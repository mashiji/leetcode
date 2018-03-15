
/*给定两个分别由字母组成的字符串 A 和字符串 B，字符串 B 的长度比字符串 A 短。请问，如何
最快地判断字符串 B 中所有字母是否都在字符串 A 里？
为了简单起见，我们规定输入的字符串只包含大写英文字母，请实现函数 bool
StringContains(string &A, string &B)
比如，如果是下面两个字符串：
String 1：ABCD
String 2：BAD*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool StringContain1(string &a,string &b)
{
	for (int i = 0; i < b.length(); i++)
	{
		int j;
		for (j = 0; j < a.length(); j++)
		{
			if (a[j] != b[i])
				continue;
			else
				break;
		}
		if (j == a.length())
			return false;
	}
	return true;
}

bool StringContain2(string &a, string &b)
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int pa = 0, pb = 0; pb < b.length();)
	{
		while ((pa < a.length()) && (a[pa] < b[pb]))
		{
			pa++;
		}
		if ((pa==a.length()) || (a[pa]>b[pb]))
			return false;
		++pb;
	}
	return true;
}

bool StringContain3(string &a, string &b)
{
	const int p[26] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
		43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };
	int f = 1;
	for (int i = 0; i < a.length(); ++i)
	{
		int x = p[a[i] - 'A'];
		if (f % x)
		{
			f *= x;
		}
	}
	for (int i = 0; i < b.length(); ++i)
	{
		int x = p[b[i] - 'A'];
		if (f % x)
		{
			return false;
		}
	}
	return true;
}
bool StringContain4(string &a, string &b)
{
	const int p[26] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
		43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };
	int f = 1;
	for (int i = 0; i < a.length(); i++)
	{
		int x = p[a[i] - 'A'];
		if (f % x)
		{
			f *= x;
		}
	}
	for (int i = 0; i < b.length(); i++)
	{
		int x = p[b[i] - 'A'];
		if (f%x)
			return false;
	}
	return true;
}
bool StringContain5(string &a, string &b)
{
	int hash = 0;
	int c;
	int d;
	for (int i = 0; i < a.length(); ++i)
	{
		c=(1 << (a[i] - 'A'));
		hash = hash |c;
		
	}
	cout << hash << endl;
	for (int i = 0; i < b.length(); ++i)
	{
		d = 1 << (b[i] - 'A');
		cout << d<<endl;
		cout << "a" << (hash &d) << endl;
		if ((hash & d) == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string a = "BCDE";
	string b = "DBB";
	cout << StringContain5(a,b) << endl;
	system("pause");
	return 0;
}
