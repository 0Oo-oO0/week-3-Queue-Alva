#include"LQueue.h"

void InitLQueue(LQueue * Q)
{
	Q->head = (Node *)malloc(sizeof(Node));
	Q->tail = (Node *)malloc(sizeof(Node));
	Q->head->next = Q->tail;
	Q->tail->data = 0;
	Q->tail->next = NULL;
	Q->length = 0;
}

void DestoryLQueue(LQueue * Q)
{
	Node *p;
	p = Q->head;
	while (p)
	{
		p = Q->head->next;
		free(Q->head);
		Q->head = p;
	}
	Q->head = Q->tail = NULL;
	Q->length = 0;
}

Status IsEmptyLQueue(const LQueue * Q)
{
	if (Q->head->next == Q->tail) return 1;
	return 0;
}

Status GetHeadLQueue(LQueue * Q, void * e)
{
	if (IsEmptyLQueue(Q))return 0;
	memcpy(e, Q->head->next->data, sizeof(Q->head->data));
	return 1;
}

int LengthLQueue(LQueue * Q)
{
	return Q->length;
}

Status EnLQueue(LQueue * Q, void * data)
{
	Node *p;
	p = Q->tail;
	p->data = (void *)malloc(sizeof(data));
	memcpy(p->data, data, sizeof(data));
	Q->tail = (Node *)malloc(sizeof(Node));
	p->next = Q->tail;
	Q->length++;
	Q->tail->next = NULL;
	return 1;
}

Status DeLQueue(LQueue * Q)
{
	if (IsEmptyLQueue(Q)) return 0;
	Node *q;
	q = Q->head->next;
	Q->head->next = q->next;
	free(q);
	Q->length--;
	return 1;
}

void ClearLQueue(LQueue * Q)
{
	if (IsEmptyLQueue(Q))return 0;
	Node *p,*q;
	p = Q->head->next;
	while (p != Q->tail)
	{
		q = p;
		p = p->next;
		free(q);
	}
	Q->head->next = Q->tail;
	return 1;
}

Status TraverseLQueue(const LQueue * Q, void(*foo)(void *q))
{
	if (IsEmptyLQueue(Q))return 0;
	Node *q;
	q = Q->head->next;
	while (q != Q->tail)
	{
		foo(q->data);
		q = q->next;
	}
	return 1;
}

void LPrint(void * q)
{
}
