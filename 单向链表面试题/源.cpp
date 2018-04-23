#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
typedef int DataType;
typedef struct Node
{
	struct Node*next;
	DataType data;
}Node,*plist,*pNode;
void initLinkList(plist*pplist)//��ʼ����������ָ��ı�һ��ָ���ָ��
{
	assert(pplist);//����pplist�Ƿ�ΪNULL
	*pplist = NULL;
}
pNode Buynode(DataType data)//�����½ڵ�
{
	pNode newnode = (pNode)malloc(sizeof(Node));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(0);
	}
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}
void PushFront(plist*pplist, DataType data)//ͷ��
{
	assert(pplist);
	pNode p = Buynode(data);
	p->next = *pplist;
	*pplist = p;
}
void popFront(plist*pplist)//ͷɾ
{
	assert(pplist);
	pNode cur = *pplist;
	if (*pplist == NULL)
	{
		return;
	}
	*pplist = cur->next;
	free(cur);
	cur = NULL;
}
void PushBack(plist*pplist, DataType data)//β��
{
	assert(pplist);
	pNode p = Buynode(data);
	pNode cur = *pplist;
	if (*pplist == NULL)
	{
		*pplist = p;
		return;
	}
	while (cur->next)
	{
		cur = cur->next;
	}
	cur->next = p;
}
void popBack(plist*pplist)//βɾ
{
	pNode cur = *pplist;
	pNode prev = NULL;
	assert(pplist);
	//����û�нڵ�
	if (*pplist == NULL)
	{
		return;
	}
	//������һ���ڵ�
	if (cur->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
		return;
	}
	//�������������������Ͻڵ�
	while (cur->next != NULL)
	{
		prev = cur;//prev�б������cur֮ǰ���Ǹ��ڵ�
		cur = cur->next;
	}
	prev->next = NULL;
	free(cur);
}
pNode Find(plist p, DataType data)//���ҽڵ�ָ���Ԫ��
{
	pNode cur = p;
	while (cur)
	{
		if (cur->data == data)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void remove(plist*pplist, DataType data)//ɾ��������ָ����һ��Ԫ�صĽڵ�
{
	assert(pplist);
	pNode del = NULL;
	pNode cur = Find(*pplist,data);
	if (cur == NULL)
	{
		return;
	}
	del = cur->next;
	cur->data=del->data;
	cur->next = del->next;
	free(del);
	del = NULL;
}
void Insert(plist*pplist, pNode pos, DataType data)//ָ��λ�õĲ���
{
	assert(pplist);
	pNode newnode = Buynode(data);
	assert(pos);
	if (*pplist == NULL)//ͷ��
	{
		newnode->next = *pplist;
		*pplist = newnode;
	}
	newnode->next = pos->next;//����pos�ĺ���
	pos->next = newnode;
}
void Erase(plist*pplist, pNode pos)//ָ��λ�õ�ɾ��
{
	assert(pplist);
	assert(pos);
	//�����β�ڵ㣬�����βɾ����
	if (pos->next == NULL)
	{
		popBack(pplist);
	}
	//������β�ڵ�
	else
	{
		pNode del = pos->next;
		pos->data = del->data;
		pos->next = del->next;
		free(del);
		del = NULL;
	}

}
void destory(plist*pplist)//��������
{
	assert(pplist);
	pNode cur = *pplist;
	while (cur)
	{
		pNode del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
}
void display(plist p)//��ӡ����
{
	assert(p);
	while (p)
	{
		printf("%d->", p->data);
		p = p->next;
	}
	printf("NULL");
	printf("\n");
}
void printreverse(plist p)//�����ӡ��������(�ݹ�ʵ�֣�
{
	if (p == NULL)
	{
		return;
	}
	else if (p->next == NULL)
	{
		printf("%d->", p->data);
	}
	else
	{
		printreverse(p->next);
		printf("%d->", p->data);
	}
}
void DelNotTail(pNode pos)//ɾ��һ����ͷ������ķ�β�ڵ�(��Erase�ĵڶ������һ����
{
	pNode del = NULL;
	assert(pos->next);
		del = pos->next;
		pos->data = del->data;
		pos->next = del->next;
		free(del);
		del = NULL;
}
void insertnode(pNode pos, DataType d)//����ͷ�������һ����ͷ�ڵ�ǰ����һ���ڵ�
{
	pNode newnode = Buynode(d);
	newnode->next = pos->next;
	pos->next = newnode;
	newnode->data = d;
	DataType temp = 0;
	//�������е���ֵ���н���
	temp = pos->data;
	pos->data = newnode->data;
	newnode->data = temp;
}
void JosephCycle(plist p, DataType k)//������ʵ��Լɪ��
{
	pNode cur = p;
	int count = 0;
	while (1)//����һֱѭ����ȥ
	{
		int count = k;
		if (cur == cur->next)//����û���ֻ��һ��Ԫ��������
		{
			//printf("%d", cur->data);
			break;
		}
		while (--count)//�ߵĲ���
		{
			cur = cur->next;
		}
		printf("%d ",cur->data);//��ӡҪɾ����Ԫ��
		//ʵ��ɾ������ɾ��һ����ͷ������ķ�β�ڵ���ͬ
		pNode del = cur->next;
		cur->data = del->data;
		cur->next = del->next;
		free(del);
	}
	printf("\nʣ���˵ı�ţ�%d\n", cur->data);
}
void Reverse(plist*pplist)//����/��ת������
{
	assert(pplist);
	pNode cur = *pplist;
	pNode newnode = NULL;
	if (cur == NULL || (cur->next) == NULL)
	{
		return;
	}
	while (cur != NULL)//�ų������������֮��
		//��������ĵ�һ���ڵ�ȡ�������棬֮�����ν�ʣ�µĽڵ�ȡ�·��ڵ�һ���ڵ�֮ǰ���������ָ��*pplist
	{
		pNode pre = cur;
		cur = cur->next;
		pre->next = newnode;
		newnode = pre;
	}
	//�����newnodeָ��*pplist
	 *pplist=newnode;
}
void Bubblesort(plist*pplist)//����������(ð������)
{
	assert(pplist);
	pNode cur = *pplist;
	pNode tail = NULL;
	if (cur == NULL || cur->next == NULL)
	{
		return;
	}
	//������������ð������
	while ((cur->next)!=tail)//�ܵ�����
	{
		while ((cur->next) != tail)
		{
			if ((cur->data) > (cur->next->data))
			{
				DataType temp = cur->data;
				cur->data = cur->next->data;
				cur->next->data = temp;
			}
			cur = cur->next;
		}
			tail = cur;
			cur = *pplist;
	}
}
plist Merge(plist*pplist1, plist *pplist2)//�ϲ��������������ϲ�����Ȼ����
{
	assert(pplist1);
	assert(pplist2);
	pNode cur1 = *pplist1;
	pNode cur2 = *pplist2;
	pNode head = NULL;
	pNode tail = NULL;
	if ((*pplist1 == NULL) && (*pplist2 == NULL))//��һ�����
	{
		return NULL;
	}
	//�ڶ������
	if (*pplist1 == NULL)
	{
		return *pplist2;
	}
	if ((*pplist2 == NULL) || (*pplist1 == *pplist2))
	{
		return *pplist1;
	}
	//���������,��һ��Ԫ���Ƚ��бȽϣ���������С�ķ��ڵ�һ��
	if ((cur1->data) < (cur2->data))
	{
		head = cur1;
		tail = head;
		cur1 = cur1->next;
	}
	else
	{
		head = cur2;
		tail = head;
		cur2 = cur2->next;
	}
	while ((cur1!=NULL)&&(cur2!=NULL))
	{
		if ((cur1->data) < (cur2->data))
		{
			tail->next = cur1;
			cur1 = cur1->next;
		}
		else
		{
			tail->next = cur2;
			cur2= cur2->next;
		}
		tail = tail->next;
	}
	if (cur1)
	{
		tail->next = cur1;
	}
	if (cur2)
	{
		tail->next = cur2;
	}
	return head;//����ͷָ��
}
pNode FindMidNode(plist p)//����������м�ڵ�
{
//��������ָ�룬һ����ָ�룬һ����ָ�룬����ָ��������������ʱ����ָ��պ��ߵ��м�
	pNode fast = p;
	pNode slow = p;
	if (p == NULL)
	{
		return NULL;
	}
	while ((fast) && (fast->next))
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}
void DelKNode(plist p, DataType k)//ɾ������ĵ�����K���ڵ�
{
	//��С��Ҳ���ÿ���ָ��ķ�ʽ���У��ÿ��ָ������k-1������һ���ٿ�ʼ�ߣ���ĵ����յ�ʱ�����ĸպ��ߵ�������k���ڵ�
	pNode fast = p;
	pNode slow = p;
	pNode del = NULL;
	if ((p == NULL) && (k == 0))
	{
		return;
	}
	while ((fast) && (fast->next))
	{
		while (--k > 0)
		{
			fast = fast->next;
		}
		fast = fast->next;
		slow = slow->next;
	}
	//����ɾ��
	del = slow->next;
	slow->data = del->data;
	slow->next = del->next;
	free(del);
}
pNode HasCircle(plist p)//�ж������Ƿ����
{
	////��������ָ�룬һ����ָ�룬һ����ָ�룬
	//����л����������ſ���ָ������������û�л�����ָ����ߵ��յ�
	pNode fast = p;
	pNode slow = p;
	if (p == NULL)
	{
		return NULL;
	}
	while ((fast) && (fast->next))
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			return fast;//���ؿ�ָ��
		}
	}
	return NULL;//���û�л��򷵻�NULL��
}
int Circlelength(pNode m)//��һ��m(meet)ָ���ס�����㣬��m���������߲�����һ����һ��
//�ٶ���һ��ָ��m1���������ߣ���һȦ�������mʱ���պ�����һȦ�������������
{
	pNode m1= m;
	int count = 0;
	do{
		count++;
		m1 = m1->next;
	} while (m1 != m);
	return count;
}
pNode GetCircleEntryNode(pNode m, plist p)//�󻷵���ڴ�
//����һ����ָ�룬һ����ָ�룬��ָ�����߻��ĳ��Ȳ�����ָ�뿪ʼ�ߣ�����ָ�������ĵط���Ϊ������ڵ�
{
	pNode fast = p;
	pNode slow = p;
	int num = Circlelength(m);
	while (num--)
	{
		fast = fast->next;
	}
	while (fast != slow)
	{
		fast = fast->next;
		slow = slow->next;
	}
	if (fast == slow)
	{
		return fast;
	}
}
pNode CheckListCross(plist p1, plist p2)//�ж����������Ƿ��ཻ����������������
//��һ�������β������һ�������ͷ������ת��Ϊ�Ƿ�������⣬����н��㣬����γ�һ������û�����ཻ
{
	pNode cur1 = p1;
	pNode cur2 = p2;
	while (cur1->next)
	{
		cur1 = cur1->next;
	}
	cur1->next = cur2;
	pNode m = HasCircle(p1);
	if (m == NULL)
	{
		return NULL;
	}
	else
	{
		pNode ret = GetCircleEntryNode(m, p1);//��ý���
		return ret;
	}
}
void test1()
{
	plist p1;
	initLinkList(&p1);
	PushFront(&p1, 1);
	PushFront(&p1, 2);
	PushFront(&p1, 3);
	PushFront(&p1, 4);
	display(p1);
	popFront(&p1);
	popFront(&p1);
	popFront(&p1);
	display(p1);
	destory(&p1);
}
void test2()
{
	plist p2;
	initLinkList(&p2);
	PushBack(&p2, 1);
	PushBack(&p2, 2);
	PushBack(&p2, 3);
	PushBack(&p2, 4);
	display(p2);
	popBack(&p2);
	display(p2);
	destory(&p2);
}
void test3()
{
	plist p2;
	initLinkList(&p2);
	PushBack(&p2, 1);
	PushBack(&p2, 2);
	PushBack(&p2, 3);
	PushBack(&p2, 4);
	display(p2);
	pNode ret = Find(p2, 2);
	printf("%d\n", ret->data);
	Erase(&p2, ret);
	display(p2);
	remove(&p2, 3);
	display(p2);
	destory(&p2);
}
void test4()
{
	plist p2;
	initLinkList(&p2);
	PushBack(&p2, 1);
	PushBack(&p2, 2);
	PushBack(&p2, 3);
	PushBack(&p2, 4);
	printreverse(p2);
	destory(&p2);
}
void test5()//ɾ��һ����ͷ������ķ�β�ڵ�
{
	plist p2;
	initLinkList(&p2);
	PushBack(&p2, 1);
	PushBack(&p2, 2);
	PushBack(&p2, 3);
	PushBack(&p2, 4);
	printf("֮ǰ������Ϊ");
	display(p2);
	pNode ret = Find(p2, 2);
	DelNotTail(ret);
	printf("ɾ���ڵ�������Ϊ��");
	display(p2);
	destory(&p2);
}
void test6()
{
	plist p2;
	initLinkList(&p2);
	PushBack(&p2, 1);
	PushBack(&p2, 2);
	PushBack(&p2, 3);
	PushBack(&p2, 4);
	printf("֮ǰ������Ϊ");
	display(p2);
	pNode ret = Find(p2, 2);
	insertnode(ret, 6);
	printf("���������������Ϊ��");
	display(p2);
	destory(&p2);
}
void test7()
{
	plist p2;
	initLinkList(&p2);
	for (int i = 1; i <= 41; i++)
	{
		PushBack(&p2, i);
	}
	pNode ret = Find(p2, 41);
	ret->next = p2;
	JosephCycle(p2, 3);
}
void test8()
{
	plist p2;
	initLinkList(&p2);
	PushBack(&p2, 1);
	PushBack(&p2, 2);
	PushBack(&p2, 3);
	PushBack(&p2, 4);
	printf("֮ǰ������Ϊ");
	display(p2);
	Reverse(&p2);
	printf("���������������Ϊ��");
	display(p2);
	destory(&p2);
}
void test9()
{
	plist p2;
	initLinkList(&p2);
	PushBack(&p2, 1);
	PushBack(&p2, 2);
	PushBack(&p2, 8);
	PushBack(&p2, 4); 
	printf("֮ǰ������Ϊ");
	display(p2);
	Bubblesort(&p2);
	printf("���������������Ϊ��");
	display(p2);
	destory(&p2);
}
void test10()
{
	plist p1;
	initLinkList(&p1);
	PushBack(&p1, 1);
	PushBack(&p1, 2);
	PushBack(&p1, 3);
	PushBack(&p1, 4);
	plist p2;
	initLinkList(&p2);
	PushBack(&p2, 2);
	PushBack(&p2, 2);
	PushBack(&p2, 5);
	PushBack(&p2, 6);
	pNode newlist=Merge(&p1, &p2);
	display(newlist);
	destory(&newlist);
}
void test11()
{
	plist p1;
	initLinkList(&p1);
	PushBack(&p1, 1);
	PushBack(&p1, 2);
	PushBack(&p1, 3);
	PushBack(&p1, 4);
	PushBack(&p1, 5);
	PushBack(&p1, 6);
	PushBack(&p1, 7);
	PushBack(&p1, 8);
	pNode ret = FindMidNode(p1);
	printf("%d\n", ret->data);
	destory(&p1);
}
void test12()
{
	plist p1;
	initLinkList(&p1);
	PushBack(&p1, 1);
	PushBack(&p1, 2);
	PushBack(&p1, 3);
	PushBack(&p1, 4);
	PushBack(&p1, 5);
	PushBack(&p1, 6);
	PushBack(&p1, 7);
	PushBack(&p1, 8);
	printf("֮ǰ������Ϊ");
	display(p1);
	DelKNode(p1, 2);
	printf("���������������Ϊ��");
	display(p1);
	destory(&p1);
}
void test13()
{
	plist p1;
	initLinkList(&p1);
	PushBack(&p1, 1);
	PushBack(&p1, 2);
	PushBack(&p1, 3);
	PushBack(&p1, 4);
	PushBack(&p1, 5);
	PushBack(&p1, 6);
	PushBack(&p1, 7);
	PushBack(&p1, 8);
	pNode ret = Find(p1, 6);
	ret->next = Find(p1, 3);
	pNode pp = HasCircle(p1);
	if (pp == NULL)
	{
		printf("û��");
	}
	else
	{
		printf("��");
	}
	printf("\n");
	printf("�����㣺%d\n", pp->data);
	printf("���ĳ��ȣ�%d\n", Circlelength(pp));
	pNode m = GetCircleEntryNode(pp, p1);
	printf("������ڵ�Ϊ��%d",m->data);
}
void test14()
{
	plist p1;
	initLinkList(&p1);
	PushBack(&p1, 1);
	PushBack(&p1, 2);
	PushBack(&p1, 3);
	PushBack(&p1, 4);
	PushBack(&p1, 5);
	PushBack(&p1, 6);
	PushBack(&p1, 7);
	PushBack(&p1, 8);
	display(p1);
	plist p2;
	initLinkList(&p2);
	PushBack(&p2, 10);
	PushBack(&p2, 9);
	PushBack(&p2, 9);
	PushBack(&p2, 8);
	display(p2);
	Find(p1, 7)->next = Find(p2, 8);
	pNode ret = CheckListCross(p1, p2);
	if (ret == NULL)
	{
		printf("���ཻ\n");
	}
	else
	{
		printf("�ཻ��Ϊ��%d", ret->data);
	}

}
int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	//test7();
	//test8();
	//test9();
	//test10();
	//test11();
    //test12();
	//test13();
	test14();
	system("pause");
	return 0;
}
