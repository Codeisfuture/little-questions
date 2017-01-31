// 判断字母数和单词数.cpp : 定义控制台应用程序的入口点。
//
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool is_letter(char c)
{
	//字母的ascii码为97-122 65-90
	if (c >= 97 && c <= 122 || c >= 65 && c <= 90)
		return true;
	return false;
}
int main()
{
	ifstream in("in.txt");
	string str;
	int num_danci=0;
	int num_zifu=0;
	while (getline(in, str))
	{
		num_zifu += str.length();
		for (int i = 0; i < str.length(); i++)
		{
			if (is_letter(str[i]) && !is_letter(str[i + 1]))
				num_danci++;
		}

	}
	in.close();
	cout << num_danci <<" "<< num_zifu;
    return 0;
}

