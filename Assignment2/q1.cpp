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


#define MAX_SIZE 1000

typedef struct {
	/*从0编号到n-1*/
	char elem[MAX_SIZE];
	int size = 0;
	int max_size = MAX_SIZE;
} CharStack;

int popCharStack(CharStack *stack) {
	if (stack->size == 0) {
		exit(OutOfIndex);
	}

	stack->size--;

	return stack->elem[stack->size];
}

int pushCharStack(CharStack *stack, char value) {
	if (stack->size == stack->max_size) {
		exit(OutOfIndex);
	}

	stack->elem[stack->size++] = value;

	return Ok;
}

int isHuiwen(char str[]) {
	CharStack stack;

	bool meet_andchar = false;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '&')
		{
			meet_andchar = true;
			continue;
		}

		if (str[i] == '@')
		{
			// 栈不为空也不行
			if (stack.size != 0)
			{
				return 0;
			}

			break;
		}

		if (!meet_andchar)
		{
			pushCharStack(&stack, str[i]);
		}
		else {
			// 判断弹出的元素是否和当前字符相等
			if (str[i] != popCharStack(&stack))
			{
				return 0;
			}
		}

	}

	

	return 1;
}

int test_huiwen() {

	char str1[] = "a+b&b+a@";        
	printf("isHuiwen(%s) = %d\n", str1, isHuiwen(str1));

	char str2[] = "a+b&b-a@";
	printf("isHuiwen(%s) = %d\n", str2, isHuiwen(str2));

	return Ok;
}

int main()
{
	test_huiwen();
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