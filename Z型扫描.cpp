
#include <iostream>

using namespace std;

int A[501][501];
enum  Choice
{
	rightTowards,//���ƶ�
	rightUp,//�������ƶ�
	down,//�����ƶ�
	leftDown//�������ƶ�
};

void zigzagScan(int n)
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> A[i][j];
	int row = 0, col = 0;
	Choice choice = rightTowards;
	//row = n-1&&col = n-1��������whileѭ����������������ֹ����Խ��������
	while (row != n - 1 || col != n - 1)
	{
		cout << A[row][col] << ' ';
		switch (choice)
		{
		case rightTowards:
			col++;
			if (row == 0)
				choice = leftDown;
			else
				choice = rightUp;
			break;
		case rightUp:
			row--;
			col++;
			if (row == 0 && col != n - 1)
				choice = rightTowards;
			else if (col == n - 1)
				choice = down;
			else
				choice = rightUp;
			break;
		case down:
			row++;
			if (col == 0)
				choice = rightUp;
			else
				choice = leftDown;
			break;
		case leftDown:
			row++;
			col--;
			if (col == 0 && row != n - 1)
				choice = down;
			else if (row == n - 1)
				choice = rightTowards;
			else
				choice = leftDown;
			break;
		}
	}
	cout << A[n - 1][n - 1];
}

int main()
{
	int n;
	while (cin >> n)
	{
		zigzagScan(n);
	}
	return 0;
}

