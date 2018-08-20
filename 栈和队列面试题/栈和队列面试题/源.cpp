////1.实现一个栈，要求实现Push(出栈)、pop(入栈)、min(返回最小值的操作)的时间复杂度为O(1)。
////方法：如果两个栈s1,s2作为辅助栈，每次压入s2都是s1的最小值，元素x入栈时，将x和s2栈顶元素进行比较，如果小于等于s2的栈顶，将x分别push到s1,s2,若x大于s2的栈顶，则将x push到s1中，如果s1.top()==s2.top()，s1和s2都执行pop操作，否则先执行s1.pop()
////#include<iostream>
////#include<stack>
////using namespace std;
////template<class T>
////class Minstack
////{
////public:
////	Minstack()
////	{}
////	~Minstack()
////	{}
////	//void push(int data)
////	//{
////	//	s1.push(data);
////	//	if (s2.empty() || data <= s2.top())
////	//	{
////	//		s2.push(data);
////	//	}
////	//}
////	void push(int data)
////	{
////		if (s1.empty()&&s2.empty())
////		{
////			s1.push(data);
////			s2.push(data);
////		}
////		else
////		{
////			if (data <= s2.top())
////			{
////				s1.push(data);
////				s2.push(data);
////			}
////			else
////			{
////				s1.push(data);
////			}
////		}
////	}
////	void pop()
////	{
////		if (s1.top() == s2.top())
////		{
////			s2.pop();
////		}
////		s1.pop();
////	}
////	int Min()
////	{
////		if (!s2.empty())
////		{
////			return s2.top();
////		}
////	}
////private:
////	stack<int> s1, s2;
////};
////int main()
////{
////	Minstack<int> s;
////	s.push(5);
////	s.push(3);
////	s.push(2);
////	s.push(4);
////	s.push(6);
////	s.push(3);
////	s.push(1);
////	cout << s.Min() << endl;
////	s.pop();
////	cout << s.Min() << endl;
////	s.pop();
////	cout << s.Min() << endl;
////	s.pop();
////	cout << s.Min() << endl;
////	s.pop();
////	cout << s.Min() << endl;
////	s.pop();
////	cout << s.Min() << endl;
////	s.pop();
////	system("pause");
////	return 0;
////}
////2.使用两个栈实现一个队列：
//#include<iostream>
//#include<stack>
//using namespace std;
//template<class T>
//class Queue
//{
//public:
//	Queue()
//	{}
//	~Queue()
//	{}
//	void  push(int data)
//	{
//		s1.push(data);
//	}
//	void pop()
//	{
//		int temp = 0;
//		if (s2.empty())
//		{
//			while (!s1.empty())
//			{
//				temp = s1.top();
//				s2.push(temp);
//				s1.pop();
//			}
//		}
//		s2.pop();
//	}
//	int front()
//	{
//		int temp = 0;//如果s2为空时，将s1的值push到s2里 。
//		if (s2.empty())
//		{
//			while (!s1.empty())
//			{
//				temp = s1.top();
//				s2.push(temp);
//				s1.pop();
//			}
//			return s2.top();
//		}
//		else
//		{
//			return s2.top();
//		}
//	}
//private:
//	stack<int>s1, s2;
//};
//int main()
//{
//	Queue<int>q;
//	q.push(1);
//	q.push(2);
//	q.push(3);
//	cout<<q.front()<<endl;
//	q.pop();
//	cout << q.front() << endl;
//	system("pause");
//	return 0;
//}
//3.两个队列建立一个栈
//#include<iostream>
//#include<queue>
//using namespace std;
//template<class T>
//class Stack
//{
//public:
//	Stack()
//	{}
//	~Stack()
//	{}
//	void push(int data)
//	{
//		if (!q1.empty())
//		{
//			q1.push(data);
//		}
//		else
//		{
//			q2.push(data);
//		}
//	}
//	void pop()
//	{
//		queue<T>*empty = q1;
//		queue<T>*NotEmpty = q2;
//		if (!q1.empty())
//		{
//			swap(empty, NotEmpty);//当其不为空时，进行交换
//		}
//		while (NotEmpty->size())
//		{
//			empty->push(NotEmpty->front());//将非空的队列中的元素push到空队列中
//			NotEmpty->pop();//非空队列进行pop
//		}
//		NotEmpty->pop();//当只剩一个元素时，将非空队列中的元素进行pop
//	}
//	int  Top()
//	{
//		if (!q1.empty())
//		{
//			return q1.back();
//		}
//		else
//		{
//			return q2.back();
//		}
//	}
//private:
//	queue<int>q1, q2;
//};
//int main()
//{
//	Stack<int>s;
//	s.push(1);
//	s.push(2);
//	cout << s.Top() << endl;
//	s.pop();
//	system("pause");
//	return 0;
//}
//4.元素出栈、入栈的合法性。如入栈的序列（1，2，3，4，5），出栈的序列为（4，5，3，2，1）
//#include<iostream>
//#include<assert.h>
//#include<stack>
//#include<vector>
//using namespace std;
//bool IsInvalidStackOrder(vector<int>&in, vector<int>&out)
//{
//	assert(in.size() == out.size());
//	stack<int>s;
//	size_t index = 0;
//	size_t outdex = 0;
//	int size1 = in.size();
//	int size2 = out.size();
//	while (index < size1)
//	{
//		s.push(in[index]);
//		while(s.size()>0 && s.top() == out[outdex])
//		{
//			s.pop();
//			outdex++;
//		}
//		index++;
//	}
//	if (s.size() >0)
//	{
//		return false;
//	}
//	else
//	{
//		return true;
//	}
//}
//int main()
//{
//	vector<int>v1;
//	vector<int>v2;
//	v1.emplace_back(1);
//	v1.emplace_back(2); 
//	v1.emplace_back(3);
//	v1.emplace_back(4);
//	v1.emplace_back(5);
//	v2.emplace_back(4);
//	v2.emplace_back(5);
//	v2.emplace_back(3);
//	v2.emplace_back(2);
//	v2.emplace_back(1);
//	cout << boolalpha << IsInvalidStackOrder(v1, v2);
//	system("pause");
//	return 0;
//}
////5.一个数组实现两个栈
////#include<iostream>
////#include<assert.h>
////using namespace std;
////#define MAX_SIZE 1024 
////class SharedStack
////{
////public:
////	SharedStack()
////		:top1(0)
////		, top2(MAX_SIZE)
////	{}
////	void push1(int data)
////	{
////		if (top1 == top2)
////		{
////			return;
////		}
////		arr[top1++] = data;
////	}
////	void push2(int data)
////	{
////		if (top1 == top2)
////		{
////			return;
////		}
////		arr[top2--] = data;
////	}
////	void pop1()
////	{
////		assert(top1>0);
////		top1--;
////	}
////	void pop2()
////	{
////		assert(top2 < MAX_SIZE);
////		top2++;
////	}
////	size_t size1()
////	{
////		return top1;
////	}
////	size_t size2()
////	{
////		return MAX_SIZE-top2;
////	}
////	int Top1()
////	{
////		assert(top1 > 0);
////		return arr[top1];
////	}
////	int Top2()
////	{
////		assert(top2 < MAX_SIZE);
////		return arr[top2];
////	}
////private:
////	int arr[MAX_SIZE];
////	int top1;
////	int top2;
////};
////int main()
////{
////	SharedStack s;
////	for (size_t i = 0; i<4; ++i)
////	{
////		s.push1(i);
////	}
////	for (size_t i = 4; i < 8; ++i)
////	{
////		s.push2(i);
////	}
////	cout << s.size1() << endl;
////	cout << s.size2() << endl;
////	s.pop1();
////	cout << s.size1() << endl;
////	s.pop2();
////	cout << s.size1() << endl;
////	cout << s.Top1() << endl;
////	cout << s.Top2() << endl;
////	system("pause");
////	return 0;
////}
