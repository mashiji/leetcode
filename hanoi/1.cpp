//算法：当只有一个盘子的时候，只需要从将A塔上的一个盘子移到C塔上。
//当A塔上有两个盘子是，先将A塔上的1号盘子（编号从上到下）移动到B塔上，再将A塔上的2号盘子移动的C塔上，最后将B塔上的小盘子移动到C塔上。
//当A塔上有3个盘子时，先将A塔上编号1至2的盘子（共2个）移动到B塔上（需借助C塔），然后将A塔上的3号最大的盘子移动到C塔，最后将B塔上的两个盘子借助A塔移动到C塔上。
//当A塔上有n个盘子是，先将A塔上编号1至n - 1的盘子（共n - 1个）移动到B塔上（借助C塔），然后将A塔上最大的n号盘子移动到C塔上，最后将B塔上的n - 1个盘子借助A塔移动到C塔上。
//综上所述，除了只有一个盘子时不需要借助其他塔外，其余情况均一样（只是事件的复杂程度不一样）。


#include<iostream>
using namespace std;
int i = 1;
void move(int n, char from, char to)
{
	cout << "第" << i++ << "步" << " " << n << "号盘子" << from << "->" << to << endl;
}
void hanoi(int n, char from, char temp, char to)
{
	if (n == 1)
		move(1, from, to);
	else
	{
		hanoi(n - 1, from, to, temp);
		move(n, from, to);
		hanoi(n - 1, temp, from, to);
	}
}


int main()
{
	cout << "请输入盘子的个数:\n";
	int n;
	cin >> n;
	char x = 'A', y = 'B', z = 'C';
	cout << "盘子移动情况如下:\n";
	hanoi(n, x, y, z);
	system("pause");
	return 0;

}
