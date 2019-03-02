#include "stdafx.h"
#include <stdlib.h>
#include <assert.h>

typedef struct LNode
{
	int nData;
	struct LNode *next;
}LinKList;


void ClearList(LinKList *list)
{
	assert(list);
	LinKList *p,*q;
	p = list->next;
	while (p)
	{
		q = p->next;
		free(p);
		p=q;
	}

	list->next = NULL;
}


int _tmain(int argc, _TCHAR* argv[])
{
	LinKList *p = NULL;
	ClearList(p);
	return 0;
}