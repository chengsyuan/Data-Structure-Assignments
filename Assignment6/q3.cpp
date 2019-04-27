
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

struct tree {
	int r;
	int n;
	int parent[MAX_SIZE];
};

int height(tree t, int id) {
	if (id == t.r)
	{
		return 0;
	}

	return height(t, t.parent[id]) + 1;
}

int main()
{
	tree t = {
		0, 10,
		{-1 ,0,0,0,1,1,3,6,6,6}
	};

	int h = 0;
	for (int i = 0; i < t.n; i++)
	{
		int hh = height(t, i);
		if (hh > h)
		{
			h = hh;
		}
	}

	printf("%d\n", h);
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