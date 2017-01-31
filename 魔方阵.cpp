// 魔方阵.cpp : 定义控制台应用程序的入口点。
//

#include<iostream>
using namespace std;

int main()
{
	int  **Matrix;
	int *num;
	int n;
	cin >> n;
	int N = 2 * n - 1;
	num = new int[n];
	for (int i = 0; i < n; i++)
		num[i] = i + 1; 
	Matrix = new int*[N];
	
	for (int i = 0; i < N; i++)
		Matrix[i] = new int[N];
	for(int m=0;m<n;m++)
	{
		for (int i = m; i <2*n-m-1; i++)
		{
			for (int j = m; j <2*n-m-1; j++)
			{
				Matrix[i][j] = num[m];

			}
		}
	}
	for (int i = 0; i < 2 * n - 1; i++)
	{
		for (int j = 0; j < 2 * n - 1; j++)
		{
			cout << Matrix[i][j];
		}
		cout << endl;
	}
    return 0;
}

