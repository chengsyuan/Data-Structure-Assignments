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
	double elem[MAX_SIZE];
	int size = 0;
	int max_size = MAX_SIZE;
} SeqStack;

int popStack(SeqStack *stack) {
	if (stack->size == 0) {
		exit(OutOfIndex);
	}

	stack->size--;

	return stack->elem[stack->size];
}

int pushStack(SeqStack *stack, double value) {
	if (stack->size == stack->max_size) {
		exit(OutOfIndex);
	}

	stack->elem[stack->size++] = value;

	return Ok;
}

int printStack(SeqStack *stack) {
	for (int i = 0; i < stack->size; i++)
	{
		printf("%lf ", stack->elem[i]);
	}

	printf("\n");
	return Ok;
}

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

int getOperatorPriority(char ch) {

	if (ch == '+' || ch == '-')
		return 1;

	if (ch == '*' || ch == '/')
		return 5;

	if (ch == ')')
		return 10;

	if (ch == '(')
		return -10;

	exit(TestFailed);
}

int test_expreesion_to_reverse_polish() {
	SeqStack v_stack;
	CharStack c_stack;

	char str[] = "1 + 2 * 3 * ( 4 + 5 ) + 6 ";

	int value = 0;
	bool isFirst = true;

	for (char i = 0; i < strlen(str); i++)
	{
		char ch = str[i];
		if (ch == ' ')
		{
			// push stack
			pushStack(&v_stack, (double)value);
			//printf("value = %d\n", value);
			value = 0;
		}
		else if ('0' <= ch && ch <= '9')
		{
			// read in value
			value *= 10;
			value += ch - '0';
		}
		else {
			// operate
			i++;

			pushCharStack(&c_stack, ch);
			if (v_stack.size == 1) {
				continue;
			}

			if (ch == '(') {
				//啥也不干
				continue;
			}

 			if (ch == ')') {
				char ch_top = c_stack.elem[c_stack.size - 1];

				popCharStack(&c_stack);

				while ((ch_top = c_stack.elem[c_stack.size - 1])!='(')
				{
					if (isFirst) {
						double a = popStack(&v_stack);
						double b = popStack(&v_stack);

						printf("%.2lf %.2lf %c ", a, b, ch_top);

						isFirst = false;
					}
					else
					{
						double a = popStack(&v_stack);

						printf("%.2lf %c ", a, ch_top);
					}


					popCharStack(&c_stack);
				}
				
				popCharStack(&c_stack);
				continue;
			}


			while (true) {

				char ch_top = c_stack.elem[c_stack.size - 1];
				char ch_top_m_1 = c_stack.elem[c_stack.size - 2];

				if (getOperatorPriority(ch_top) < getOperatorPriority(ch_top_m_1)) {

					isFirst = false;

					if (isFirst) {
						double a = popStack(&v_stack);
						double b = popStack(&v_stack);

						printf("%.2lf %.2lf %c ", a, b, ch_top_m_1);

					}
					else
					{
						double a = popStack(&v_stack);

						printf("%.2lf %c ", a, ch_top_m_1);
					}


					popCharStack(&c_stack);
					popCharStack(&c_stack);

					pushCharStack(&c_stack, ch);
				}
				else {
					break;
				}
			}

		}
	}

	while (c_stack.size)
	{
		if (isFirst) {
			isFirst = false;
			char ch = popCharStack(&c_stack);
			double a = popStack(&v_stack);
			double b = popStack(&v_stack);

			printf("%.2lf %.2lf %c ", a, b, ch);

		}
		else {
			char ch = popCharStack(&c_stack);
			double a = popStack(&v_stack);

			printf(" %.2lf %c", a, ch);
		}

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