// data_structure_assignment.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
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

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ������ʾ: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�