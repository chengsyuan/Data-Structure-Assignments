## 数据结构
## 应承轩 - 201785071 - 电计1701

### 8.设二叉树采用二叉链表存储，设计递归算法实现二叉树中所有结点的左右孩子交换。

详细代码放在 https://github.com/chengsyuan/Data-Structure-Assignments/blob/master/Assignment3/q8.cpp

```c++
struct Node{
	Node *l, *r;
	char c;
};

void printInOrderBiTree(Node *root) {
	if (root)
	{
		printInOrderBiTree(root->l);
		printf("%c ", root->c);
		printInOrderBiTree(root->r);
	}
}

void swapLR(Node* root) {
	/*采用后序遍历，先swap子树，然后swap自己*/
	if (root)
	{
		swapLR(root->l);
		swapLR(root->r);

		Node* t = root->l;
		root->l = root->r;
		root->r = t;

	}
}

int testBiTree() {
	Node *rt = (Node *)NULL;

	rt = buildTreeByPreOrder(rt, "abd##eh##i##cf##g##");

	printInOrderBiTree(rt);
	printf("\n");

	swapLR(rt);

	printInOrderBiTree(rt);
	printf("\n");
	return Ok;
}
/* output:
d b h e i a f c g
g c f a i e h b d
*/
```

### 9. 设二叉树采用二叉链表存储，设计非递归算法在根结点为 T 的二叉树中查找是否存在值为 x 的结点，若存在返回其结点地址，不存在返回空指针。

详细代码放在 https://github.com/chengsyuan/Data-Structure-Assignments/blob/master/Assignment3/q9.cpp

```c++
Node* findx(Node* root, char c) {
	Node* st[MAX_SIZE]; int top = 0; /* a easy stack */

	/* preOrder */
	st[top++] = root;
	Node* p = NULL;
	while (top)
	{
		p = st[--top];
		while (p) {
			if (p->c == c) return p; /* find */

			if (p->r) st[top++] = p->r;
			p = p->l;
		}
	}

	return NULL; /* not find */
}
```

### 10. 设二叉树采用二叉链表存储，设计算法判断一棵二叉树是否为完全二叉树。

详细代码放在 https://github.com/chengsyuan/Data-Structure-Assignments/blob/master/Assignment3/q10.cpp

```c++
bool isFullBiTree(Node * rt) {
	Node *queue[MAX_SIZE], *h;
	int head=0, tail=0; // an easy queue
	queue[tail++] = rt; // enqueue root

	rt->id = 1;// set root id to 1
	int last_id = 0; // this id should add 1 for each iteration

	while (head < tail)
	{
		h = queue[head++]; // pop head
		last_id++;

		if (last_id != h->id)
		{
			return false;
		}

		// enqueue left child
		Node* t = h->l;
		if (t)
		{
			queue[tail++] = t;
			t->id = h->id * 2;
		}

		// enqueue right child
		t = h->r;
		if (t)
		{
			queue[tail++] = t;
			t->id = h->id * 2 + 1;
		}
	}

	return true;
}


int testBiTree() {
	Node* rt = (Node*)NULL;

	rt = buildTreeByPreOrder(rt, "abd##e##c#f##", true);
	printf("%d\n", isFullBiTree(rt));

	rt = buildTreeByPreOrder(rt, "abd##e##cf###", true);
	printf("%d\n", isFullBiTree(rt));

	rt = buildTreeByPreOrder(rt, "abd##e##cf##g##", true);
	printf("%d\n", isFullBiTree(rt));
	return Ok;
}
/* out
0
1
1
*/
```

