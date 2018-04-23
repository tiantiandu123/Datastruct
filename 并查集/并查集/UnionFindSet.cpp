#include<iostream>
#include<vector>
using namespace std;
class UFS
{
public:
	UFS(int size)
		:_set(size+1, -1)
	{}
	void Union(int x1, int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);
		if (root1 != root2)
		{
			_set[root1] += _set[root2];
			_set[root2] = root1;
		}
	}
	size_t FindRoot(int x)//求双亲
	{
		while (_set[x] >= 0)//当其大于0时，说明其不是双亲
		{
			x = _set[x];
		}
		return x;
	}
	size_t sizecount()
	{
		size_t count = 0;
		for (size_t i = 0; i < _set.size(); i++)
		{
			if (_set[i] <0)
			{
				count++;
			}
		}
		return count-1;
	}
private:
	std::vector<int>_set;
};
int friends(int n, int m, int arr[][2])
{
	UFS u(n);
	for (int i = 0; i < m; i++)
	{
		u.Union(arr[i][0], arr[i][1]);
	}
	int count = u.sizecount();
	return count;
}
int main()
{
	int arr[][2]= { { 1, 2 }, { 2, 3, }, { 4, 5 } };
	cout << friends(5, 3, arr);
	system("pause");
	return 0;
}