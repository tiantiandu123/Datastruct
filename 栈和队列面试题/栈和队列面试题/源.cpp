////1.ʵ��һ��ջ��Ҫ��ʵ��Push(��ջ)��pop(��ջ)��min(������Сֵ�Ĳ���)��ʱ�临�Ӷ�ΪO(1)��
////�������������ջs1,s2��Ϊ����ջ��ÿ��ѹ��s2����s1����Сֵ��Ԫ��x��ջʱ����x��s2ջ��Ԫ�ؽ��бȽϣ����С�ڵ���s2��ջ������x�ֱ�push��s1,s2,��x����s2��ջ������x push��s1�У����s1.top()==s2.top()��s1��s2��ִ��pop������������ִ��s1.pop()
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
////2.ʹ������ջʵ��һ�����У�
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
//		int temp = 0;//���s2Ϊ��ʱ����s1��ֵpush��s2�� ��
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
//3.�������н���һ��ջ
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
//			swap(empty, NotEmpty);//���䲻Ϊ��ʱ�����н���
//		}
//		while (NotEmpty->size())
//		{
//			empty->push(NotEmpty->front());//���ǿյĶ����е�Ԫ��push���ն�����
//			NotEmpty->pop();//�ǿն��н���pop
//		}
//		NotEmpty->pop();//��ֻʣһ��Ԫ��ʱ�����ǿն����е�Ԫ�ؽ���pop
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
//4.Ԫ�س�ջ����ջ�ĺϷ��ԡ�����ջ�����У�1��2��3��4��5������ջ������Ϊ��4��5��3��2��1��
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
////5.һ������ʵ������ջ
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
