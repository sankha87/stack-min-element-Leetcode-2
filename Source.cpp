#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
	int data[1000];
	int top;
	//MinStack *link;
}MinStack;

MinStack* minStackCreate()
{
	MinStack *st = (MinStack*)malloc(sizeof(MinStack));
	memset(st->data, 0, sizeof(st->data));
	st->top = -1;
	return st;
}

void minStackPush(MinStack *obj, int x)
{
	if (obj->top != 999)
	{
		obj->top++;
		obj->data[obj->top] = x;
	}
//	obj->data[++obj->top] = x;
}

void minStackPop(MinStack *obj)
{
	int temp = obj->data[obj->top];
	obj->top--;
}

int minStackTop(MinStack* obj)
{
	return obj->data[obj->top];
}

int minStackGetMin(MinStack* obj)
{
	MinStack *s = obj;
	int n = s->top + 1;

	int temp = s->data[0];
	for (int j = 1; j < n; j++)
	{
		if (s->data[j] < temp)
			temp = s->data[j];
	}

	return temp;
}

void minStackFree(MinStack* obj)
{
	free(obj);
}

void main()
{
	MinStack *obj = minStackCreate();

	minStackPush(obj, -2);
	minStackPush(obj, 0);
	minStackPush(obj, -3);
	minStackPush(obj, -4);
	minStackPush(obj, 3);
	minStackPush(obj, -1);

	int m = minStackGetMin(obj);
	printf(" %d ", m);

	minStackPop(obj);
	minStackTop(obj);
	m = minStackGetMin(obj);
	printf(" %d ", m);

	minStackFree(obj);
	_getch();
}