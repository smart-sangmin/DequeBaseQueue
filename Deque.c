#include <stdio.h>
#include "Deque.h"
#include <stdlib.h>

void DequeInit(Deque* pdeq)
{
	pdeq->head = 0;
	pdeq->tail = 0;
}

int DQIsEmpty(Deque* pdeq)
{
	if (pdeq->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void DQAddFirst(Deque* pdeq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = pdeq->head;
	if (DQIsEmpty(pdeq))
		pdeq->tail = newNode;
	else
		pdeq->head->prev = newNode;
	
	newNode->prev = NULL;
	pdeq->head = newNode;
}

void DQAddLast(Deque* pdeq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	newNode->prev = pdeq->tail;
	if (DQIsEmpty(pdeq))
		pdeq->head = newNode;
	else
		pdeq->tail->next = newNode;

	newNode->next = NULL;
	pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque* pdeq)
{
	Node* delNode = pdeq->head;
	Data data = delNode->data;
	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error");
		exit(-1);
	}
	pdeq->head = pdeq->head->next;
	free(delNode);
	if (pdeq->head == NULL)
		pdeq->tail = NULL;
	else
		pdeq->head->prev = NULL;

	return data;
}

Data DQRemoveLast(Deque* pdeq)
{
	Node* delNode = pdeq->tail;
	Data data = delNode->data;
	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error");
		exit(-1);
	}
	pdeq->tail = pdeq->tail->prev;
	free(delNode);
	if (pdeq->tail==NULL)
		pdeq->head = NULL;
	else
		pdeq->tail->next = NULL;
	
	return data;
}

Data DQGetFirst(Deque* pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error");
		exit(-1);
	}
	return pdeq->head->data;
}

Data DQGetLast(Deque* pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error");
		exit(-1);
	}
	return pdeq->tail->data;
}
