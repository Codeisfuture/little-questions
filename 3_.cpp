#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string a;
int num[50];
int main()
{
	int i,k,m;
	ifstream in("poly.in");
	ofstream out("poly.out");
	for(i=0;i<50;i++)
		num[i]=0;
	while(getline(in,a))
	{
		for(i=0;i<a.length();i++)
		{
			k=0;
			while(a[i]!=' ')
			{
				k=k*10+a[i]-48;
				i++;
			}
			i++;
			m=0;
			while(a[i]!=' ' && i<a.length())
			{
				m=m*10+a[i]-48;
				i++;
			}
			 num[m]=num[m]+k;
		}
	}
	for(i=49;i>=0;i--)
		if(num[i]!=0)
			out<<num[i]<<" "<<i<<" ";
	in.close();
	out.close();
	return 0;
}