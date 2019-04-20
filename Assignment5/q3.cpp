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


#define MAX_SIZE 6

struct Node {
	Node* l, * r;
	char c;
};

Node* buildTreeByPreOrder(Node* root, const char s[]) {
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



int sizeOfQueue(int head, int tail) {
	return (tail - head + MAX_SIZE) % MAX_SIZE;
}

void hierarchical_traverse(Node* rt) {
	Node* queue[MAX_SIZE];
	int h, t;
	h = t = 0;

	queue[t++] = rt;

	while (h != t) {
		Node* temp = queue[h];
		h = (h + 1) % MAX_SIZE;

		printf("%c ", temp->c);

		if (temp->l)
		{
			queue[t] = temp->l;
			t = (t + 1) % MAX_SIZE;
			if (sizeOfQueue(h, t) == MAX_SIZE - 1) {
				exit(MemoryOverFlow);
			}
		}

		if (temp->r)
		{
			queue[t] = temp->r;
			t = (t + 1) % MAX_SIZE;
			if (sizeOfQueue(h, t) == MAX_SIZE - 1) {
				exit(MemoryOverFlow);
			}
		}
	}

	return;
}


int get_max_width(Node* rt) {

	int max = 0;
	int size_of_layer[MAX_SIZE] = { 0 };

	Node* queue[MAX_SIZE];
	int dep[MAX_SIZE];

	int h, t;
	h = t = 0;

	dep[t] = 0;
	queue[t++] = rt;

	while (h != t) {
		Node* temp = queue[h];
		int temp2 = dep[h];
		h = (h + 1) % MAX_SIZE;

		size_of_layer[temp2] ++;

		if (temp->l)
		{
			dep[t] = temp2 + 1;
			queue[t] = temp->l;
			t = (t + 1) % MAX_SIZE;
			if (sizeOfQueue(h, t) == MAX_SIZE - 1) {
				exit(MemoryOverFlow);
			}
		}

		if (temp->r)
		{
			dep[t] = temp2 + 1;
			queue[t] = temp->r;
			t = (t + 1) % MAX_SIZE;
			if (sizeOfQueue(h, t) == MAX_SIZE - 1) {
				exit(MemoryOverFlow);
			}
		}
	}

	for (int i = 0; i < MAX_SIZE; i++)
	{
		max = max > size_of_layer[i] ? max : size_of_layer[i];
	}
	return max;
}

int testBiTree() {
	Node* rt = (Node*)NULL;
	rt = buildTreeByPreOrder(rt, "abd##eh##i##cf##g##");

	printf("hierarchical_traverse(rt) = ");
	hierarchical_traverse(rt);
	printf("\n");

	printf("get_max_width(rt) = %d\n", get_max_width(rt));
	
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