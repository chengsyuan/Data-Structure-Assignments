// data_structure_assignment.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"

#include <stdio.h>
#include <stdlib.h>

#define Ok 0x01
#define MemoryOverFlow 0x02
#define OutOfIndex 0x03

#define TestFailed 0xfff


#define MAX_SIZE 5
typedef struct {
	/*从0编号到n-1*/
	int elem[MAX_SIZE];
	int size = 0;
	int max_size = MAX_SIZE;
} SeqStack;

int popStack(SeqStack *stack) {
	if (stack->size == 0) {
		exit(OutOfIndex);
	}

	stack->size--;

	return Ok;
}

int pushStack(SeqStack *stack, int value) {
	if (stack->size == stack->max_size) {
		exit(OutOfIndex);
	}

	stack->elem[stack->size++] = value;

	return Ok;
}

int printStack(SeqStack *stack) {
	for (int i = 0; i < stack->size; i++)
	{
		printf("%d ", stack->elem[i]);
	}

	printf("\n");
	return Ok;
}


int test_seqstack() {
	SeqStack stack;

	pushStack(&stack, 1);
	pushStack(&stack, 2);
	popStack(&stack);
	pushStack(&stack, 3);
	printStack(&stack);
	return Ok;
}

int main()
{
	test_seqstack();
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
