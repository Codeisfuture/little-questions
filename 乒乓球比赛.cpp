#include<iostream>
using namespace std;

int main()
{
	char ch;
	cin >> ch;
	switch (ch)
	{
	case 'a':cout << "z"; break;
	case 'b':cout << "x"; break;
	case 'c':cout << "y"; break;
	case 'z':cout << "a"; break;
	case 'x':cout << "b"; break;
	case 'y':cout << "c"; break;
	default:
		break;
	}
    return 0;
}
