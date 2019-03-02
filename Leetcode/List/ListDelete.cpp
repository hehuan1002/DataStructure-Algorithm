#include "stdafx.h"
#include <stdlib.h>
#include <assert.h>

typedef struct LNode
{
	int nData;
	struct LNode *next;
}LinKList;

void ListDelete(LinKList *list,int i,int *data) 
{
	assert(list);
	LinKList *p,*q;
	p = list;
	int j = 1;
	while (p->next)
	{
		p = p->next;
		++j;
	}

	if (NULL == p->next || j > i)
	{
		return;
	}

	q = p->next;
	p->next = q->next;
	*data = q->nData;
	free(q);
}

int _tmain(int argc, _TCHAR* argv[])
{
	LinKList *p = NULL;
	int data;
	ListDelete(p, 3, &data);
	return 0;
}