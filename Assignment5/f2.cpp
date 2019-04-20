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

#define MAX_SIZE 9

int main()
{
	int arr[MAX_SIZE] = { 1, 2, 3, 4 ,5,6,7,8 ,9 }, temp = 0;
	int k = 133;

	k %= MAX_SIZE;

	int nx = 0;
	for (int i = 0; i <= MAX_SIZE; i++)
	{
		if (!i)
		{
			// init the nx pointer
			temp ^= arr[nx];
			nx = (nx + k) % MAX_SIZE;
		}
		else
		{
			temp ^= arr[nx];
			arr[nx] ^= temp;
			temp ^= arr[nx];

			nx = (nx + k) % MAX_SIZE;
		}
		

	}


	for (int i = 0; i < MAX_SIZE; i++)
	{
		printf("%d ", arr[i]);
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