
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <stack>

#define Ok 0x01
#define MemoryOverFlow 0x02
#define OutOfIndex 0x03

#define TestFailed 0xfff

#define MAX_SIZE 100


struct Node
{
	char c;
	Node* fc;
	Node* nb;
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

		root->fc = buildTreeByPreOrder(root->fc, s);
		root->nb = buildTreeByPreOrder(root->nb, s);
	}

	return root;
}

void inOrderBiTree(Node* root) {
	if (root)
	{
		inOrderBiTree(root->fc);
		printf("%c ", root->c);
		inOrderBiTree(root->nb);
		
	}
}

void countLeaf(Node* root, int &cnt) {

	if (root)
	{
		if (root->fc)
		{
			countLeaf(root->fc, cnt);
		}
		else
		{
			cnt += 1;
		}
		
		if (root->nb)
		{
			countLeaf(root->nb, cnt);
		}
		
	}
}

bool isFullBiTree(Node* root) {
	Node* p = root;
	Node* q[MAX_SIZE];

	int head, tail;
	head = tail = 0;

	int id[MAX_SIZE];
	int p_id;

	q[tail] = p;
	id[tail] = 1;
	tail++;

	int cnt = 0;
	while (head < tail) {
		p = q[head];
		p_id = id[head];
		head++;

		if (p)
		{
			cnt++;
		}

		if (p_id != cnt)
		{
			return false;
		}

		if (p->fc)
		{
			q[tail] = p->fc;
			id[tail] = p_id * 2;
			tail++;
		}

		if (p->nb)
		{
			q[tail] = p->nb;
			id[tail] = p_id * 2 + 1;
			tail++;
		}

	}

	return true;
}

int main()
{
	
	Node* rt = (Node*)NULL;
	rt = buildTreeByPreOrder(rt, "ab#e##c##"); // "ab#c#d##ef##gh#ij#####"

	inOrderBiTree(rt);
	printf("\n");

	int cnt = 0;
	countLeaf(rt, cnt);
	printf("leaf=%d\n", cnt);

	printf("isFullBiTree=%d\n", isFullBiTree(rt));
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