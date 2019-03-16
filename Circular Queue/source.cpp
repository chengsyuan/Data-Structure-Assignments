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
} Circular_Queue;

int convertIndex(int index, int queue_size) {
	return (index + queue_size) % queue_size;
}

int incIndex(int index, int queue_size) {
	index++;
	index = convertIndex(index, queue_size);

	return index;
}

int sizeOfQueue(Circular_Queue * queue) {
	return (queue->end - queue->front + queue->max_size) % queue->max_size;
}

int enQueue(Circular_Queue *queue, int value) {
	if (sizeOfQueue(queue) == queue->max_size-1) {
		exit(OutOfIndex);
	}

	queue->elem[queue->end] = value;
	queue->end = incIndex(queue->end, queue->max_size);

	return Ok;
}

int deQueue(Circular_Queue *queue) {
	if (sizeOfQueue(queue) == 0) {
		exit(OutOfIndex);
	}

	queue->front = incIndex(queue->front, queue->max_size);

	return Ok;
}

int printQueue(Circular_Queue * queue) {
	for (int i = queue->front; i != queue->end; i = incIndex(i ,queue->max_size))
	{
		printf("%d ", queue->elem[i]);
	}

	printf("\n");
	return Ok;
}


int test_queue() {
	Circular_Queue q;
	enQueue(&q, 1);
	enQueue(&q, 2);
	enQueue(&q, 3);
	enQueue(&q, 4);
	printQueue(&q);
	printf("size = %d\n", sizeOfQueue(&q));

	deQueue(&q);
	deQueue(&q);
	deQueue(&q);
	deQueue(&q);
	printQueue(&q);
	printf("size = %d\n\n", sizeOfQueue(&q));

	enQueue(&q, 1);
	enQueue(&q, 2);
	enQueue(&q, 3);
	enQueue(&q, 4);
	printQueue(&q);
	printf("size = %d\n", sizeOfQueue(&q));

	printf("front = %d, end = %d \n", q.front, q.end);
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
