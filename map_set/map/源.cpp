#include<iostream>
#include<string>
#include<map>
using namespace std;
void test_map()
{
	string strs[] = { "sort", "sort", "second", "first", "first" };
	map<string, size_t>CountMap;
	for (size_t i = 0; i < sizeof(strs) / sizeof(string); i++)
	{
		//方式一：
		/*map<string, size_t>::iterator it = CountMap.find(strs[i]);
		if (it != CountMap.end())
		{
		it->second++;
		}
		else
		{
		CountMap.insert(make_pair(strs[i], 1));
		}*/
		//方式二：
		pair<map<string, size_t>::iterator, bool>ret = CountMap.insert(make_pair(strs[i], 1));
		if (ret.second == false)//表示里面已经有了元素，则不会插入
		{
			ret.first->second++;
		}
		//方式三：operator[]
		/*CountMap[strs[i]]++;*/
	}
	map<string, size_t>::iterator it1 = CountMap.begin();
	while (it1 != CountMap.end())
	{
		cout << it1->first << ":" << it1->second << endl;
		++it1;
	}
	cout << endl;
}
int main()
{
	test_map();
	system("pause");
}
