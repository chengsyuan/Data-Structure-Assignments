
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

struct arc {
	int vex;
	arc* nextarc;
};

struct Graph {
	int vexnum = 0;
	int arcnum = 0;

	arc* firstarc[MAX_SIZE];
};

void initGraph(Graph& g) {
	memset(&g, 0, sizeof(g));
}

void addarc(Graph& g, int i, int j) {
	arc* t = (arc*)malloc(sizeof(arc));

	t->nextarc = g.firstarc[i];
	g.firstarc[i] = t;

	t->vex = j;

}

int main()
{
	Graph g;
	initGraph(g);


	printf("�����붥����:");
	scanf("%d", &g.vexnum);
	printf("���������:");
	scanf("%d", &g.arcnum);

	for (int i = 0; i < g.arcnum; i++)
	{
		int s, e;
		printf("��������ʼ����ͽ�������:");
		scanf("%d %d", &s, &e);
		addarc(g, s, e);
		addarc(g, e, s);
	}

	int cnt = 0;
	int q[MAX_SIZE] = { 0 }, head = 0, tail = 0;
	q[tail++] = 1;
	int vis[MAX_SIZE] = { 0 };

	int t;
	while (head < tail)
	{
		t = q[head++];

		arc* p = g.firstarc[t];
		if (!vis[t])
		{
			cnt++;
			vis[t]++;

		}
		else
		{
			continue;
		}
		
		

		while (p)
		{
			q[tail++] = p->vex;
			p = p->nextarc;
		}
	}

	if (cnt == g.vexnum)
	{
		printf("\n����ͨͼ\n");
	}
	else {
		printf("\n������ͨͼ\n");
	}
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