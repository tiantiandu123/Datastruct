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
	typedef ptrdiff_t  difference_type;// :��ʾ����������֮��ľ�������ͣ������Ҳ����������ʾһ�����������������

	typedef T**        map_pointer;
	typedef _deque_Iterator self;
	//����������������
	T*cur;//�˵�������ָ֮�������е����У�current)Ԫ��
	T*first;//�˵�������ָ֮��������ͷ
	T*last;//�ε�����ȥ��ָ֮��������β
	map_pointer node;//ָ��ܿ�����

	//��������������������С�ĺ���buffer_size(),����_deque_buf_size()����
	//���n��Ϊ0������n,��ʾbuffer_size���û�����
	//���nΪ0����ʾbuffer_sizeʹ��Ĭ��ֵ����ô��
	//���:sz(Ԫ�ش�С��sizeof(value_type))С��512������512/sz
	//���sz��С��512������1
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
	//�����Ǹ���������Ĳ���
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
		++cur;//�л�����һ��Ԫ��
		if (cur == last)//����Ѵﵽ���ڻ�������β��
		{
			set_node(node + 1);//���л�����һ���ڵ�
			cur = first;//�л�����һ���ڵ�ĵ�һ��Ԫ��
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
		if (cur == first)//����Ѵﵽ��������ͷ��
		{
			set_node(node - 1);//�л���ǰһ���ڵ�
			cur = last;//ǰһ���ڵ�����һ��Ԫ��
		}
		--cur;//�л���ǰһ��Ԫ��
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
	//Ԫ�ص�ָ���ָ��
	typedef pointer*map_pointer;
	iterator start;//���ֵ�һ���ڵ�
	iterator finish;
	map_pointer map;//ָ��map,map�ǿ������ռ䣬
		//��ÿ��Ԫ�ض��Ǹ�ָ�룬ָ��һ���ڵ㣨��������
	size_type map_size;//map���ж��ٸ�ָ��
};
//template<class T, class Alloc = alloc, size_t Bufsiz = 0>
//int main()
//{
//	deque<int, alloc, 8>ideq(20, 9);
//	cout << ideq.size() << endl;
//	system("pause");
//	return 0;
//}