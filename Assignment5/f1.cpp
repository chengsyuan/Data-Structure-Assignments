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
#define MAX 0xffff


int main()
{
	int m = 3, n = 5;
	int e[3][5] = { {0, 1, 2, 3, 4}, 
					{5, 6, 3, 3, 4}, 
					{5, 5, 3, 1, 4} };

	// find minimum of each row
	int min[3];
	for (int i = 0; i < m; i++) min[i] = MAX;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			min[i] = min[i] < e[i][j] ? min[i] : e[i][j];
		}

	// find maximum of each column
	int max[5];
	for (int i = 0; i < n; i++) max[i] = -MAX;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			max[j] = max[j] > e[i][j] ? max[j] : e[i][j];
		}

	// find saddle point
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			if (max[j] == min[i])
			{
				printf("%d on (%d,%d) is saddle point\n", e[i][j], i + 1, j + 1);
			}
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