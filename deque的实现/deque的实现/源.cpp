#include<iostream>
#include<algorithm>

using namespace std;
template<class T,class Ref,class Ptr,size_t BufSiz>
struct _deque_Iterator
{
	typedef _deque_Iterator<T, T&, T*, BufSiz>iterator;
	typedef _deque_Iterator<T, const T&, const T*, BufSiz>const_iterator;
	static size_t buffsize(){
		return _deque_buf_size(BufSiz, sizeof(T));
	}
	typedef random_access_iterator_tag iterator_category;
	typedef T         value_type;
	typedef Ptr        pointer;
	typedef Ref        reference;
	typedef size_t     size_type;
	typedef ptrdiff_t  difference_type;// :表示两个迭代器之间的距离的类型，因此它也可以用来表示一个容器的最大容量。

	typedef T**        map_pointer;
	typedef _deque_Iterator self;
	//保持与容器的联结
	T*cur;//此迭代器所指之缓冲区中的现行（current)元素
	T*first;//此迭代器所指之缓冲区的头
	T*last;//次迭代器去所指之缓冲区的尾
	map_pointer node;//指向管控中心

	//其中用来决定缓冲区大小的函数buffer_size(),调用_deque_buf_size()函数
	//如果n不为0，传回n,表示buffer_size由用户定义
	//如果n为0，表示buffer_size使用默认值，那么：
	//如果:sz(元素大小，sizeof(value_type))小于512，传回512/sz
	//如果sz不小于512，传回1
	inline size_t _deque_buf_size(size_t n, size_t sz)
	{
		return n != 0 ? n : (sz < 512 ? size_t(512 / sz) : size_t(1));
	}
	void set_node(map_pointer new_node)
	{
		node = new_node;
		first = *new_node;
		last = first + difference_type(buffsize());
	}
	//以下是各个运算符的操作
	reference operator*()const
	{
		return *cur;
	}
	pointer operator->()const
	{
		return &(cur);
	}
	/*difference_type operator--(const self&x)const
	{
		return difference_type(buffsize())*(node - x.node - 1) + (cur - first) + (x.last - x.cur);
	}*/
	self&operator++()
	{
		++cur;//切换至下一个元素
		if (cur == last)//如果已达到所在缓冲区的尾端
		{
			set_node(node + 1);//就切换至下一个节点
			cur = first;//切换至下一个节点的第一个元素
		}
	}
	self operator++(int)
	{
		self temp = *this;
		++*this;
		return temp;
	}
	self&operator--()
	{
		if (cur == first)//如果已达到缓冲区的头端
		{
			set_node(node - 1);//切换到前一个节点
			cur = last;//前一个节点的最后一个元素
		}
		--cur;//切换到前一个元素
		return *this;
	}
	self operator--(int)
	{
		self temp = *this;
		--*this;
		return temp;
	}
	reference operator[](difference_type n)const
	{
		return *(*this + n);
	}
	bool operator==(const self&x)
	{
		return cur == x.cur;
	}
	bool operator!=(const self&x)
	{
		return cur != x.cur;
	}
	bool operator<(const self&x)const
	{
		return (node == x.node) ? (cur < x.cur) : (node < x.node);
	}
};
template<class T,class Alloc=alloc,size_t Bufsiz=0>
class deque
{
public:
	typedef T value_type;
	typedef T* pointer;
	typedef size_t size_type;
	typedef T& reference;
	typedef  _deque_Iterator<T, T&, T*, Bufsiz>  iterator;
	iterator begin()
	{
		return start;
	}
	iterator end()
	{
		return finish;
	}
	reference operator[](size_type(n))
	{
		return start[difference_type(n)];
	}
	reference front()
	{
		return *start;
	}
	reference back()
	{
		iterator temp = finish;
		--temp;
		return *temp;
	}
	size_type size()const
	{
		return finish - start;
	}
	size_type max_size()const
	{
		return size_type(-1);
	}
	bool empty()const
	{
		return finish == start;
	}
protected:
	//元素的指针的指针
	typedef pointer*map_pointer;
	iterator start;//表现第一个节点
	iterator finish;
	map_pointer map;//指向map,map是块连续空间，
		//其每个元素都是个指针，指向一个节点（缓冲区）
	size_type map_size;//map内有多少个指针
};
//template<class T, class Alloc = alloc, size_t Bufsiz = 0>
//int main()
//{
//	deque<int, alloc, 8>ideq(20, 9);
//	cout << ideq.size() << endl;
//	system("pause");
//	return 0;
//}