#include<iostream>
#include<vector>
using namespace std;
template<class T>
struct Greater
{
	bool operator()(const T&a, const T&b)
	{
		return a > b;
	}
};
template<class T>
struct Smaller
{
	bool operator()(const T&a, const T&b)
	{
		return a < b;
	}
};
template<class T, class compare = Smaller<T>>
class Heap
{
public:
	Heap()
	{}
	Heap(T*array, int size)//�ѵĴ���
	{
		//1.�������е�Ԫ�ش�����
		_array.resize(size);
		for (int i = 0; i < size; i++)
		{
			_array[i] = array[i];
		}
		//2.���µ���
		int root = (size - 2) >> 1;
		for (; root >= 0; root--)
		{
			_AdjustDown(root);
		}
	}
	void Push(const T& data)
	{
		_array.push_back(data);
		if (_array.size() > 1)
		{
			_AdjustUp(_array.size() - 1);
		}
	}
	void Pop()
	{
		if (Size() == 0)
			return;
		else
		{
			int last = _array.size() - 1;
			swap(_array[0], _array[last]);
			_array.pop_back();
			//2.���µ���
			_AdjustDown(0);
		}
	}
	T Top()const
	{
		return _array[0];
	}
	bool Empty()const
	{
		return _array.empty();
	}
	size_t Size()const
	{
		return  _array.size();
	}
private:
	void _AdjustDown(int parent)//���µ���
	{
		int child = parent * 2 + 1;
		int size = _array.size();
		while (child < size)
		{
			if ((child + 1 < size) && (compare()(_array[child], _array[child + 1])))
			{
				child += 1;
			}
			if (compare()(_array[parent], _array[child]))
			{
				swap(_array[parent], _array[child]);
				parent = child;
				child = parent * 2 + 1;//�����ߵ�����࣬���е���
			}
			else
				return;
		}
	}
	void _AdjustUp(int child)//���ϵ���
	{
		int size = _array.size();
		int parent = (size - 2) >> 1;
		while (child > 0)
		{
			if (compare()(_array[parent], _array[child]))
			{
				swap(_array[parent], _array[child]);
				child = parent;
				parent = (child - 1) >> 1;
			}
			else
			{
				break;
			}
		}
	}
private:
	vector<T>_array;
};