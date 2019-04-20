#include "stdafx.h"


/*********************
   ���������Ƕ�ð�������һ�ָĽ������Ļ���˼���ǣ�ͨ��һ�����򽫴��ż�¼�ָ�ɶ������������֣�����һ���ּ�¼�Ĺؼ��־�����һ���ּ�¼��
�ؼ���С����ɷֱ���������ּ�¼�������������Դﵽ������������
   ��������������Ϊ{L.r[s],L.r[s+1],......,L.r[t]}����������ѡȡһ����¼��ͨ����ѡ��һ����¼L.r[s]����Ϊ��(shu)�ᣨ��֧�㣩(pivot)��
Ȼ������ԭ���������������¼�������йؼ��ֽ���С�ļ�¼����������λ��֮ǰ�������йؼ��ֽ�����ļ�¼������������λ��֮���ɴ˿��Ըá����ᡱ
��¼��������λ��i���ֽ��ߣ�������{L.r[s],L.[r+1],.....L.r[t]}�ָ������������{L.r[s],L.r[s+1],...,L.r[i-1]}��{L.r[i+1],L.r[i+2],...,L.[t]}��
������̳���һ�˿������򣨻�һ�λ��֣���
   һ�˿�������ľ��������ǣ���������ָ��low��high�����ǵĳ�ֵ�ֱ�Ϊlow��high���������¼�Ĺؼ���Ϊpivotkey�������ȴ�high��ָλ������ǰ�����ҵ�
��һ���ؼ���С��pivotkey�ļ�¼�������¼���ཻ����Ȼ���low��ָλ��������������ҵ���һ���ؼ���С��pivotkey�ļ�¼�������¼���ཻ����Ȼ���low
��ָλ��������������ҵ���һ���ؼ��ִ���pivotkey�ļ�¼�������¼���ཻ�����ظ�������ֱ��low==highΪֹ��
������������ԣ�������ѭ�����Ǳ���ģ�ֻ���ڲ�ѭ����Ҫ�ı�һ�£����Կ��������ʱ�临�Ӷ�ΪO(nlogn)���ռ临�Ӷ�ΪO(logn)��


********************/
#define MAXSIZE 9
typedef struct
{
	int r[MAXSIZE];
	int length;
}Sqlist;

void swap(Sqlist *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}

void Init(Sqlist *L)
{
	L->r[0] = 50;
	L->r[1] = 10;
	L->r[2] = 90;
	L->r[3] = 30;
	L->r[4] = 70;
	L->r[5] = 40;
	L->r[6] = 80;
	L->r[7] = 60;
	L->r[8] = 20;

	L->length = MAXSIZE;
}

int Partition(Sqlist& L, int low, int high)
{
	int Pivotkey = L.r[low]; // �±��Ӧ��ֵ
	while (low < high)
	{
		while (low < high && L.r[high] >= Pivotkey) --high;
		swap(&L, low, high);
		while (low < high && L.r[low] <= Pivotkey) ++low;
		swap(&L, low, high);
	}

	return low;
}

void QSort(Sqlist&L, int low, int high)
{
	if (low < high)
	{
		int pivot = Partition(L, low, high);
		QSort(L, low, pivot-1);// pivot���±�����ֵ
		QSort(L,pivot+1, high);
	}
}


void QuickSort(Sqlist &L)
{
	QSort(L, 0, L.length - 1);
}
int _tmain(int argc, _TCHAR* argv[]){
	
	Sqlist L;
	Init(&L);

	// ����ǰ
	for (int i = 0; i < L.length; i++){
		printf("%d ", L.r[i]);
	}
	printf("\n");

	QuickSort(L);

	// �����
	for (int i = 0; i < L.length; i++){
		printf("%d ", L.r[i]);
	}
	printf("\n");

	return 0;
}