// 多项式相加.cpp : 定义控制台应用程序的入口点。
//

#include<iostream>
#include<fstream>
#define MAX 1000000
using namespace std;
int num[100];

int main()
{
	ifstream in("poly.in");
	ofstream out("poly.out");
	int _num=0;
	int n = 0;
	while (!in.eof())
	{
		in >> _num;
		num[n++] = _num;
	}
	int N = n;
	for (int i = 1; i < N; i = i + 2)
	{
		for (int j = i+2; j < N; j = j + 2)
		{
			if (num[i] == num[j])
			{
				num[i - 1] += num[j - 1];
				num[j - 1] = MAX;
				num[j] = MAX;
				n = n - 2;
			}
		}

	}
	for (int i = 1; i < n; i=i+2)
	{
		int k = i; int temp;
		for (int j = i; j < n; j=j+2)
			if (num[k] < num[j])
				k = j;
			temp = num[i];  num[i] = num[k];   num[k] = temp;
			temp = num[i-1];  num[i-1] = num[k-1];   num[k-1] = temp;
	}
	out << num[0];
	for (int i = 1; i < n; i++)
		out <<" " <<num[i];
    return 0;
}

