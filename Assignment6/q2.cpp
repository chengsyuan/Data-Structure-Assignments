
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


	printf("请输入顶点数:");
	scanf("%d", &g.vexnum);
	printf("请输入边数:");
	scanf("%d", &g.arcnum);

	for (int i = 0; i < g.arcnum; i++)
	{
		int s, e;
		printf("请输入起始顶点和结束顶点:");
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
		printf("\n是连通图\n");
	}
	else {
		printf("\n不是连通图\n");
	}
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