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
	int coefficient;
	int index;
	linkNode* next;
};

void msgBox(const char s[]) {
	/* show a message box */
	system("cls");
	printf("------------------------------------------\n\n%35s\n\n------------------------------------------\n\n", s);
	system("pause");
	system("cls");
	return;
}

void addLinkNode(linkNode* head, linkNode *node) {
	/* add LinkNode by ascending index order */
	if (head->next == NULL)
	{
		/* if null add first node */
		head->next = node;
		node->next = NULL;
	}
	else
	{
		linkNode* t = head->next;
		while (true)
		{
			/* not last */
			if (t->next && t->index <= node->index && node->index < t->next->index)
			{
				break;
			}

			/* last */
			if (!t->next && t->index <= node->index)
			{
				break;
			}
			t = t->next;
		}

		if (t->index == node->index)
		{
			/* update t */
			t->coefficient += node->coefficient;
		}
		else {
			/* insert after t */
			node->next = t->next;
			t->next = node;
		}
	}

	return;
}

char* getMultinomial(linkNode* head) {
	char str[MAXSIZE] = "";

	linkNode* t = head->next;
	bool isFirst = true;
	while (t)
	{
		if (isFirst)
		{
			isFirst = false;
		}
		else
		{
			strcat(str, "+");
		}

		if (t->index == 0)
		{
			char s[MAXSIZE];
			sprintf(s, "%d", t->coefficient);
			strcat(str, s);
		}
		else if (t->index == 1)
		{
			char s[MAXSIZE];
			sprintf(s, "%dx", t->coefficient);
			strcat(str, s);
		}
		else
		{
			char s[MAXSIZE];
			sprintf(s, "%dx^%d", t->coefficient, t->index);
			strcat(str, s);
		}

		t = t->next;
	}

	return str;
}

linkNode* createMultinomial() {
	linkNode* head = (linkNode*)malloc(sizeof(linkNode));
	head->coefficient = 0, head->index = 0, head->next = NULL;

	system("cls");
	printf("\n\n请以元组的形式输入多项式的指数和系数\n\n例如:(0,1),(1,10),(2,20)\n它的含义是1+10x+20x^2\n\n");

	char str[MAXSIZE], t;
	scanf("%s", str);
	/* iterate the str and find all tuples */
	for (int i = 0; t = str[i]; i++) {
		/* if not new tuple then continue*/
		if (t != '(')
		{
			continue;
		}

		/* string to int */
		int index, coefficient;
		sscanf(str + i, "(%d,%d)", &index, &coefficient);

		/* add linkNode */
		linkNode* node = (linkNode*)malloc(sizeof(linkNode));
		node->index = index, node->coefficient = coefficient, node->next = NULL;
		addLinkNode(head, node);
	}

	char str2[MAXSIZE];
	sprintf(str2, "从%s创建的%s\n此多项式已经被存储到带表头结点的单链表", str, getMultinomial(head));
	msgBox(str2);

	return head;
}

void reverseMultinomial(linkNode* head) {
	linkNode* t = head->next, *p = NULL;
	head->next = NULL;

	while (t)
	{
		p = t->next;
		t->next = head->next;
		head->next = t;

		t = p;
	}
	return;
}

int calMultinomial(linkNode* head) {
	system("cls");
	printf("\n\n请输入x的值\n\n");

	int x;
	scanf("%d", &x);

	linkNode* t = head->next;

	int ans = 0;
	while (t)
	{

		/* o(lg n) << o(n) 高效方法 */
		int tmp = t->index, tot = 1, base = x;
		while (tmp)
		{
			if (tmp % 2) tot *= base;

			base *= base;
			tmp /= 2;
		}
		ans += tot * t->coefficient;


		t = t->next;
	}
	return ans;
}

linkNode* addMultinomial(linkNode* h1, linkNode* h2) {
	/* retrun a new mm */
	linkNode* head = (linkNode*)malloc(sizeof(linkNode));
	head->coefficient = 0, head->index = 0, head->next = NULL;

	/* add h1 to new mm */
	linkNode* t = h1->next;
	while (t)
	{
		/* cpy node to a new mem addr */
		linkNode* t_ = (linkNode*)malloc(sizeof(linkNode));
		memcpy(t_, t, sizeof(linkNode));
		addLinkNode(head, t_);
		t = t->next;
	}

	/* add h2 to new mm */
	t = h2->next;
	while (t)
	{
		/* cpy node to a new mem addr */
		linkNode* t_ = (linkNode*)malloc(sizeof(linkNode));
		memcpy(t_, t, sizeof(linkNode));
		addLinkNode(head, t_);
		t = t->next;
	}

	return head;
}

void showMenu() {
	char menu_option;
	linkNode* t1 = NULL, * t2 = NULL, * t3 = NULL;
	char str[MAXSIZE];
	int ans = 0;

	do
	{
		/* header menu */
		printf("        第一次上机作业\n\n");
		printf("应承轩 电计1701 201785071\n");
		printf("------------------------------------------\n\n");


		/* menu */
		printf("主菜单\n");
		printf("a. 建立带表头结点的单链表存放一元多项式（按照指数升序排列）\n");
		printf("b. 输出一元多项式的所有数据元素(按照指数升序输出每一系数非0项的系数和指数)\n");
		printf("c. 将单链表存放的一元多项式就地逆置，变成按照指数降序排列\n");
		printf("d. 输入自变量的值，计算一元多项式的值（设计高效算法）\n");
		printf("e. 求2个一元多项式的和多项式\n");
		printf("f. 附加题：3个递增有序的单链表A,B,C，在A表中删除同时出现在B和C中的数据元素\n");
		printf("q. 退出\n");
		printf(" 请输入a-f选择，或者q退出: ");

		/* input */
		while (menu_option = getchar())
		{
			if(menu_option >= 'a' && menu_option <= 'z')
				break;
		}

		switch (menu_option) {
		case 'a':
			t1 = createMultinomial();
			break;

		case 'b':
			if (t1 == NULL)
			{
				msgBox("请先执行a命令       ");
				break;
			}
			sprintf(str, "您在a中创建的一元多项式为:\n%s", getMultinomial(t1));
			msgBox(str);
			break;

		case 'c':
			if (t1 == NULL)
			{
				msgBox("请先执行a命令       ");
				break;
			}
			reverseMultinomial(t1);
			sprintf(str, "执行反转之后为:\n%s", getMultinomial(t1));
			msgBox(str);
			break;

		case 'd':
			if (t1 == NULL)
			{
				msgBox("请先执行a命令       ");
				break;
			}
			sprintf(str, "一元多项式的值:%d", calMultinomial(t1));
			msgBox(str);
			break;

		case 'e':
			msgBox("您现在需要重新输入两个多项式!");
			t1 = createMultinomial();
			t2 = createMultinomial();
			t3 = addMultinomial(t1, t2);

			sprintf(str, "2个一元多项式的和多项式 = \n (%s)", getMultinomial(t3));
			msgBox(str);
			break;

		case 'q':
			/* exit */
			return;

		default:
			/* show info */
			msgBox("请输入a-f选择，或者q退出!");
			break;
		}

	} while (true);
}

int main()
{
	showMenu();
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