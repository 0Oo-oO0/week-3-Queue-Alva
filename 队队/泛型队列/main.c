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
	if (IsEmptyAQueue(&c1)) printf("����Ϊ��\n");
	EnAQueue(&c1, &a);
	GetHeadAQueue(&c1, &b);
	printf("%d\n", b);
	DeAQueue(&c1);
	EnAQueue(&c1, &c);
	GetHeadAQueue(&c1, &d);
	printf("%c\n", d);
	printf("���鳤��Ϊ:%d\n", LengthAQueue(&c1));
	EnAQueue(&c1, &a);
	if (IsFullAQueue(&c1)) printf("��������\n");
	TraverseAQueue(&c1, fff);
	ClearAQueue(&c1);
	if (IsEmptyAQueue(&c1)) printf("����Ϊ��\n");


	printf("LQueue\n");
	LQueue c2;
	InitLQueue(&c2);
	if(IsEmptyLQueue(&c2)) printf("����Ϊ��\n");
	EnLQueue(&c2, &a);
	GetHeadLQueue(&c2, &x);
	printf("%d\n", x);
	DeLQueue(&c2);
	EnLQueue(&c2, &c);
	GetHeadLQueue(&c2, &y);
	printf("%c\n", y);
	printf("���鳤��Ϊ:%d\n", LengthLQueue(&c2));
	EnLQueue(&c2, &a);
	TraverseLQueue(&c2, fff);
	ClearLQueue(&c2);
	if (IsEmptyLQueue(&c2)) printf("����Ϊ��\n");





	system("pause");
	return 0;
}

void ppppp(void * q)
{
	printf("%d\n", q);
}
