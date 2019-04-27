
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

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ������ʾ: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�