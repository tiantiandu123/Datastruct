#include"Huffman.h"
int main()
{
	int array[] = { 5, 3, 2, 7 };
	HuffmanTree<int>h(array, 4, 0);
	system("pause");
	return 0;
}