#include <iostream>
#include <string>
using namespace std;
template<class K, class V, size_t M>//M Ϊ�ڵ����
struct BTreeNode
{
	//kvs��subs��һ���ռ���Ϊ�˲����Ժ��ڷ���
	//�򻯷��ѵ��߼�
	pair<K, V>_kvs[M];         //kvs
	BTreeNode<K, V, M>* _subs[M + 1];//���ӽڵ�
	BTreeNode<K, V, M>* _parent;
	size_t _size;//kvs������
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
template<class K, class V, size_t M>//M Ϊ�ڵ����
class BTree
{
	typedef BTreeNode<K, V, M> Node;
	typedef Node* pNode;
public:
	BTree()
		:_root(NULL)
	{}
	pair<pNode, int>Find(const K&key)//���Һ���
	{
		pNode cur = _root;
		pNode parent = NULL;
		while (cur)
		{
			size_t i = 0;
			while (i < cur->_size)
			{
				if (cur->_kvs[i].first == key)//���ҵ��򷵻ؽڵ�����λ��
				{
					return make_pair(cur, i);
				}
				else if (cur->_kvs[i].first>key)//��keyֵС��cur->_kvs[i].first����������������
				{
					break;
				}
				else   //������������
				{
					++i;
				}
			}
			parent = cur;
			cur = cur->_subs[i];
		}
		//���Ҳ����򷵻�-1��
		return make_pair(parent, -1);
	}
	bool Insert(const pair<K, V>&kv)//���뺯��
	{
		//1.��Ϊ����
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
			return false;//˵��key�ڽڵ���`
		}
		pNode cur = ret.first;
		pair<K, V>newkv = kv;
		pNode sub = NULL;
		while (1)//���ϵ����Ϸ���
		{
			Insertkv(cur, newkv, sub);
			if (cur->_size < M)
			{
				return true;
			}
			else
			{
				//�ߵ��ˣ���ʾ�ڵ���������Ҫ���з���
				pNode brother = new Node;
				//��cur�ڵ���Ұ�������Ѹ��ֵܽڵ�
				size_t mid = (M / 2);
				size_t j = 0;//���Ұ����俽��
				for (size_t i = mid + 1; i < cur->_size; ++i)
				{
					brother->_kvs[j] = cur->_kvs[i];
					brother->_subs[j] = cur->_subs[i];
					if (brother->_subs[j])
					{
						brother->_subs[j]->_parent = brother;
					}
					++j;
					brother->_size++;//���ӽڵ�
				}
				//�����ʣһ���Һ���
				brother->_subs[j] = cur->_subs[cur->_size];//�����һ������brother��
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
				else//�и���ʱ
				{
					newkv = cur->_kvs[mid];
					sub = brother;
					cur = cur->_parent;
				}
			}
		}
	}
	void Insertkv(pNode cur, const pair<K, V>&kv, pNode sub)//subΪһ������
	{
		int end = cur->_size - 1;
		while (end >= 0)
		{
			if (cur->_kvs[end].first < kv.first)//����ֵ����cur->_kvs[end].first���������end+1��λ��
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
		cur->_subs[end + 2] = sub;//Ų���Һ���
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
		for (; i < cur->_size; ++i)//cur->_size���ڵ�ĸ�����Ϊ�ϱ�key�ĸ���
		{
			_InOrder(cur->_subs[i]);//����
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