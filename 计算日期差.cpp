#include<iostream>
#include<stdio.h>
using namespace std;
struct Date 
{
	int year;
	int month;
	int day;
};
bool isLeap_year(int year)
{
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0))
		return true;
	return false;
}
int GetDay(int month,Date date)
{
	int num;
	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		num = 31;
		break;
	case 2:
		if (isLeap_year(date.year))
			num = 29;
		else num  = 28;
		break;
	default:
		num  = 30;
	}
	return num;
}
int main()
{
	int difference=0;
	Date date_1;
	Date date_2;
	scanf("%d %d %d", &date_1.year, &date_1.month, &date_1.day);
	scanf("%d %d %d", &date_2.year, &date_2.month, &date_2.day);
	if (date_1.year == date_2.year)   //年相同 且不是闰年
	{
		if (date_1.month == date_2.month)
			difference = date_2.day - date_1.day;
		else
		{
			difference = GetDay(date_1.month, date_1) - date_1.day + date_2.day;
			for (int i = date_1.month+1; i < date_2.month; i++)
				difference += GetDay(i, date_1);
		}
	}
	else
	{    //// 两个年相邻
		for (int i = date_1.month; i <=12; i++)
			difference += GetDay(i, date_1);
		difference -=date_1.day; //date_1.month 到年底的天数
		for (int i = 1; i < date_2.month; i++)
			difference += GetDay(i, date_2);
		difference += date_2.day;
	
		if (date_2.year - date_1.year != 1)   // 不相邻
		{
			for (int i = date_1.year+1; i < date_2.year; i++)
			{
				if (isLeap_year(i)) difference += 366;
				else difference += 365;
			}
		}
	}
		cout << difference;
    return 0;
}

