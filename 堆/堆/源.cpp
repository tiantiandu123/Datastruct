//1. ʵ�ֶѵ����½ӿ�
#include<iostream>
#include<vector>
using namespace std;
template<class T>
class Heap
{
public:
	Heap()
	{}
	Heap(const T*array,size_t size)//�ѵĴ���
	{
		//1.�������е�Ԫ�ش�����
		_array.resize(size);
		for (size_t i = 0; i < size; i++)
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
		if (Size()==0)
			return;
		else    
		{
			size_t last = _array.size() - 1;
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
	void _AdjustDown(size_t parent)//���µ���
	{
		size_t child = parent * 2 + 1;
		size_t size = _array.size();
		while (child < size)
		{
			if ((child + 1 < size) && (_array[child] > _array[child + 1]))
			{
				child += 1;
			}
				if (_array[parent]>_array[child])
				{
					swap(_array[parent], _array[child]);
					parent = child;
					child = parent * 2 + 1;//�����ߵ�����࣬���е���
				}
				else
				{
					break;
				}
			} 
		}
	void _AdjustUp(size_t child)//���ϵ���
	{
		size_t size = _array.size();
		size_t parent = (size - 2) >> 1;
		while (child > 0)
		{
			if (_array[parent] > _array[child])
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
int main()
{
	int array[] = { 53, 17, 78, 9, 45, 65, 87, 23 };
	Heap<int>h(array, sizeof(array) / sizeof(int));
	h.Push(10);
	cout << boolalpha << h.Empty() << endl;
	cout << h.Top() << endl;
	cout << h.Size() << endl;
	h.Pop();
	cout << h.Size() << endl;
	cout << h.Empty() << endl;
	system("pause");
	return 0;
}
//2. ����������ӱȽ������û�����������ƴ�ѻ���С��
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
template<class T, class compare=Smaller<T>>
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
		if (Size()==0)
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
int main()
{
	int array[] = { 53, 17, 78, 9, 45, 65, 87, 23 };
	Heap<int,Smaller<int>>h(array, sizeof(array) / sizeof(int));
	//Heap<int, Greater<int>>h1(array, sizeof(array) / sizeof(array[0]));
	h.Push(10);
	cout << boolalpha << h.Empty() << endl;
	cout << h.Top() << endl;
	cout << h.Size() << endl;
	h.Pop();
	cout << h.Size() << endl;
	cout << h.Empty() << endl;
	system("pause");
	return 0;
}
//3. �öѷ�װ���ȼ�����
#include<iostream>
#include<vector>
#include"Heap.h"
using namespace std;
template<class T,class compare>
class priority
{
public:
	priority()
	{}
	void push(const T&data)
	{
		h.Push(data);
	}
	void pop()
	{
		h.Pop();
	}
	T Top()
	{
		return h.Top();
	}
	size_t Size()
	{
		return h.Size();
	}

	bool Empty()
	{
		return h.Empty();
	}
private:
	Heap<T, compare>h;
};
int main()
{
	/*int array[] = { 53, 17, 78, 9, 45, 65, 87, 23 };
	Heap<int,Smaller<int>>h(array, sizeof(array) / sizeof(int));*/
	//Heap<int, Greater<int>>h1(array, sizeof(array) / sizeof(array[0]));
	priority<int, Greater<int>>p;
	p.push(10);
	p.push(25);
	cout << boolalpha << p.Empty() << endl;
	cout << p.Top() << endl;
	cout << p.Size() << endl;
	p.pop();
	cout << p.Size() << endl;
	cout << p.Empty() << endl;
	system("pause");
	return 0;
}
//4. �ö��㷨ʵ�ֶ����� 
#include<iostream>
#include<vector>
using namespace std;
void AdjustDown(int* array, size_t size, size_t parent)
{
	size_t child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size&&array[child + 1] > array[child])
		{
			++child;
		}
		if (array[child]>array[parent])
		{
			std::swap(array[child], array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void HeapSort(int* array, size_t size)
{
	//����  
	for (int i = (size - 2) / 2; i >= 0; --i)
	{
		AdjustDown(array, size, i);
	}
	for (size_t i = 0; i < size; ++i)
	{
		std::swap(array[0], array[size - i - 1]);//���һ�������±�  
		AdjustDown(array, size - i - 1, 0);//����  
	}
}
int main()
{
	int array[] = { 10, 11, 12, 14, 12, 1, 2, 3, 4, 15, 19 };
	int len = sizeof(array) / sizeof(array[0]);
	HeapSort(array, len);
	for (size_t i = 0; i < len; ++i)
	{
		cout << array[i] << " ";
	}
	system("pause");
	return 0;
}