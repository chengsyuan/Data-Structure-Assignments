// data_structure_assignment.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define Ok 0x01
#define MemoryOverFlow 0x02
#define OutOfIndex 0x03

#define TestFailed 0xfff


#define MAX_SIZE 10

typedef struct {
	int i, j;
	int value;
} Triple;

typedef struct {
	/* subscipt from 0 to n-1 */
	Triple elem[MAX_SIZE];

	int m ,n;
	int len = 0;
} Matrix;

void printMatrix(Matrix m) {
	int cur = 0;
	for (int i = 0; i < m.m; i++)
	{
		for (int j = 0; j < m.n; j++)
		{
			if (m.elem[cur].i == i && m.elem[cur].j == j) {
				printf("%d ", m.elem[cur].value);
				cur++;
			}
			else
			{
				printf("%d ", 0);
			}
			
		}
		printf("\n");
	}
	printf("\n");
}

Matrix addMatrix(Matrix m, Matrix n) {
	if (m.m != n.m || m.n != n.n)
	{
		exit(OutOfIndex);
	}

	Matrix t;
	t.m = m.m, t.n = m.n;
	
	int curm = 0, curn = 0;
	while (curm < m.len && curn < n.len)
	{
		Triple a = m.elem[curm];
		Triple b = n.elem[curm];
		if (a.i < b.i || a.i == b.i && a.j < b.j) {
			t.elem[t.len++] = a;
			curm++;
			continue;

		}
		else if (a.i == b.i && a.j == b.j)
		{
			t.elem[t.len++] = { a.i, a.j ,a.value + b.value };
			curm++;
			curn++;
			continue;

		}
		else if (a.i > b.i || a.i == b.i && a.j > b.j)
		{
			t.elem[t.len++] = b;
			curn++;
			continue;

		}
		
		exit(TestFailed);
	}

	/*concat remain elems*/
	while (curm < m.len)
	{
		Triple a = m.elem[curm];
		t.elem[t.len++] = a;
		curm++;
	}

	while (curn < n.len)
	{
		Triple a = n.elem[curn];
		t.elem[t.len++] = a;
		curn++;
	}
	return t;
}

bool isBigger(Triple a, Triple b) {
	if (a.i == b.i)
	{
		return a.j < b.j;
	}

	return a.i < b.i;
}

Matrix transposeMatrix(Matrix m) {
	Matrix t;
	t.m = m.n, t.n = m.m;

	for (int i = 0; i < m.len; i++)
	{
		Triple a = m.elem[i];
		t.elem[t.len++] = { a.j,a.i,a.value };
	}

	std::sort(t.elem, t.elem + t.len, isBigger);
	return t;
}

int testMatrix() {
	/* for brief, all the operation is not inplace operation*/

	Matrix m;
	m.m = 3, m.n = 4;
	m.elem[m.len++] = { 0, 0, 1 };
	m.elem[m.len++] = { 1, 1, 2 };
	m.elem[m.len++] = { 2, 2, 3 };
	printMatrix(m);


	Matrix n;
	n.m = 3, n.n = 4;
	n.elem[n.len++] = { 0, 0, 1 };
	n.elem[n.len++] = { 1, 1, 2 };
	n.elem[n.len++] = { 2, 2, 3 };
	n.elem[n.len++] = { 2, 3, 3 };
	printMatrix(n);

	Matrix t = addMatrix(m, n);
	printMatrix(t);

	t = transposeMatrix(t);
	printMatrix(t);
	return Ok;
}

int main()
{
	testMatrix();
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