
#include<iostream>

using namespace std;
int main()
{
	int p[9][9], q[9][9], n, m;
	int i, j;
	bool flag = false;
	cin >> n;
	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
			cin >> p[i][j];
	cin >> m;
	for (i = 0; i<m; i++)
		for (j = 0; j<m; j++)
			cin >> q[i][j];
	for (i = 0; i <= n - m; i++)
	{
		for (j = 0; j <= n - m; j++)
		{
			if (p[i][j] == q[0][0])   //开头相同
			{
					int a, b;
					for (a = 0; a < m; a++)
						for (b = 0; b < m; b++)
							if (p[i + a][j + b] != q[a][b]) break;
					if (a == m&&b == m) flag = true;
			}
			if (flag) break;
		}
		if (flag) break;
	}
	if (flag) cout << i + 1 << ',' << j + 1 << endl;
	else cout << -1 << endl;
	return 0;
}