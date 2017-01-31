#include<iostream>
#include<iomanip>
using namespace std;
int  **Matrix;

int main() {
	int n;
	cin >> n;
	Matrix = new int*[n];
	for (int i = 0; i < n; i++)
		Matrix[i] = new int[n];
	int k = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			Matrix[i][j] = k++;
		}

	int i, j;
	for (i = 0; i<n; i++) {
		for (j = 0; j<n; j++)
			cout<< setiosflags(ios::right) << setw(4)<<Matrix[n-1-j][i];
		cout << endl<<endl;
	}
	return 0;
}