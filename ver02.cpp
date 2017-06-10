#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<iomanip>
#include<windows.h>
#include<fstream>
#include<istream>

using namespace std;

void gotoxy(int x, int y) 
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

struct info
{
	char name[10];
	int yuwen_fenshu;
	int shuxue_fenshu;
	int yingyu_fenshu;
	int total_fenshu;
	int paiming;
};
info student[20];
int maxNum;
int average_yuwen, average_shuxue, average_yingyu, average_total;

void UI()
{
	cout << "\t\t**********系统菜单**********\n" << endl;
	cout << "\t\t1.查询成绩\t2.添加学生" << endl;
	cout << "\t\t3.删除学生\t4.查看信息" << endl;
	cout << "\t\t5.排列顺序\t6.清空数据" << endl;
	cout << "\t\t7.退出" << endl;
	cout << "请输入你所要的功能：";
}

void display(int n)
{
	int i;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "|    姓名   |  语文成绩  |  数学成绩  |  英语成绩  |   总分  |  排名  |" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "|" << setw(8) << student[i].name << "|" << setw(6) << student[i].yuwen_fenshu << "      |" << setw(6) << student[i].shuxue_fenshu << "      |"
			<< setw(6) << student[i].yingyu_fenshu << "      |" << setw(7) << student[i].total_fenshu << "  |" << setw(4) << student[i].paiming << "    |" << endl;
		cout << "----------------------------------------------------------------------" << endl;
	}
}

void display_A(int n)
{
	gotoxy(75, 8);  cout << "-----------------------";
	gotoxy(75, 9);  cout << "|语文平均分|" << setw(6) << average_yuwen << "    |";
	gotoxy(75, 10); cout << "-----------------------";
	gotoxy(75, 11); cout << "|数学平均分|" << setw(6) << average_shuxue << "    |";
	gotoxy(75, 12); cout << "-----------------------";
	gotoxy(75, 13); cout << "|英语平均分|" << setw(6) << average_yingyu << "    |";
	gotoxy(75, 14); cout << "-----------------------";
	gotoxy(75, 15); cout << "|  总平均分|" << setw(6) << average_total << "    |";
	gotoxy(75, 16); cout << "-----------------------";
}

void display_person(int i)
{
	cout << "----------------------------------------------------------------------" << endl;
	cout << "|    姓名   |  语文成绩  |  数学成绩  |  英语成绩  |   总分  |  排名  |" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "|" << setw(8) << student[i].name << "|" << setw(6) << student[i].yuwen_fenshu << "      |" << setw(6) << student[i].shuxue_fenshu << "      |"
		<< setw(6) << student[i].yingyu_fenshu << "      |" << setw(7) << student[i].total_fenshu << "  |" << setw(4) << student[i].paiming << "    |" << endl;
	cout << "----------------------------------------------------------------------" << endl;
	getch();
}

void pailie()
{
	int i, j, rank;
	for (i = 0; i < maxNum; i++)
	{
		student[i].total_fenshu = student[i].yuwen_fenshu + student[i].shuxue_fenshu + student[i].yingyu_fenshu;
	}
	for (i = 0; i < maxNum; i++)
	{
		rank = 0;
		for (j = 0; j < maxNum; j++)
		{
			if (student[i].total_fenshu <= student[j].total_fenshu)
			{
				rank++;
			}
		}
		student[i].paiming = rank;
	}
}

void average()
{
	int i;
	int temp_yuwen = 0, temp_shuxue = 0, temp_yingyu = 0;

	for (i = 0; i < maxNum; i++)
	{
		temp_yuwen += student[i].yuwen_fenshu;
		temp_shuxue += student[i].shuxue_fenshu;
		temp_yingyu += student[i].yingyu_fenshu;
	}
	average_yuwen = temp_yuwen / maxNum;
	average_shuxue = temp_shuxue / maxNum;
	average_yingyu = temp_yingyu / maxNum;
	average_total = (temp_yingyu + temp_yuwen + temp_shuxue) / maxNum;
}

void fun(int n)
{
	if (n == 1)
	{
		char name[10];
		int i;
		bool found = false;
		cout << "你要查找的名字：";
		cin >> name;
		for (i = 0; i < maxNum; i++)
		{
			if (strcmp(student[i].name, name) == 0)
			{
				display_person(i);
				found = true;
			}
		}
		if (!found)
		{
			cout << "未找到该生！" << endl;
		}
		getch();
	}
	else if (n == 2)
	{
		int i, num;
		cout << "想要加入几个学生：";
		cin >> num;
		for (i = maxNum; i < maxNum + num; i++)
		{
			cout << "第" << i + 1 << "个学生的名字：";
			cin >> student[i].name;
			cout << "第" << i + 1 << "个学生的语文成绩：";
			cin >> student[i].yuwen_fenshu;
			cout << "第" << i + 1 << "个学生的数学成绩：";
			cin >> student[i].shuxue_fenshu;
			cout << "第" << i + 1 << "个学生的英语成绩：";
			cin >> student[i].yingyu_fenshu;
		}
		maxNum = maxNum + num;
		pailie();
		getch();
	}
	else if (n == 3)
	{
		int i;
		int num;
		info t;
		cout << "学生信息：" << endl;
		display(maxNum);
		do
		{
			cout << "请输入要删除的学生的位置：";
			cin >> num;
		} while (num <= 0 || num > maxNum);
		for (i = num - 1; i < maxNum - 1; i++)
		{
			t = student[i];
			student[i] = student[i + 1];
			student[i + 1] = t;
			/*strcpy(student[i].name, student[i + 1].name);
			student[i].yuwen_fenshu = student[i + 1].yuwen_fenshu;
			student[i].shuxue_fenshu = student[i + 1].shuxue_fenshu;
			student[i].yinyu_fenshu= student[i + 1].yinyu_fenshu;*/
		}
		maxNum--;
		pailie();
		getch();
	}
	else if (n == 4)
	{
		gotoxy(0, 6);
		cout << "学生信息：" << endl;
		display(maxNum);
		average();
		display_A(maxNum);
		getch();
	}
	else if (n == 5)
	{
		int i, j;
		int temp_total_fenshu, temp_fenshu;
		int num;
		info t;
		cout << "1.按总分排列" << endl;
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
					if (student[j].total_fenshu < student[j + 1].total_fenshu)
					{
						t = student[j];
						student[j] = student[j + 1];
						student[j + 1] = t;
						/*temp_total_fenshu = student[j].total_fenshu;
						student[j].total_fenshu = student[j + 1].total_fenshu;
						student[j + 1].total_fenshu = temp_total_fenshu;*/
					}
				}
			}
		}
		else if (num == 2)
		{
			int num1;
			cout << "1.以语文成绩排序" << endl;
			cout << "2.以数学成绩排序" << endl;
			cout << "3.以英语成绩排序" << endl;
			do
			{
				cout << "你的选择：";
				cin >> num1;
			} while (num1 != 1 && num1 != 2 && num1 != 3);
			if (num1 == 1)
			{
				gotoxy(0, 6);
				for (i = maxNum - 1; i > 0; i--)
				{
					for (j = maxNum - 1; j > maxNum - (1 + i); j--)
					{
						if (student[j].yuwen_fenshu > student[j - 1].yuwen_fenshu)
						{
							t = student[j - 1];
							student[j - 1] = student[j];
							student[j] = t;
						}
					}
				}
			}
			else if (num1 == 2)
			{
				for (i = maxNum - 1; i > 0; i--)
				{
					for (j = maxNum - 1; j > maxNum - (1 + i); j--)
					{
						if (student[j].shuxue_fenshu > student[j - 1].shuxue_fenshu)
						{
							t = student[j - 1];
							student[j - 1] = student[j];
							student[j] = t;
						}
					}
				}
			}
			else if (num1 == 3)
			{
				for (i = maxNum - 1; i > 0; i--)
				{
					for (j = maxNum - 1; j > maxNum - (1 + i); j--)
					{
						if (student[j].yingyu_fenshu > student[j - 1].yingyu_fenshu)
						{
							t = student[j - 1];
							student[j - 1] = student[j];
							student[j] = t;
						}
					}
				}
			}
		}
		cout << "现在的学生信息：" << endl;
		display(maxNum);
		getch();
	}
	if (n == 6)
	{
		memset(student, 0, sizeof(student));
		maxNum = 0;
		if (maxNum == 0)cout << "学生信息以全部清除！" << endl;
		else cout << "初始化失败！" << endl;
		getch();
	}
}

void save()
{
	int i;
	ofstream outflie;
	outflie.open("student.txt");
	outflie << maxNum << endl;
	for (i = 0; i < maxNum; i++)
	{
		outflie << student[i].name << " " << student[i].yuwen_fenshu << " " << student[i].shuxue_fenshu << " " << student[i].yingyu_fenshu << endl;
	}
	outflie.close();
}

void startup()
{
	int i;
	ifstream inflie;
	inflie.open("student.txt");
	if (!inflie.is_open())
	{
		cout << "数据读取失败！" << endl;
		Sleep(1000);
		system("cls");
	}
	inflie >> maxNum;
	for (i = 0; i < maxNum; i++)
	{
		inflie >> student[i].name >> student[i].yuwen_fenshu >> student[i].shuxue_fenshu >> student[i].yingyu_fenshu;
	}
	inflie.close();
	pailie();
	average();
}

int main()
{
	int str;
	startup();
	do
	{
		UI();
		cin >> str;
		fun(str);
		system("cls");
	} while (str != 7);
	save();
	return 0;
}