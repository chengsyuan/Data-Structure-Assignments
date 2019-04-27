
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <stack>

#define Ok 0x01
#define MemoryOverFlow 0x02
#define OutOfIndex 0x03

#define TestFailed 0xfff

#define MAX_SIZE 100

struct tree {
	int r;
	int n;
	int parent[MAX_SIZE];
};

int height(tree t, int id) {
	if (id == t.r)
	{
		return 0;
	}

	return height(t, t.parent[id]) + 1;
}

int main()
{
	tree t = {
		0, 10,
		{-1 ,0,0,0,1,1,3,6,6,6}
	};

	int h = 0;
	for (int i = 0; i < t.n; i++)
	{
		int hh = height(t, i);
		if (hh > h)
		{
			h = hh;
		}
	}

	printf("%d\n", h);
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