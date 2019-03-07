// data_structure_assignment.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"

#include <stdio.h>
#include <stdlib.h>

#define Ok 0x01
#define MemoryOverFlow 0x02
#define OutOfIndex 0x03

#define TestFailed 0xfff

#define LIST_INIT_SIZE 5

typedef struct{
	/*从1编号到n*/
	int *elem;
	int length;
	int max_size;
} SeqList;

int InitList(SeqList *L) {
	L->elem = (int *)malloc(LIST_INIT_SIZE * sizeof(int));
	if (!L->elem) exit(MemoryOverFlow);
	//printf("%d", L.elem);
	L->length = 0;
	L->max_size = LIST_INIT_SIZE;
	return Ok;
}

int ListInsert(SeqList *L, int index, int value) {
	/*插入到第x位前面(1<=x<=length+1)*/
	if (index<1 || index>L->length+1) {
		exit(OutOfIndex);
	}
	if (L->length >= L->max_size - 1)
	{
		int *new_addr = (int *)realloc(L->elem, L->max_size * 2 * sizeof(int));
		if (!new_addr)exit(MemoryOverFlow);

		L->elem = new_addr;
		L->max_size *= 2;
	}

	for (int i = L->length; i >= index; --i) {
		L->elem[i + 1] = L->elem[i];
	}

	L->elem[index] = value;
	L->length += 1;
	return Ok;
}

int OrderdListInsert(SeqList *L, int value) {
	/*用类C语言设计算法，在有序顺序表中插入新的数据x，要求插入后的线性表仍然有序*/
	if (L->length >= L->max_size - 1)
	{
		int *new_addr = (int *)realloc(L->elem, L->max_size * 2 * sizeof(int));
		if (!new_addr)exit(MemoryOverFlow);

		L->elem = new_addr;
		L->max_size *= 2;
	}

	int index = 0;
	/*列表下标从1到n*/
	for (int i = 2; i <= L->length; ++i) {
		if ((L->elem[i - 1] <= value && value <= L->elem[i]) || /*递增序*/
			(L->elem[i - 1] >= value && value >= L->elem[i])) { /*递减序*/
			index = i;
			break;
		}
		
	}

	/*把index+1的元素向后移*/
	for (int i = L->length; i >= index; --i) {
		L->elem[i + 1] = L->elem[i];
	}

	L->elem[index] = value;
	L->length += 1;
	return Ok;
}

int ReverseList(SeqList *L) {
	for (int i = 1; i <= L->length / 2; ++i) {
		int index1 = i;
		int index2 = L->length + 1 - index1;

		/*三变量法交换，用L->elem[0]当作临时空间，因为数组下标从1到n，0是没用的，就索性拿来用了*/
		L->elem[0] = L->elem[index1];
		L->elem[index1] = L->elem[index2];
		L->elem[index2] = L->elem[0];
	}
	return Ok;
}

int ListDelete(SeqList *L, int index) {
	/*删除第x位(1<=x<=length)*/
	if (index<1 || index>L->length) {
		exit(OutOfIndex);
	}

	for (int i = index; i <= L->length; ++i) {
		L->elem[i] = L->elem[i + 1];
	}

	L->length -= 1;
	return Ok;
}

int LocateElem(SeqList *L, int value, int * index) {
	L->elem[0] = value;

	for (*index = L->length; L->elem[*index] != value; (*index)--);

	return Ok;
}

int test_SeqList() {
	SeqList Sq;
	InitList(&Sq);
	for (int i = 0; i < 20; i++)
	{
		ListInsert(&Sq, Sq.length + 1, i * 2);
	}

	OrderdListInsert(&Sq, 11);

	for (int i = 1; i <= Sq.length; i++)
	{
		printf("%d ", Sq.elem[i]);
	}


	ReverseList(&Sq);
	printf("\nReverseList\n");
	for (int i = 1; i <= Sq.length; i++)
	{
		printf("%d ", Sq.elem[i]);
	}
	//int index = 0;
	//LocateElem(&Sq, 10, &index);
	//printf("\n%d ", index);

	return Ok;
}

struct LinkList {
	/*从1编号到n*/
	int value;
	LinkList *next;
};

int LinkListInit(LinkList *lk) {
	lk->value = 0;
	lk->next = NULL;
	return Ok;
}

int LinkListInsert(LinkList *lk,int index, int value) {
	/*在第i个位置之前插入*/
	int curIndex = 0;
	LinkList *cur = lk;
	while (curIndex < index - 1 && (cur = (LinkList *)(cur->next)))
	{
		curIndex++;
	}

	LinkList * t = (LinkList *)(malloc(sizeof(LinkList)));
	t->value = value;
	t->next = cur->next;
	cur->next = t;

	return Ok;
}

int LinkListPrint(LinkList *lk) {
	LinkList *cur = lk;
	while (cur = (LinkList *)(cur->next))
	{
		printf("%d ", cur->value);
	}
	printf("\n");
	return Ok;
}

int LinkListClip(LinkList *lk, int maxk, int mink) {
	/*为了提高证代码可读性，代码略有冗余，见谅*/
	LinkList *cur = lk;
	bool clip_lowerbound = false,
		clip_upperbound = false;
	while (cur = (LinkList *)(cur->next))
	{
		if (!clip_lowerbound && cur->value > maxk)
		{
			lk->next = cur;
			clip_lowerbound = true;
		}

		if (!clip_upperbound && cur->value < mink && cur->next->value >= mink)
		{
			cur->next = NULL;
			clip_upperbound = true;
			break;
		}
	}
	return Ok;
}

int LinkListDivMN(LinkList *lk) {
	/*这里假设低次项存在于链表低位，即x的0次方存在链表的第1位，x的1次方存在链表的第2位，依此类推*/
	LinkList *cur = lk;
	int index = 0;
	while (cur = (LinkList *)(cur->next))
	{
		if (index != 0)
		{
			if (index == 1)
			{
				/*一次项不显示x*/
				printf("%d+", index * cur->value);
			}
			else if (index == 2)
			{
				/*2次项不显示x^1*/
				printf("%dx+", index * cur->value);
			}
			else
			{
				printf("%dx^%d+", index * cur->value, index - 1);
			}
			
		}
		index += 1;
	}

	/*抹掉最后一个+号*/
	printf("\b \n");
	return Ok;
}

int LinkListReverse(LinkList *lk) {
	LinkList *prepre = lk;
	LinkList *pre = lk;
	LinkList *cur = lk;

	while (cur = (LinkList *)(cur->next))
	{
		if (prepre == lk)
		{
			pre->next = NULL;
		}
		else
		{
			pre->next = prepre;
		}
		prepre = pre;
		pre = cur;
	}
	
	pre->next = prepre;
	/*设置链表头为尾部*/
	lk->next = pre;
	return Ok;
}

int LinkListMerge(LinkList *lk1, LinkList *lk2) {
	/*把lk2并到lk1*/
	LinkList *cur1 = lk1->next;
	LinkList *cur2 = lk2->next;

	LinkList *cur = lk1;

	while (cur1 && cur2)
	{
		if (cur1->value <= cur2->value) {
			cur->next = cur1;
			cur = cur1;
			cur1 = cur1->next;
		}
		else
		{
			cur->next = cur2;
			cur = cur2;
			cur2 = cur2->next;
		}
	}

	cur->next = cur1 ? cur1 : cur2;

	return Ok;
}

int test_LinkList() {
	//LinkList Lk;
	
	//LinkListInit(&Lk);

	//LinkListInsert(&Lk, 1, 2);
	//LinkListInsert(&Lk, 2, 4);
	//LinkListInsert(&Lk, 3, 5);
	//LinkListInsert(&Lk, 4, 6);
	//LinkListInsert(&Lk, 5, 8);

	//LinkListPrint(&Lk);
	//LinkListDivMN(&Lk);
	//LinkListClip(&Lk, 4, 8);
	//LinkListPrint(&Lk);
	LinkList Lk1;
	LinkListInit(&Lk1);
	LinkListInsert(&Lk1, 1, 1);
	LinkListInsert(&Lk1, 2, 3);
	LinkListInsert(&Lk1, 3, 5);
	LinkListPrint(&Lk1);

	LinkList Lk2;
	LinkListInit(&Lk2);
	LinkListInsert(&Lk2, 1, 2);
	LinkListInsert(&Lk2, 2, 4);
	LinkListInsert(&Lk2, 3, 6);
	LinkListPrint(&Lk2);

	LinkListMerge(&Lk1, &Lk2);
	LinkListPrint(&Lk1);
	LinkListReverse(&Lk1);
	LinkListPrint(&Lk1);
	return Ok;
}

int main()
{
	//test_SeqList();
	test_LinkList();
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
