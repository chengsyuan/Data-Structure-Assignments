// data_structure_assignment.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <stack>
#include <math.h>

#define Ok 0x01
#define MemoryOverFlow 0x02
#define OutOfIndex 0x03

#define TestFailed 0xfff


#define MAX_SIZE 10

struct Node {
	Node* l, * r;
	char c;

	int id;
};

Node* buildTreeByPreOrder(Node* root, const char s[], bool reset=false) {
	static int cnt = 0;
	if (reset)
	{
		cnt = 0;
	}

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
		root = (Node*)NULL;
		cnt++;
	}
	else
	{
		root = (Node*)malloc(sizeof(Node));
		root->c = s[cnt];
		cnt++;

		root->l = buildTreeByPreOrder(root->l, s);
		root->r = buildTreeByPreOrder(root->r, s);
	}

	return root;
}


bool isFullBiTree(Node * rt) {
	Node *queue[MAX_SIZE], *h;
	int head=0, tail=0; // an easy queue
	queue[tail++] = rt; // enqueue root

	rt->id = 1;// set root id to 1
	int last_id = 0; // this id should add 1 for each iteration

	while (head < tail)
	{
		h = queue[head++]; // pop head
		last_id++;

		if (last_id != h->id)
		{
			return false;
		}

		// enqueue left child
		Node* t = h->l;
		if (t)
		{
			queue[tail++] = t;
			t->id = h->id * 2;
		}

		// enqueue right child
		t = h->r;
		if (t)
		{
			queue[tail++] = t;
			t->id = h->id * 2 + 1;
		}
	}

	return true;
}


int testBiTree() {
	Node* rt = (Node*)NULL;

	rt = buildTreeByPreOrder(rt, "abd##e##c#f##", true);
	printf("%d\n", isFullBiTree(rt));

	rt = buildTreeByPreOrder(rt, "abd##e##cf###", true);
	printf("%d\n", isFullBiTree(rt));

	rt = buildTreeByPreOrder(rt, "abd##e##cf##g##", true);
	printf("%d\n", isFullBiTree(rt));
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