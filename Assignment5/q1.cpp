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


#define MAX_SIZE 100

typedef struct {
	/*从0编号到n-1*/
	char elem[MAX_SIZE];
	int size = 0;
	int max_size = MAX_SIZE;
} CharStack;

int popCharStack(CharStack* stack) {
	if (stack->size == 0) {
		exit(OutOfIndex);
	}

	stack->size--;

	return stack->elem[stack->size];
}

int pushCharStack(CharStack* stack, char value) {
	if (stack->size == stack->max_size) {
		exit(OutOfIndex);
	}

	stack->elem[stack->size++] = value;

	return Ok;
}

typedef struct {
	/*从0编号到n-1*/
	char elem[MAX_SIZE];
	int head = 0;
	int tail = 0;
	int max_size = MAX_SIZE;
} CharQueue;

int deCharQueue(CharQueue* queue) {
	if (queue->head == queue->tail) {
		exit(OutOfIndex);
	}

	return queue->elem[queue->head++];
}

int enCharQueue(CharQueue* queue, char value) {
	if (queue->tail == queue->max_size - 1) {
		exit(OutOfIndex);
	}

	queue->elem[queue->tail++] = value;

	return Ok;
}

int getOperatorPriority(char ch) {
	if (ch == '+' || ch == '-')
		return 1;

	if (ch == '*' || ch == '/')
		return 5;

	if (ch == '(')
		return -1000;

	exit(TestFailed);
}

int test_expreesion_to_reverse_polish() {
	CharStack stack;
	CharQueue queue;

	char str[] = "(a+b)*(c+d)/q";//"(a+b)*c*(d+e)+f";//"a+b*(c+d)+e+f";
	printf("%s\n", str);

	for (int i = 0; i < strlen(str); i++)
	{
		char ch = str[i];

		if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z'))
		{
			enCharQueue(&queue, ch);
		}
		else {
			if (ch == '(')
			{
				// nop
			}
			else if (ch == ')')
			{
				char t;

				while ((t = popCharStack(&stack)) != '(')
				{
					enCharQueue(&queue, t);
				}

				continue; // pass push ) into stack
			}
			else {
				while (stack.size && getOperatorPriority(stack.elem[stack.size - 1]) > getOperatorPriority(ch))
				{
					enCharQueue(&queue, popCharStack(&stack));
				}

			}

			pushCharStack(&stack, ch);
		}
	}


	while (stack.size)
		enCharQueue(&queue, popCharStack(&stack));


	while (queue.head != queue.tail)
	{
		printf("%c", deCharQueue(&queue));
	}

	return Ok;
}

int main()
{
	test_expreesion_to_reverse_polish();
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