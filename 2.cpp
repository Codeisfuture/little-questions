// 2.cpp : 定义控制台应用程序的入口点。
//


#include<fstream>
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
string str[2];                          //str[1] string字符串
int N;                                 //第一行的数字 第二行字符串的字符个数
int dp[5001][5001];
void DP();
void LCS(string str1, string str2);
void read();
int toInt(string s);
int main()
{
	read();   
	str[0] = str[1];
	for (int i = 0; i < N; i++)
	{
		str[1][i] = str[0][N - 1-i];
	}   //str[0] 正序字符串 str[1]倒序字符串
	//DP();
	
	LCS(str[0], str[1]);
	ofstream out("palin.out");
	//out << N - dp[N - 1][N - 1];//DP
	out << N - dp[N][N];        //LCS
    return 0;
}
void DP()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (str[0][i] == str[1][j])
			{
				if (i == 0 || j == 0) dp[i][j]++;
				else dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				if (i != 0) dp[i][j] = max(dp[i - 1][j], dp[i][j]);
				if (j != 0) dp[i][j] = max(dp[i][j - 1], dp[i][j]);
			}
		}
	}
}
void LCS(string str1, string str2)
{
	//初始化边界，过滤掉0的情况
	for (int i = 0; i <= str1.length(); i++)
		dp[i][0] = 0;

	for (int j = 0; j <= str2.length(); j++)
		dp[0][j] = 0;

	//填充矩阵
	for (int i = 1; i <= str1.length(); i++)
	{
		for (int j = 1; j <= str2.length(); j++)
		{
			//相等的情况
			if (str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				//比较“左边”和“上边“，根据其max来填充
				//if (dp[i][j - 1]>dp[i - 1][j] )
				//	dp[i][j] = dp[i][j-1];
				//else
				//	dp[i][j] = dp[i-1][j];
				
				
				if (dp[i - 1][j] >= dp[i][j - 1])
					dp[i][j] = dp[i - 1][j];
				else
					dp[i][j] = dp[i][j - 1];
			}
		}
	}
}

void read()
{
	ifstream in("palin.in");
	string temp;
	int x = 0;
	while (getline(in, temp))
	{
		str[x] = temp;
		x++;
	}
	N = toInt(str[0]); 
}
int toInt(string s)
{
	int num = 0;
	for (int i = 0; i < s.size(); i++)
	{
		num += (s[i] - '0') * pow(10, s.size() - i - 1);
	}
	return num;
}