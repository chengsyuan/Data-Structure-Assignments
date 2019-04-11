// data_structure_assignment.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define Ok 0x01
#define MemoryOverFlow 0x02
#define OutOfIndex 0x03

#define TestFailed 0xfff
#define MAXSIZE 10000

struct linkNode{
	int value;
	linkNode* next;
};

void initNode(linkNode** A) {
	*A = (linkNode*)malloc(sizeof(linkNode));
	(*A)->next = NULL;
	(*A)->value = 0;
}

void addNodeToTail(linkNode* A, int value) {
	while (A->next)
	{
		A = A->next;
	}

	linkNode* t = NULL;
	initNode(&t);
	t->value = value;

	t->next = A->next;
	A->next = t;
}

void printLinkNode(linkNode* A) {
	printf("\n");
	while (A = A->next)
	{
		printf("%d ", A->value);
	}
	printf("\n");
}

void myDelete(linkNode* A, linkNode* B, linkNode* C) {
	linkNode* pa = A->next, * pre = A, *t = NULL;
	linkNode* pb = B->next;
	linkNode* pc = C->next;

	while (pa && pb && pc)
	{
		if (pb->value == pc->value) {
			int v = pb->value;
			while (pa && pa->value < v)
			{
				pre = pa;
				pa = pa->next;
			}

			if (pa->value == v)
			{
				/* if pa=tail */
				if (pa->next == NULL) {
					pre->next = NULL;
					return;
				}

				/* skip this */
				t = pa;
				pa = pa->next;
				pre->next = pa;

				free(t);
			}

			pb = pb->next;
			pc = pc->next;
		}
		else if (pb->value < pc->value)
		{
			pb = pb->next;
		}
		else if (pb->value > pc->value)
		{
			pc = pc->next;
		}
	}
}

int main()
{
	linkNode* A = NULL, * B = NULL, * C = NULL;
	initNode(&A), initNode(&B), initNode(&C);

	addNodeToTail(A, 1);
	addNodeToTail(A, 2);
	addNodeToTail(A, 3);
	addNodeToTail(A, 4);
	addNodeToTail(A, 5);

	addNodeToTail(B, 1);
	addNodeToTail(B, 3);
	addNodeToTail(B, 5);
	addNodeToTail(B, 6);

	addNodeToTail(C, 3);
	addNodeToTail(C, 4);
	addNodeToTail(C, 5);
	addNodeToTail(C, 6);

	printLinkNode(A);
	printLinkNode(B);
	printLinkNode(C);

	myDelete(A, B, C);

	printLinkNode(A);

	return Ok;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件