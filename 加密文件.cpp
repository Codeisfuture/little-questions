// 加密文件.cpp : 定义控制台应用程序的入口点。
//

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
string deletesame(string str)
{
	int i, j;
	int N = str.length();
	for (i = 0; i < N; i++)
		for (j = i + 1; j < N; j++)
			if (str[i] == str[j])
			{
				str.erase(j, 1);
				N--;
				j--;
			}
	return str;
}

int main()
{
	string str; //密钥
	cin >> str;
	ifstream in("encrypt.txt");
	ofstream out("out.txt");
	string alphabet("abcdefghijklmnopqrstuvwxyz");
	string passwordtable(deletesame(str));
	for (int i = 25; i > 0; i--)
	{
		if (passwordtable.find(alphabet[i]) == string::npos)
			passwordtable += alphabet[i];
	}
	istreambuf_iterator<char> beg(in), end;
	string text(beg, end);

	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] >= 97 && text[i] <= 122)
		{
			int pos = alphabet.find(text[i]);
			out << passwordtable[pos];
		}
		else
			out << text[i];
	} 
    return 0;
}

