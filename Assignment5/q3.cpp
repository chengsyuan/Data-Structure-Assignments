// data_structure_assignment.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
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

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ������ʾ: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�