// 猴子选大王(约瑟夫环).cpp : 定义控制台应用程序的入口点。
//

#include<iostream>
#include<list>
using namespace std;
int main()
{
	int n, m, q;
	cin >>n>>m >>q ;
	list<int> *monkey = new list<int>();
	for (int i = 0; i < n; i++)
		monkey->push_back(i);
	int shout = 1;
	int last = 0;
	for (list<int>::iterator it = monkey->begin(); !monkey->empty();)
	{
		if (shout++ == m)
		{
			last = *it;
			it = monkey->erase(it);
			shout = 1;
		}
		else
			it++;
		if (it == monkey->end())
			it = monkey->begin();

	}
	if (last + q > n)
		last = last + q - n;
	else
		last = last + q;
	cout << last;
	return 0;
}

