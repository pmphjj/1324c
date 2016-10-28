// 1324c.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stdio.h"
#include "malloc.h"
#include "stdlib.h"


typedef struct Lnode
{
	int data;
	struct Lnode *next;
}Lnode;


Lnode * Insert(Lnode * L, int a);
void PrintfList(Lnode * L);
void FreeList(Lnode * L);

int _tmain(int argc, _TCHAR* argv[])
{
	Lnode * La, *Lb, *Lc, *p, *q, *r;
	La = (Lnode*)malloc(sizeof(Lnode));
	La->next = NULL;
	p = La;
	Lb = (Lnode*)malloc(sizeof(Lnode));
	Lb->next = NULL;
	q = Lb;
	Lc = (Lnode*)malloc(sizeof(Lnode));
	Lc->next = NULL;

	int INPUT, sum = 0, Sign = 1;
	while (scanf_s("%d", &INPUT) != EOF)
	{
		//if (INPUT <= 0 || INPUT > 100)//�ж����������Ƿ�Ϊ�Ϸ���
		//{
		//	printf("INPUT ERROR.\n");
		//	return 1;
		//}
		if (sum <= 0) //�����һ������ ��ʾ�ܸ���
		{
			sum = INPUT;
		}
		else //��������
		{	//������
			r = (Lnode*)malloc(sizeof(Lnode));
			r->next = NULL;
			r->data = INPUT;
			if (Sign == 1)
			{
				p->next = r;
				p = p->next;
			}
			else
			{
				q->next = r;
				q = q->next;
			}
			sum--;//������� ʣ������-1
			if (sum == 0 && Sign == 1)
			{
				Sign = 2;
			}
			else if (sum == 0 && Sign == 2)//�ڶ���Ҳ������� ׼�����
			{
				Sign = 1;
				p = La; q = Lb; r = Lc;
				while (p->next != NULL && q->next != NULL)
				{
					if (p->next->data < q->next->data) {
						r = Insert(Lc,p->next->data);
						p = p->next;
					}
					else
					{
						r = Insert(Lc,q->next->data);
						q = q->next;
					}
				}
				if (p->next != NULL) {
					r->next = p->next; p->next = NULL;
				}
				if (q->next != NULL) {
					r->next = q->next; q->next = NULL;
				}
				PrintfList(Lc);
				FreeList(La);
				FreeList(Lb);
				FreeList(Lc);
				p = La;
				q = Lb;
			}

		}
	}
	return 0;
}

Lnode * Insert(Lnode * L, int a)
{
	Lnode *p, *q;
	p = L;
	while (p->next != NULL) p = p->next;
	q = (Lnode*)malloc(sizeof(Lnode));
	q->next = NULL;
	q->data = a;
	p->next = q;
	return q;
}

void PrintfList(Lnode * L)
{
	Lnode *p = L;
	while (p->next != NULL) {
		printf("%d", p->next->data);
		if (p->next->next != NULL) printf(" ");
		p = p->next;
	}
	//printf("error.");
	printf("\n");
}

void FreeList(Lnode * L)
{
	Lnode * p, *q;
	p = L->next;
	while (p != NULL) {
		q = p;
		L->next = p->next;
		free(q);
		p = L->next;
	}
}