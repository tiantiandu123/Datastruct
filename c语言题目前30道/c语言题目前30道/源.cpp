//1.使用c语言编写程序，在屏幕上显示”hello world”

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h> 
#include<cmath>
#include<assert.h>
#include<string.h>
#if 0
int main()
{
	printf("hello world\n");
	system("pause");
	return 0;
}
#endif

//2.计算1,2,…100这100个数的和 (循环）

#if 0
int main()
{
	int sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		sum += i;
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}
#endif

//3. 在屏幕上打印9*9乘法表

#if 0
int main()
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%d", i, j, i*j);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
#endif

//4.求两个整数的较大值（分支判断）

#if 0
int main()
{
	int i = 0;
	int j = 0;
	scanf("%d ,%d", &i, &j);
	if (i > j)
		printf("%d\n", i);
	else
	{
		printf("%d\n", j);
	}
	system("pause");
	return 0;
}
#endif

//5.求十个整数中的最大数（循环）

#if 0
int main()
{
	int arr[10] = { 0 };
	int i = 0;
	int max = 0;
	for (i = 0; i <sizeof(arr) / sizeof(arr[0]); i++)
	{
		scanf("%d", &arr[i]);
	}
	max = arr[0];
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	printf("max=%d\n", max);
	system("pause");
	return 0;
}
#endif

//6.求1到100间的素数

#if 0
int main()
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= 100; i = i + 2)
	{
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i%j == 0)
				break;
		}
		if (j>sqrt(i))
			printf("%d\n", i);
	}
	system("pause");
	return 0;
}
#endif

//7.求两个整数的最大公约数(辗转相除）

#if 0
int main()
{
	int a = 0;
	int b = 0;
	int k = 0;
	scanf("%d,%d", &a, &b);
	if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	while (b)
	{
		int c = a%b;
		a = b;
		b = c;
	}
	printf("最大公约数为：%d\n", a);
	system("pause");
	return 0;
}
#endif

//8. 求两个整数的最小公倍数(辗转相除）

#if 0
int main()
{

	int a = 0;
	int b = 0;
	int k = 0;
	scanf("%d,%d", &a, &b);
	if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	int d = a;
	int e = b;
	while (b)
	{
		int c = a%b;
		a = b;
		b = c;
	}
	printf("最小公倍数为：%d\n", (d*e) / a);
	system("pause");
	return 0;
}
#endif

//9.交换两整数的值

#if 0
int main()
{
	int a = 0;
	int b = 0;
	int temp = 0;
	scanf("%d,%d", &a, &b);
	temp = a;
	a = b;
	b = temp;
	printf("%d,%d", a, b);
	system("pause");
	return 0;
}
#endif

//10.编写一个函数，交换两个数的值（传址）

#if 0
int main()
{
	int num1 = 10;
	int num2 = 20;
	int Swap(int *x, int *y);
	Swap(&num1, &num2);
	printf("num1 = %d num2 = %d\n", num1, num2);
	system("pause");
	return 0;
}
int Swap(int *x, int *y)
{
	int tmp = 0;
	tmp = *x;
	*x = *y;
	*y = tmp;
	return 0;
}
#endif

//11.有1,2,3,4四个数字，能组成多少个互不相同且无重复数字的三位数，都是多少 
//程序分析：可填在百位、十位、个位的数字都是1、2、3、4。组成所有的排列后再去掉不满足条件的排列。

#if 0
int main()
{
	int i = 0;
	int j = 0;
	int k = 0;
	int count = 0;
	for (i = 1; i <= 4; i++)
	{
		for (j = 1; j <= 4; j++)
		{
			for (k = 1; k <= 4; k++)
			{
				if ((i != j) && (i != k) && (j != k))
				{
					count++;
					printf("%d%d%d\n", i, j, k);
				}
			}
		}
	}
	printf("总数为：%d\n", count);
	system("pause");
	return 0;
}
#endif

//12.输出两千年之前的所有闰年及个数

#if 0
int main()
{
	int i = 0;
	int count = 0;
	for (i = 1; i <= 2000; i++)
	{
		if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
		{
			count++;
			printf("%d\n", i);
		}
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}
#endif

//13.有一分数序列：2/1,3/2,5/3,8/5,13/8,21/13…求出这个数列的前二十项之和

#if 0
int main()
{
	int a = 2, b = 1, c = 0, sum = 0;
	for (int i = 1; i <= 20; i++)
	{
		sum += a / b;
		c = a + b;
		b = a;
		a = c;
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}
#endif

//14.s=a+aa+aaa+aaaa+aa…a的值，例如：2+22+222+2222+22222

#if 0
int main()
{
	int a = 0;
	int b = 0;
	int s = 0;
	int i = 0;
	int w = 0;
	scanf("%d,%d", &a, &w);
	for (i = 0; i < w; i++)
	{
		s = s * 10 + a;
		b = s + b;
	}
	printf("%d\n", b);
	system("pause");
	return 0;
}
#endif

//15.一球从100米高度自由落下，每次落地后反跳回原高度的一半；再落下，求它在第十次落地时共经过多少米？第十次反弹多高？

//int main()
//{
//  float sn = 100.0, hn = sn / 2;
//  int n;
//  for (n = 2; n <= 10; n++)
//  {
//      sn = sn + 2 * hn;/*第n次落地时共经过的米数*/
//      hn = hn / 2; /*第n次反跳高度*/
//  }
//  printf("%f\n", sn);
//  printf("%f\n", hn);
//  system("pause");
//  return 0;
//}

//16.猴子吃桃问题 分析：设x1为前一天桃子数，设x2为第二天桃子数， 则 
//x2 = x1 / 2 - 1, x1 = (x2 + 1) * 2 
//x3 = x2 / 2 - 1, x2 = (x3 + 1) * 2 
//以此类推： x前 = (x后 + 1) * 2 ；

#if 0
int main()
{
	int i = 1;
	int j = 0;
	int day = 9;
	while (day > 0)
	{
		j = (i + 1) * 2;
		i = j;
		day--;
	}
	printf("%d\n", j);
	system("pause");
	return 0;
}
#endif

//17.1-1/2+1/3-1/4+1/5…+1/99-1/100的值

#if 0
int main()
{
	int i = 0;
	double sum = 0;
	int k = 1;
	for (i = 1; i <= 100; i++)
	{
		sum = k*1.0 / i + sum;
		k = -k;
	}
	printf("%f\n", sum);
	system("pause");
	return 0;
}
#endif

//18.求1+2！+3！+…+20!

#if 0
int main()
{
	int i = 0;
	int sum = 0;
	int t = 1;
	for (i = 1; i <= 20; i++)
	{
		t = t*i;
		sum = sum + t;
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}
#endif
//递归算法如下：
#if 0
int main()
{
	int i = 0;
	int sum = 0;
	for (i = 1; i <= 20; i++)
	{
		sum = sum + fac(i);
	}
	printf("%d\n", sum);
}
int fac(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
		return n*fac(n - 1);
}
#endif

//19.判断一个数是否为回文数（回文数也是一个数字，数字的特点是正反序是同一个数字，如：12321,3443就是回文数）

#if 0
int ishuiwen(int n)
{
	//  //assert(n >= 0);
	int num = n;
	int i = 0;
	while (num)
	{
		i = i * 10 + num % 10;
		num = num / 10;
	}
	if (i == n)
	{
		return 1;
	}
	return 0;
}
int main()
{
	int n = 12321;
	int ret = 0;
	ret = ishuiwen(n);
	if (ret == 0)
	{
		printf("no");
	}
	else
	{
		printf("yes ");
	}
	system("pause");
	return 0;
}
#endif

//20.判断一个字符串是否为回文字符串

#if 0
char *str_reverse(char*str, int len) //先进行逆序
{
	assert(str != NULL);
	char*start = str;
	char*end = str + len - 1;
	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
	return str;
}
int main()
{
	char str[] = "abcba";
	char str1[10] = "abcba";
	int len = strlen(str);
	str_reverse(str, len);
	int i = strcmp(str, str1);
	if (i == 0)
	{
		printf("yes");
	}
	else
	{
		printf("no");
	}
	system("pause");
	return 0;
}
#endif

//21.求一个3*3矩阵对角线元素的和
#if 0
int main()
{
	int a[3][3] = { 0 };
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	int sum = a[0][0] + a[1][1] + a[2][2];      //两对角线的和。
	int t = a[2][0] + a[1][1] + a[0][2];
	printf("%d,%d", sum, t);
	system("pause");
	return 0;
}
#endif

//22.将一个整形数组逆序

#if 0
void reverse(int arr[], int n)
{
	for (int i = n - 1; i >= 0; i--)
		printf("%d ", arr[i]);
}
int main()
{
	int arr[5] = { 1, 2, 3, 4, 5 };
	reverse(arr, 5);
	system("pause");
	return 0;
}
#endif

//23.对任意一个整形数组排序（冒泡排序）

#if 0
int main()
{
	int a[] = { 10, 8, 58, 64, 5 };
	int i;
	int j;
	int k;
	int temp;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j<5 - i - 1; j++)
		{
			if (a[j]>a[j + 1])
			{
				temp = a[j + 1];
				a[j + 1] = a[j];
				a[j] = temp;
			}
		}
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}
	system("pause");
	return 0;
}
#endif

//24.将多个字符串排序输出：如”hello”,”bit-tech”,”world”排序后为”bit-tech”,”hello”,”world”

#if 0
int main()
{
	char*arr[] = { "hello", "bit-tech", "world" };
	int i = 0;
	int j = 0;
	for (j = 0; j < (sizeof(arr) / sizeof(arr[0])); j++)
	{
		for (i = 0; i< (sizeof(arr) / sizeof(arr[0])) - j - 1; i++)
		{
			if (strcmp(*(arr + i), *(arr + i + 1))>0)
			{
				char*tmp = *(arr + i);
				*(arr + i) = *(arr + i + 1);
				*(arr + i + 1) = tmp;
			}
		}
	}
	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%s\n", *(arr + i));
	}
	printf("%d\n", sizeof(arr) / sizeof(arr[0]));
	system("pause");
	return 0;
}
#endif

//25.用递归的方式求斐波那契数列的第n个数

#if 0
int Fibonacci(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return  Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = Fibonacci(n);
	printf("%d\n", ret);
	system("pause");
	return 0;
}
#endif

//26.用非递归的方式求斐波那契数列的第n个数

int Fibonacci(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	int a1 = 1;
	int a2 = 1;
	int sum = 0;
	for (int i = 3; i <= n; i++)
	{
		sum = a1 + a2;
		a1 = a2;
		a2 = sum;
	}
	return sum;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = Fibonacci(n);
	printf("%d\n", ret);
	system("pause");
	return 0;
}

//27.编写一个函数可以求字符串的长度

#if 0
int my_strlen(const char*str)
{
	assert(str != NULL);
	int count = 0;
	while (*str++)
	{
		count++;
	}
	return count;
}
int main()
{
	char str[] = "afrgbe";
	int ret = my_strlen(str);
	printf("%d\n", ret);
	system("pause");
	return 0;
}
#endif
//28.不允许创建临时变量求一个字符串的长度（递归）
int my_strlen(const char*str)
{
	assert(str != NULL);
	if (*str != '\0')
	{
		return (1 + my_strlen(str + 1));
	}
	else
		return 0;
}
int main()
{
	char str[] = "afrgbe";
	int ret = my_strlen(str);
	printf("%d\n", ret);
	system("pause");
	return 0;
}

//29.对任意一个整形数组排序（选择排序法）

void select_sort(int a[], int n)//n为数组a的元素个数
{
	//进行N-1轮选择
	for (int i = 0; i<n - 1; i++)
	{
		int min_index = i;
		//找出第i小的数所在的位置
		for (int j = i + 1; j<n; j++)
		{
			if (a[j] < a[min_index])
			{
				min_index = j;
			}
		}
		//将第i小的数，放在第i个位置；如果刚好，就不用交换
		if (i != min_index)
		{
			int temp = a[i];
			a[i] = a[min_index];
			a[min_index] = temp;
		}
	}
}
int  main()
{
	int num[8] = { 89, 38, 11, 78, 96, 44, 19, 25 };
	select_sort(num, 8);
	for (int i = 0; i<8; i++)
		printf("%d  ", num[i]);
	printf("\n");
	system("pause");
	return 0;
}
//30.求一个数的二进制序列中的1的个数（谷歌笔试题）

int main()
{
	int res = 0;
	int x = 5;
	while (x)
	{
		res = res + (x % 2);
		x = x / 2;
	}
	printf("%d\n", res);//res即是x的二进制数中1的个数
	system("pause");
	return 0;
}