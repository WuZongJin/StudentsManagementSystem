#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<iomanip>

using namespace std;

struct info
{
	char name[10];
	int fenshu;
	int xuehao;
};
info student[20];
int maxNum;

void UI()
{
	cout << "\t\t**********系统菜单**********\n" << endl;
	cout << "\t\t1.新建系统\t2.添加学生" << endl;
	cout << "\t\t3.删除学生\t4.查看信息" << endl;
	cout << "\t\t5.排列顺序\t6.退出系统" << endl;
	cout << "请输入你所要的功能：";
}

void display(int n)
{
	int i;
	cout << "学号    \t姓名    \t成绩    " << endl;
	for (i = 0; i < n; i++)
	{
		cout << setw(3) << student[i].xuehao << "    \t" << setw(3) << student[i].name << "    \t" << setw(4) << student[i].fenshu << endl;
	}
}

void fun(int n)
{
	if (n == 1)
	{
		memset(student, 0, sizeof(student));
		maxNum = 0;
		if (maxNum == 0)cout << "学生信息以全部清除！" << endl;
		else cout << "初始化失败！" << endl;
		getch();
	}
	else if (n == 2)
	{
		int i, num;
		cout << "想要加入几个学生：";
		cin >> num;
		for (i = maxNum; i < maxNum + num; i++)
		{
			cout << "第" << i + 1 << "个学生的学号：";
			cin >> student[i].xuehao;
			cout << "第" << i + 1 << "个学生的名字：";
			cin >> student[i].name;
			cout << "第" << i + 1 << "个学生的成绩：";
			cin >> student[i].fenshu;
		}
		maxNum = maxNum + num;
		getch();
	}
	else if (n == 3)
	{
		int i;
		int num;
		cout << "学生信息：" << endl;
		display(maxNum);
		do
		{
			cout << "请输入要删除的学生的位置：";
			cin >> num;
		} while (num <= 0 || num > maxNum);
		for (i = num - 1; i < maxNum - 1; i++)
		{
			strcpy(student[i].name, student[i + 1].name);
			student[i].fenshu = student[i + 1].fenshu;
			student[i].xuehao = student[i + 1].xuehao;
		}
		maxNum--;
		getch();
	}
	else if (n == 4)
	{
		cout << "学生信息：" << endl;
		display(maxNum);
		getch();
	}
	else if (n == 5)
	{
		int i, j;
		int temp_xuehao, temp_fenshu;
		int num;
		cout << "1.按学号排列" << endl;
		cout << "2.按成绩排列" << endl;
		do
		{
			cout << "你的选择：";
			cin >> num;
		} while (num != 1 && num != 2);
		if (num == 1)
		{
			for (i = 0; i < maxNum; i++)
			{
				for (j = 0; j < maxNum - i - 1; j++)
				{
					if (student[j].xuehao > student[j + 1].xuehao)
					{
						temp_xuehao = student[j].xuehao;
						student[j].xuehao = student[j + 1].xuehao;
						student[j + 1].xuehao = temp_xuehao;
					}
				}
			}
		}
		else if (num == 2)
		{
			for (i = maxNum - 1; i > 0; i--)
			{
				for (j = maxNum - 1; j > maxNum - (1 + i); j--)
				{
					if (student[j].fenshu > student[j - 1].fenshu)
					{
						temp_fenshu = student[j].fenshu;
						student[j].fenshu = student[j - 1].fenshu;
						student[j - 1].fenshu = temp_fenshu;
					}
				}
			}
		}
		cout << "现在的学生信息：" << endl;
		display(maxNum);
		getch();
	}
}

int main()
{
	int str;
	do
	{
		UI();
		cin >> str;
		fun(str);
		system("cls");
	} while (str != 6);
}