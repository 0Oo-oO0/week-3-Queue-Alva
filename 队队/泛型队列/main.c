#include"main.h"






int main()
{
	int a = 1,b,x;
	char c = 'a', d,y;
	void (*fff)(void * q);
	fff = ppppp;
	AQueue c1;
	printf("AQueue\n");
	InitAQueue(&c1);
	if (IsEmptyAQueue(&c1)) printf("队列为空\n");
	EnAQueue(&c1, &a);
	GetHeadAQueue(&c1, &b);
	printf("%d\n", b);
	DeAQueue(&c1);
	EnAQueue(&c1, &c);
	GetHeadAQueue(&c1, &d);
	printf("%c\n", d);
	printf("数组长度为:%d\n", LengthAQueue(&c1));
	EnAQueue(&c1, &a);
	if (IsFullAQueue(&c1)) printf("队列已满\n");
	TraverseAQueue(&c1, fff);
	ClearAQueue(&c1);
	if (IsEmptyAQueue(&c1)) printf("队列为空\n");


	printf("LQueue\n");
	LQueue c2;
	InitLQueue(&c2);
	if(IsEmptyLQueue(&c2)) printf("队列为空\n");
	EnLQueue(&c2, &a);
	GetHeadLQueue(&c2, &x);
	printf("%d\n", x);
	DeLQueue(&c2);
	EnLQueue(&c2, &c);
	GetHeadLQueue(&c2, &y);
	printf("%c\n", y);
	printf("数组长度为:%d\n", LengthLQueue(&c2));
	EnLQueue(&c2, &a);
	TraverseLQueue(&c2, fff);
	ClearLQueue(&c2);
	if (IsEmptyLQueue(&c2)) printf("队列为空\n");





	system("pause");
	return 0;
}

void ppppp(void * q)
{
	printf("%d\n", q);
}
