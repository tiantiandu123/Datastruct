#include"heap.h"
template<class W>
struct HuffmanTreeNode
{
	HuffmanTreeNode()
		:_pLeft(NULL)
		, _pRight(NULL)
		, _weight(0)
	{}
	HuffmanTreeNode(W weight)
		:_pLeft(NULL)
		, _pRight(NULL)
		, _weight(weight)
	{}
	HuffmanTreeNode<W>*_pLeft;
	HuffmanTreeNode<W>*_pRight;
	W _weight;//权值
};
template<class W>
class HuffmanTree
{
public:
	typedef HuffmanTreeNode<W> Node;
	typedef HuffmanTreeNode<W>* pNode;
	HuffmanTree(W*array,size_t size,const W&invalid)
	{
		_CreateHuffmanTree(array, size, 0);
	}
	~HuffmanTree()
	{
		destory(_pRoot);
	}
private:
	void _CreateHuffmanTree(W*array, size_t size, const W&invalid)
	{
		if (hp.Empty())
		{
			_pRoot = NULL;
		}
		Heap<pNode>hp;//堆中存的是Huffman树的结点
		for (int i = 0; i < size; i++)
		{
			if (array[i] != invalid)
			{
				hp.push(new Node(array[i]));
			}
		}
		//取出堆顶元素
		while (hp.size()>1)
		{
			pNode pLeft = hp.Top();
			hp.pop();
			pNode pRight = hp.Top();
			hp.pop();
			pNode Parent = new Node(pLeft->_weight + pRight->_weight);
			if (pLeft->_weight < pRight->_weight)
			{
				Parent->_pLeft = pLeft;
			}
			else
			{
				Parent->_pRight = pRight;
			}
			hp.push(Parent);
		}	
		_pRoot = hp.Top();
	}
	void destory(pNode pRoot)
	{
		if (pRoot)
		{
			destory(pRoot->_pRight);
			destory(pRoot->_pLeft);
			delete pRoot;
		}
	}
	pNode _pRoot;
	Heap<W> hp;
};