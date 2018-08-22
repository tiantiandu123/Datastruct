#include<iostream>
#include<vector>
using namespace std;
template<class T>
class Heap
{
public:
	Heap()
	{}
	Heap(const T*array, size_t size)
	{
		_array.reserve(size);//只扩容，没有初始化
		//_array.resize(size);//扩容并初始化
		for (int i = 0; i < size; i++)
		{
			//_array[i] = array[i];//如果是这样必须初始化
			_array.push_back(array[i]);
		}
		//找到完全二叉树中倒数第一个非叶子节点
		int root = (size - 2) >> 1;
		for (; root>0; root--)
		{
			AdjustDown(root); 
		}
	}
	void AdjustDown(size_t parent)
	{
		int child = 2 * parent + 1;
		int size = _array.size();
		while (child < size)
		{
			if ((child + 1 < size) && (_array[child] > _array[child + 1]))
			{
				child = child + 1;
			}
			if (_array[child] < _array[parent])
			{
				swap(_array[child], _array[parent]);
				parent = child;
				child = 2 * parent + 1;
			}
			else
			{
				break;
			}
		}
	}
	void push(const T&data)
	{
		int child = _array.size() - 1;
		_array.push_back(data);
		if (_array.size() > 1)
		{
			AdjustUp(child);
		}
	}
	void AdjustUp(size_t child)
	{
		int size = _array.size();
		int parent = (size - 2) >> 1;
		while (child > 0)//若只有一个元素则不用再调整
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
	void pop()//自顶向下调整
	{
		if (_array.size() == 0)
		{
			return;
		}
		int last = _array.size() - 1;
		swap(_array[last], _array[0]);
		_array.pop_back();
		if (_array.size() > 1)
		{
			AdjustDown(0);
		}
	}
	size_t size()
	{
		return _array.size();
	}
	T& Top()
	{
		return _array[0];
	}
	bool Empty()
	{
		return _array.empty();
	}
private:
	vector<T>_array;
}; 
////
////
////int main()
////{
////	int array[] = { 53, 17, 78, 9, 45, 65, 87, 23 };
////	Heap<int>hp1(array, 8);
////	cout << hp1.size() << endl;
////	hp1.push(55);
////	cout << hp1.size() << endl;
////	hp1.pop();
////	cout << hp1.size() << endl;
////
////	int array1[] = { 10, 11, 12, 14, 12, 1, 2, 3, 4, 15, 19 };
////	Heap<int>hp2(array1, 11);
////	int len = sizeof(array1) / sizeof(array1[0]);
////	system("pause");
////	return 0;
////}
//////堆排序：
////#include<iostream>
////#include<vector>
////using namespace std;
////void AdjustDown(int *array, size_t size, size_t parent)
////{
////	size_t child = 2 * parent + 1;
////	while (child < size)
////	{
////		if (child + 1 < size&&array[child] <array[child + 1])
////		{
////			child = child + 1;
////		}
////		if (array[parent]<array[child])
////		{
////			swap(array[child], array[parent]);
////			parent = child;
////			child = 2 * parent + 1;
////		}
////		else
////		{
////			break;
////		}
////	}
////}
////void Heapsort(int*array, size_t size)
////{
////	int root = (size - 2) >> 1;
////	//建堆
////	for (; root >= 0; --root)
////	{
////		AdjustDown(array, size, root);
////	}
////	int end = size - 1;
////	for (; end > 0; --end)
////	{
////		swap(array[0], array[end]);
////		AdjustDown(array, end, 0);
////	}
////}
//////int main()
//////{
//////	int array[] = { 10, 11, 12, 14, 12, 1, 2, 3, 4, 15, 19 };
//////	Heapsort(array, sizeof(array) / sizeof(array[0]));
//////	for (int i = 0; i <sizeof(array)/sizeof(array[0]); i++)
//////	{
//////		cout << array[i] << " ";
//////	}
//////	system("pause");
//////	return 0;
//////}
////
//////TopK问题：
//////100W个数中找出最大的前K个数。//建小堆
////#include<iostream>
////#include<vector>
////#include<assert.h>
////using namespace std;
////void AdjustDown(int*heap, size_t size, size_t root)
////{
////	assert(heap);
////	size_t parent = root;
////	size_t child = 2 * parent + 1;
////	while (child < size)
////	{
////		if ((child + 1 < size)&&heap[child] > heap[child + 1])
////		{
////			child = child + 1;
////		}
////		if (heap[child] < heap[parent])
////		{
////			swap(heap[child], heap[parent]);
////			parent = child;
////			child = 2 * parent + 1;
////		}
////		else
////		{
////			break;
////		}
////	}
////}
////void GetTopK(int*arr, size_t n, int K)
////{
////	int *heap = new int[K];
////	for (int i = 0; i < K; i++)
////	{
////		heap[i] = arr[i];
////	}
////	//建堆
////	for (int i = (K - 2) >> 1; i >= 0; --i)
////	{
////		AdjustDown(heap, K, i);
////	}
////	//排序
////	for (int i = K; i < n; i++)//用K+1个元素之后的元素和堆顶比较，如果大于堆顶，交换然后调整
////	{
////		if (arr[i]>heap[0])
////		{
////			swap(arr[i], heap[0]);
////			AdjustDown(heap, K, 0);
////		}
////	}
////	for (int i = 0; i < K; i++)
////	{
////		cout << heap[i] << " ";
////	}
////}
////int main()
////{
////	const size_t M = 10000;
////	const size_t K = 100;
////	int arr[M] = { 0 };
////	for (int i = 0; i < M; i++)
////	{
////		arr[i] = rand() % M;//这些数都小于M
////	}
////	//待会打印的前K个元素，就应该是下面这5个。
////	arr[0] = 555555;
////	arr[99] = 41789;
////	arr[987] = 14589;
////	arr[100] = 9999;
////	arr[235] = 5678;
////	GetTopK(arr, M, K);
////	//for (size_t i = 0; i < K; i++)
////	//{
////	//	cout << arr[i] << " ";
////	//}
////	system("pause");
////	return 0;
////}
//
//////优先级队列：
////#include<iostream>
////#include<queue>
////#include<algorithm>
////using namespace std;
////int main()
////{
////	int a[] = { 0, 1, 2, 3, 4, 8, 9, 3, 5 };
////	priority_queue<int>q(a, a + 9);//
////	cout << "size=" << q.size() << endl;
////
////	for (int i = 0; i < q.size(); i++)
////	{
////		cout << q.top() << " ";//求出堆顶元素
////	}
////	cout << endl;
////
////	while (!q.empty())
////	{
////		cout << q.top() << " ";
////		q.pop();
////	}
////	cout << endl;
////	system("pause");
////	return 0;
////}
//#include<iostream>
//#include<vector>
//using namespace std;
//template<class T>
//struct Greater
//{
//	bool operator()(const T&l, const T&r)
//	{
//		return l > r;
//	}
//};
//template<class T>
//struct Smaller
//{
//	bool operator()(const T&l, const T&r)
//	{
//		return l < r;
//	}
//};
//template<class T, class Compare>
//class Heap
//{
//public:
//	Heap()
//	{}
//	Heap(T*array, size_t size)
//	{
//		_array.reserve(size);
//		for (int i = 0; i < size; i++)
//		{
//			_array.push_back(array[i]);
//		}
//		//建堆
//		for (int root = (size - 2) >> 1; root >= 0; root--)
//		{
//			AdjustDown(root);
//		}
//
//	}
//	void AdjustDown(int parent)
//	{
//		int child = 2 * parent + 1;
//		size_t size = _array.size();
//		while (child < size)
//		{
//			if ((child + 1)<size&&Compare()(_array[child+1], _array[child]))
//			{
//				child = child + 1;
//			}
//			if (Compare()(_array[child], _array[parent]))
//			{
//				swap(_array[child], _array[parent]);
//				parent = child;
//				child = 2 * parent + 1;
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//	void push(const T&data)
//	{
//		int child = _array.size() - 1;
//		_array.push_back(data);
//		while (_array.size() > 1)
//		{
//			AdjustUp(child);
//		}
//	}
//	void AdjustUp(int child)
//	{
//		size_t parent = (child - 1) >> 1;
//		while (child > 0)
//		{
//			if (Compare()(_array[child], _array[parent]))
//			{
//				swap(_array[parent], _array[child]);
//				child = parent;
//				parent = (child - 1) >> 1;
//			}
//			else
//			{
//				break;
//			}
//		}
//	}
//	void pop()
//	{
//		if (_array.size() == 0)
//		{
//			return;
//		}
//		if (_array.size() > 1)
//		{
//			swap(_array[0], _array[_array.size() - 1]);
//			_array.pop_back();
//			AdjustDown(0);
//		}
//	}
//	T Top()const
//	{
//		return _array[0];
//	}
//	size_t size()
//	{
//		return _array.size();
//	}
//	bool Empty()
//	{
//		return _array.empty();
//	}
//private:
//	vector<T>_array;
//};
