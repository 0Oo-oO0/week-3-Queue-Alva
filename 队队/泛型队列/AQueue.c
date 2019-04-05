#include "AQueue.h"

void InitAQueue(AQueue * Q)
{
	for (int i = 0; i < MAXQUEUE; i++)
	{
		Q->data[i] = NULL;
	}
	Q->head = 0;
	Q->tail = 0;
	Q->length = MAXQUEUE;
}

void DestoryAQueue(AQueue * Q)
{
	free(Q);
}

Status IsFullAQueue(const AQueue * Q)
{
	if (Q->head == Q->tail && Q->data[Q->head] != NULL) return 1;
	return 0;
}

Status IsEmptyAQueue(const AQueue * Q)
{
	if (Q->head == Q->tail && Q->data[Q->head] == NULL) return 1;
	return 0;
}

Status GetHeadAQueue(AQueue * Q, void * e)
{
	if (IsEmptyAQueue(Q))return 0;
	memcpy(e, Q->data[Q->head], sizeof(Q->data[Q->head]));
	return 1;
}

int LengthAQueue(AQueue * Q)
{
	if (Q->tail > Q->head)
	{
		return Q->tail - Q->head + 1;
	}
	if (IsEmptyAQueue(Q)) return 0;
	return Q->length - Q->head + Q->tail;
}

Status EnAQueue(AQueue * Q, void * data)
{
	if (IsFullAQueue(Q))return 0;
	if (Q->data[Q->tail] == NULL) Q->data[Q->tail] = (char *)malloc(sizeof(data));
	memcpy(Q->data[Q->tail], data, sizeof(data));
	Q->tail = ++Q->tail%Q->length;
	return 1;
}

Status DeAQueue(AQueue * Q)
{
	if (IsEmptyAQueue(Q))return 0;
	free(Q->data[Q->head]);
	Q->data[Q->head] = NULL;
	Q->head = ++Q->head%Q->length;
	return 1;
}

void ClearAQueue(AQueue * Q)
{
	for (int i = 0; i < Q->length; i++)
	{
		free(Q->data[i]);
		Q->data[i] = NULL;
	}
}

Status TraverseAQueue(const AQueue * Q, void(*foo)(void *q))
{
	if (IsEmptyAQueue(Q))return 0;
	if (Q->tail > Q->head)
	{
		for (int i = Q->head; i < Q->tail; i++)
		{
			foo(Q->data[i]);
		}
	}
	else if(Q->tail < Q->head)
	{
		for (int i = Q->head; i > Q->tail; i--)
		{
			foo(Q->data[i]);
		}
	}
	else
	{
		for (int i = 0; i < Q->length; i++)
		{
			foo(Q->data[i]);
		}
	}
	return 1;
}

void APrint(void * q)
{

}
