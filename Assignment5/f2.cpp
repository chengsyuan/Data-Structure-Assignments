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

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ������ʾ: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�