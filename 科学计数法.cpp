// 科学计数法.cpp : 定义控制台应用程序的入口点。
//

#include<string>
#include<iostream>
#include<stdio.h>
#include<cmath>


using namespace std;
int toInt(string s)
{
	int num = 0;
	if (s[0] == '-' || s[0] == '+')  //有符号位
	{
		for (int i = 1; i < s.size(); i++)
		{
			num += (s[i] - '0') * pow(10, s.size() - i - 1);
		}
		if (s[0] == '-')  return -num;
		else return num;
	}
	else                       //无符号位
	{
		for (int i = 0; i < s.size(); i++)
		{
			num += (s[i] - '0') * pow(10, s.size() - i - 1);
		}
		return num;
	}

}
float toFloat(string s)
{
	float num=0.0;
	int pos = s.find(".");
	if (s[0] == '-')
	{
		string ss(s, 1, s.length());
		return -toFloat(ss);
	}
	else
	{// 无小数点
		if (pos == string::npos)
		{
			for (int i = 0; i < s.size(); i++)
			{
				num += (s[i] - '0') * pow(10, s.size() - i - 1);
			}
			return num;
		}

		//有小数点
		for (int i = 0; i < pos; i++)
		{
			num += (s[i] - '0') * pow(10, pos - i - 1);
		}
		for (int i = pos + 1; i < s.size(); i++)
		{
			num += (s[i] - '0') * pow(10, pos - i);
		}
		return num;
	}
}
int main()
{
	float num;
	int pos=-1;
	string str,str_1,str_2;
	cin >> str;
	pos=str.find("e");
	string s_1(str,0, pos);
	string s_2(str, pos + 1, str.length());
	num = toFloat(s_1);
	printf("%f", num*pow(10, toInt(s_2)));
    return 0;
}

