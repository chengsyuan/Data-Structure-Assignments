// data_structure_assignment.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
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
	/*��0��ŵ�n-1*/
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
	/*��0��ŵ�n-1*/
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

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ������ʾ: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�