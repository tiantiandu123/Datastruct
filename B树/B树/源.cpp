#include <iostream>
#include <string>
using namespace std;
template<class K, class V, size_t M>//M 为节点个数
struct BTreeNode
{
	//kvs和subs多一个空间是为了插入以后在分裂
	//简化分裂的逻辑
	pair<K, V>_kvs[M];         //kvs
	BTreeNode<K, V, M>* _subs[M + 1];//孩子节点
	BTreeNode<K, V, M>* _parent;
	size_t _size;//kvs的数量
	BTreeNode()
		:_parent(NULL)
		, _size(0)
	{
		for (size_t i = 0; i < M + 1; i++)
		{
			_subs[i] = NULL;
		}
	}
};
template<class K, class V, size_t M>//M 为节点个数
class BTree
{
	typedef BTreeNode<K, V, M> Node;
	typedef Node* pNode;
public:
	BTree()
		:_root(NULL)
	{}
	pair<pNode, int>Find(const K&key)//查找函数
	{
		pNode cur = _root;
		pNode parent = NULL;
		while (cur)
		{
			size_t i = 0;
			while (i < cur->_size)
			{
				if (cur->_kvs[i].first == key)//若找到则返回节点与其位置
				{
					return make_pair(cur, i);
				}
				else if (cur->_kvs[i].first>key)//若key值小于cur->_kvs[i].first，则在其左子树中
				{
					break;
				}
				else   //在其右子树中
				{
					++i;
				}
			}
			parent = cur;
			cur = cur->_subs[i];
		}
		//若找不到则返回-1；
		return make_pair(parent, -1);
	}
	bool Insert(const pair<K, V>&kv)//插入函数
	{
		//1.若为空树
		if (_root == NULL)
		{
			_root = new Node;
			_root->_kvs[0] = kv;
			_root->_size = 1;
			return true;
		}
		//2.
		pair<pNode, int>ret = Find(kv.first);
		if (ret.second != -1)
		{
			return false;//说明key在节点中`
		}
		pNode cur = ret.first;
		pair<K, V>newkv = kv;
		pNode sub = NULL;
		while (1)//不断地向上分裂
		{
			Insertkv(cur, newkv, sub);
			if (cur->_size < M)
			{
				return true;
			}
			else
			{
				//走到此，表示节点已满，需要进行分裂
				pNode brother = new Node;
				//将cur节点的右半区间分裂给兄弟节点
				size_t mid = (M / 2);
				size_t j = 0;//将右半区间拷走
				for (size_t i = mid + 1; i < cur->_size; ++i)
				{
					brother->_kvs[j] = cur->_kvs[i];
					brother->_subs[j] = cur->_subs[i];
					if (brother->_subs[j])
					{
						brother->_subs[j]->_parent = brother;
					}
					++j;
					brother->_size++;//增加节点
				}
				//拷完后还剩一个右孩子
				brother->_subs[j] = cur->_subs[cur->_size];//将最后一个拷给brother。
				cur->_size = cur->_size - brother->_size - 1;
				if (cur == _root)
				{
					_root = new Node;
					_root->_kvs[0] = cur->_kvs[mid];
					_root->_subs[0] = cur;
					_root->_subs[1] = brother;
					_root->_size = 1;
					cur->_parent = _root;
					brother->_parent = _root;
					return true;
				}
				else//有父亲时
				{
					newkv = cur->_kvs[mid];
					sub = brother;
					cur = cur->_parent;
				}
			}
		}
	}
	void Insertkv(pNode cur, const pair<K, V>&kv, pNode sub)//sub为一个孩子
	{
		int end = cur->_size - 1;
		while (end >= 0)
		{
			if (cur->_kvs[end].first < kv.first)//若其值大于cur->_kvs[end].first，则需放在end+1的位置
			{
				break;
			}
			else
			{
				cur->_kvs[end + 1] = cur->_kvs[end];
				cur->_subs[end + 2] = cur->_subs[end + 1];
				--end;
			}
		}
		cur->_kvs[end + 1] = kv;
		cur->_subs[end + 2] = sub;//挪走右孩子
		if (sub)
		{
			sub->_parent = cur;
		}
		cur->_size++;
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;
		Node* cur = root;
		size_t i = 0;
		for (; i < cur->_size; ++i)//cur->_size：节点的个数即为上边key的个数
		{
			_InOrder(cur->_subs[i]);//左孩子
			cout << cur->_kvs[i].first << " " << cur->_kvs[i].second << endl;
		}
		_InOrder(cur->_subs[i]);
	}
private:
	Node* _root;
};
void TestBTree()
{
	BTree<int, int, 3> t;
	int a[] = { 53, 75, 139, 49, 145, 36, 101 };
	for (size_t i = 0; i < (sizeof(a) / sizeof(a[0])); ++i)
	{
		t.Insert(make_pair(a[i], i));
	}
	t.InOrder();
}
int main()
{
	TestBTree();
	system("pause");
	return 0;
}