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
#define MAX 0xffff


int main()
{
	int m = 3, n = 5;
	int e[3][5] = { {0, 1, 2, 3, 4}, 
					{5, 6, 3, 3, 4}, 
					{5, 5, 3, 1, 4} };

	// find minimum of each row
	int min[3];
	for (int i = 0; i < m; i++) min[i] = MAX;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			min[i] = min[i] < e[i][j] ? min[i] : e[i][j];
		}

	// find maximum of each column
	int max[5];
	for (int i = 0; i < n; i++) max[i] = -MAX;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			max[j] = max[j] > e[i][j] ? max[j] : e[i][j];
		}

	// find saddle point
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			if (max[j] == min[i])
			{
				printf("%d on (%d,%d) is saddle point\n", e[i][j], i + 1, j + 1);
			}
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