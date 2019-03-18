## 数据结构 - 栈和队列作业
## 应承轩 - 201785071 - 电计1701

### 1.用类C语言设计算法判断所输入的以‘@’为结束标记的字符串是否形如“序列1&序列2”的形式，其中序列1和序列2都不含‘&’字符，序列1是序列2的逆序列，比如“a+b&b+a@”就是一个属于该模式的字符串，而“a+b&b-a@”则不是。

详细代码放在https://github.com/chengsyuan/Data-Structure-Assignments/Assignment2/q1.cpp

```c++
int isHuiwen(char str[]) {
	CharStack stack;

	bool meet_andchar = false;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == '&')
		{
			meet_andchar = true;
			continue;
		}

		if (str[i] == '@')
		{
			// 栈不为空也不行
			if (stack.size != 0)
			{
				return 0;
			}

			break;
		}

		if (!meet_andchar)
		{
			pushCharStack(&stack, str[i]);
		}
		else {
			// 判断弹出的元素是否和当前字符相等
			if (str[i] != popCharStack(&stack))
			{
				return 0;
			}
		}

	}

	return 1;
}

int test_huiwen() {

	char str1[] = "a+b&b+a@";        
	printf("isHuiwen(%s) = %d\n", str1, isHuiwen(str1));

	char str2[] = "a+b&b-a@";
	printf("isHuiwen(%s) = %d\n", str2, isHuiwen(str2));

	return Ok;
}
```

### 2. 若进栈序列为ABCD，请写出全部可能的出栈序列和不可能的出栈序列。
可能的出栈序列：

| ABCD     | BCAD     |
| -------- | -------- |
| **ABDC** | **BCDA** |
| **ACBD** | **BDCA** |
| **ACDB** | **CDBA** |
| **ADCB** | **CBDA** |
| **BACD** | **CBAD** |
| **BADC** | **DCBA** |

不可能的出栈序列：

| ADBC     | DACB     |
| -------- | -------- |
| **BDAC** | **DACB** |
| **CABD** | **DBCA** |
| **CADB** | **DBAC** |
| **CDAB** | **DCAB** |



### 3. 不允许设计数器，简要说明循环队列如何判断队满和队空？

循环队列具体C实现在：https://github.com/chengsyuan/Data-Structure-Assignments/blob/master/Circular%20Queue/source.cpp

```c++
int sizeOfQueue(Circular_Queue * queue) {
	return (queue->end - queue->front + queue->max_size) % queue->max_size;
}
```

队满： sizeOfQueue(&queue) == queue.max_size - 1

（留一个元素防止循环队列头尾指针重叠）

队空： sizeOfQueue(&queue) == 0

### 4.设计算法将由+，-，*，/, (, )和单字母变量组成的普通表达式转换成逆波兰式

详细代码放在https://github.com/chengsyuan/Data-Structure-Assignments/Assignment2/q4.cpp

```c++
int getOperatorPriority(char ch) {

	if (ch == '+' || ch == '-')
		return 1;

	if (ch == '*' || ch == '/')
		return 5;

	if (ch == ')')
		return 10;

	if (ch == '(')
		return -10;

	exit(TestFailed);
}

int test_expreesion_to_reverse_polish() {
	SeqStack v_stack;
	CharStack c_stack;

	char str[] = "1 + 2 * 3 * ( 4 + 5 ) + 6 ";
    // the output is:
	// 5.00 4.00 + 3.00 * 2.00 *  6.00 + 1.00 +

	int value = 0;
	bool isFirst = true;

	for (char i = 0; i < strlen(str); i++)
	{
		char ch = str[i];
		if (ch == ' ')
		{
			// push stack
			pushStack(&v_stack, (double)value);
			//printf("value = %d\n", value);
			value = 0;
		}
		else if ('0' <= ch && ch <= '9')
		{
			// read in value
			value *= 10;
			value += ch - '0';
		}
		else {
			// operate
			i++;

			pushCharStack(&c_stack, ch);
			if (v_stack.size == 1) {
				continue;
			}

			if (ch == '(') {
				//啥也不干
				continue;
			}

 			if (ch == ')') {
				char ch_top = c_stack.elem[c_stack.size - 1];

				popCharStack(&c_stack);

				while ((ch_top = c_stack.elem[c_stack.size - 1])!='(')
				{
					if (isFirst) {
						double a = popStack(&v_stack);
						double b = popStack(&v_stack);

						printf("%.2lf %.2lf %c ", a, b, ch_top);

						isFirst = false;
					}
					else
					{
						double a = popStack(&v_stack);

						printf("%.2lf %c ", a, ch_top);
					}


					popCharStack(&c_stack);
				}
				
				popCharStack(&c_stack);
				continue;
			}


			while (true) {

				char ch_top = c_stack.elem[c_stack.size - 1];
				char ch_top_m_1 = c_stack.elem[c_stack.size - 2];

				if (getOperatorPriority(ch_top) < getOperatorPriority(ch_top_m_1)) {

					isFirst = false;

					if (isFirst) {
						double a = popStack(&v_stack);
						double b = popStack(&v_stack);

						printf("%.2lf %.2lf %c ", a, b, ch_top_m_1);

					}
					else
					{
						double a = popStack(&v_stack);

						printf("%.2lf %c ", a, ch_top_m_1);
					}


					popCharStack(&c_stack);
					popCharStack(&c_stack);

					pushCharStack(&c_stack, ch);
				}
				else {
					break;
				}
			}

		}
	}

	while (c_stack.size)
	{
		if (isFirst) {
			isFirst = false;
			char ch = popCharStack(&c_stack);
			double a = popStack(&v_stack);
			double b = popStack(&v_stack);

			printf("%.2lf %.2lf %c ", a, b, ch);

		}
		else {
			char ch = popCharStack(&c_stack);
			double a = popStack(&v_stack);

			printf(" %.2lf %c", a, ch);
		}

	}
	return Ok;
}


```
