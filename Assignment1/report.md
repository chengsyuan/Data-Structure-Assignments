## 数据结构 - 线性表作业
## 应承轩 - 201785071 - 电计1701

### 1.用类C语言设计算法，在有序顺序表中插入新的数据x，要求插入后的线性表仍然有序。

```c++
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
```

### 2. 设计算法，实现顺表的就地逆置，要求算法为原地工作算法。
```c++
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
```

### 3. 用类C语言设计高效算法在头指针为h的带表头结点的有序（数据元素的值是递增的）单链表中删除所有值小于等于maxk、大于等于mink的数据元素。
```c++
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
```

### 4.一元多项式采用带表头结点的单链表存放，用类C语言设计算法求一元多项式的一阶导数
```c++
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
```

### 5.设Pa,Pb分别为两个按升序排列的单链表的头指针，设计算法将二个单链表合并为一个按降序排列的单链表C ，要求利用原表的结点空间
```c++
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
```