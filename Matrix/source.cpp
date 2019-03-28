// data_structure_assignment.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Ok 0x01
#define MemoryOverFlow 0x02
#define OutOfIndex 0x03

#define TestFailed 0xfff


#define MAX_SIZE 10
typedef struct {
	/*从0编号到n-1*/
	int elem[MAX_SIZE][MAX_SIZE] = {0};
	int m ,n;
} Matrix;

void printMatrix(Matrix m) {
	for (int i = 0; i < m.m; i++)
	{
		for (int j = 0; j < m.n; j++)
		{
			printf("%d ", m.elem[i][j]);
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
	for (int i = 0; i < m.m; i++)
	{
		for (int j = 0; j < m.n; j++)
		{
			t.elem[i][j] = m.elem[i][j] + n.elem[i][j];
		}
	}
	return t;
}

Matrix multiplyMatrix(Matrix m, Matrix n) {
	if (m.n != n.m)
	{
		exit(OutOfIndex);
	}

	Matrix t;
	t.m = m.m, t.n = n.n;
	for (int i = 0; i < m.m; i++)
	{
		for (int j = 0; j < n.n; j++)
		{
			for (int k = 0; k < m.n; k++)
			{
				t.elem[i][j] += m.elem[i][k] * n.elem[k][j];
			}
			
		}
	}
	return t;
}

int testMatrix() {
	/* for brief, all the operation is not inplace operation*/

	Matrix m;
	m.m = 3, m.n = 4;
	m.elem[0][0] = 1, m.elem[0][1] = 2, m.elem[0][2] = 3, m.elem[0][3] = 4;
	m.elem[1][0] = 0, m.elem[1][1] = 1, m.elem[1][2] = 2, m.elem[1][3] = 3;
	m.elem[2][0] = 0, m.elem[2][1] = 0, m.elem[2][2] = 1, m.elem[2][3] = 2;
	printMatrix(m);

	Matrix n;
	n.m = 3, n.n = 4;
	n.elem[0][0] = 1, n.elem[0][1] = 1, n.elem[0][2] = 1, n.elem[0][3] = 1;
	n.elem[1][0] = 0, n.elem[1][1] = 1, n.elem[1][2] = 1, n.elem[1][3] = 1;
	n.elem[2][0] = 0, n.elem[2][1] = 0, n.elem[2][2] = 1, n.elem[2][3] = 1;
	printMatrix(n);

	Matrix t = addMatrix(m, n);
	printMatrix(t);

	Matrix e;
	e.m = 4, e.n = 4;
	e.elem[0][0] = 1, e.elem[0][1] = 0, e.elem[0][2] = 0, e.elem[0][3] = 0;
	e.elem[1][0] = 0, e.elem[1][1] = 1, e.elem[1][2] = 0, e.elem[1][3] = 0;
	e.elem[2][0] = 0, e.elem[2][1] = 0, e.elem[2][2] = 1, e.elem[2][3] = 0;
	e.elem[3][0] = 0, e.elem[3][1] = 0, e.elem[3][2] = 0, e.elem[3][3] = 1;
	printMatrix(e);

	Matrix f = multiplyMatrix(m, e);
	printMatrix(f);

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