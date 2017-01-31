#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string Reverse(string s);
int main()
{
	ifstream in ("text1.dat");
	ofstream out("text2.dat");
	string temp;
	while (getline(in,temp))
	{
		string a=Reverse(temp);
		out<<a<<endl;
	}
	in.close();
	out.close();
    return 0;
}
string Reverse(string s)
{
	string temp_s;
	for (int i = s.size()-1; i >= 0; i--)
		temp_s+= s[i];
	return temp_s;
}
