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

#define k 6
#define MAX_SIZE k


int sizeOfQueue(int head, int tail) {
	return (tail - head + MAX_SIZE) % MAX_SIZE;
}


int main()
{

	int max = 44;

	int queue[MAX_SIZE] = {0};
	int h, t;
	h = t = 0;

	queue[t++] = 0;
	queue[t++] = 1;

	while (true) {
		int a = queue[h];
		h = (h + 1) % MAX_SIZE;

		int b = queue[h];
		
		if (a + b > max)
		{
			break;
		}

		queue[t] = a + b;
		t = (t + 1) % MAX_SIZE;
	}

	// print process


	for (int i = 0; i < MAX_SIZE; i++)
	{
		printf("%d ", queue[i]);
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