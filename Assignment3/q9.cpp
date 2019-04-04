// data_structure_assignment.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <stack>

#define Ok 0x01
#define MemoryOverFlow 0x02
#define OutOfIndex 0x03

#define TestFailed 0xfff


#define MAX_SIZE 10

struct Node{
	Node *l, *r;
	char c;
};

Node * buildTreeByPreOrder(Node *root, const char s[]) {
	static int cnt = 0;
	//printf("%d ", cnt);
	if (cnt == -1)
	{
		return NULL;
	}
	if (!s[cnt])
	{
		cnt = -1;
		return NULL;
	}

	if (s[cnt] == '#') {
		root = (Node *)NULL;
		cnt++;
	}
	else
	{
		root = (Node *)malloc(sizeof(Node));
		root->c = s[cnt];
		cnt++;

		root->l = buildTreeByPreOrder(root->l, s);
		root->r = buildTreeByPreOrder(root->r, s);
	}

	return root;
}


Node* findx(Node* root, char c) {
	Node* st[MAX_SIZE]; int top = 0; /* a easy stack */

	/* preOrder */
	st[top++] = root;
	Node* p = NULL;
	while (top)
	{
		p = st[--top];
		while (p) {
			if (p->c == c) return p; /* find */

			if (p->r) st[top++] = p->r;
			p = p->l;
		}
	}

	return NULL; /* not find */
}


int testBiTree() {
	Node *rt = (Node *)NULL;

	rt = buildTreeByPreOrder(rt, "abd##eh##i##cf##g##");

	printf("%d", (int)findx(rt, 'h'));
	return Ok;
}


int main()
{
	testBiTree();
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