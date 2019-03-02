#include "stdafx.h"
#include <stdlib.h>
#include <assert.h>

typedef struct LNode
{
	int nData;
	struct LNode *next;
}LinKList;


void ListInsert(LinKList *list, int i, int data)
{
	assert(list);
	LinKList *p,*node;
	p = list->next;
	int j = 1;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}

	if (p == NULL || j > i)
	{
		return;
	}

	node = (LinKList*)malloc(sizeof(LinKList));
	node->nData = data;

	node->next = p->next;
	p->next = node;
}


int _tmain(int argc, _TCHAR* argv[])
{
	LinKList *p = NULL;
	ListInsert(p, 3, 3);
	return 0;
}