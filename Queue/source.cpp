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
	int front = 0;
	int end = 0;
	int max_size = MAX_SIZE;
} Queue;

int enQueue(Queue *queue, int value) {
	if (queue->front == queue->max_size || queue->end == queue->max_size) {
		exit(OutOfIndex);
	}

	queue->elem[queue->end++] = value;

	return Ok;
}

int deQueue(Queue *queue) {
	if (queue->front == queue->max_size || queue->end == queue->max_size) {
		exit(OutOfIndex);
	}

	queue->front ++;

	return Ok;
}

int printQueue(Queue * queue) {
	for (int i = queue->front; i < queue->end; i++)
	{
		printf("%d ", queue->elem[i]);
	}

	printf("\n");
	return Ok;
}

int sizeOfQueue(Queue * queue) {
	return queue->end - queue->front;
}

int test_queue() {
	Queue q;
	enQueue(&q, 1);
	enQueue(&q, 2);
	enQueue(&q, 3);
	printQueue(&q);
	printf("size = %d\n", sizeOfQueue(&q));

	deQueue(&q);
	printQueue(&q);
	printf("size = %d\n", sizeOfQueue(&q));

	return Ok;
}

int main()
{
	test_queue();
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
