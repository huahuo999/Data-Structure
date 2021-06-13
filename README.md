# Data-Structure
记录考研数据结构的代码

## Chapter 2 Link List

***

1. 在循环双链表中，头结点的prior也要指向尾结点，尾结点的next要指向头结点
2. 静态链表要求预先分配一大片连续的内存空间，指针指的是数组中的相对位置
3. 头指针或尾指针是用来指明链表中的第一个结点或最后一个结点，如果只有尾指针是无法访问到单链表的头结点的！！！（不是都是从头开始要看指针）
4. 头结点是在第一个结点前的一个结点，但无论有没有头结点都有头指针都指向第一个结点

## Chapter 3 Stack and Queue

***

1. 注意栈顶指针是指向第一个元素还是第一个元素前面一个元素

2. n个元素进栈，出栈元素不同排列的个数为
   $$
   C_{2n}^n * \frac{1}{n+1}
   $$
   卡特兰数

3. 采用共享栈节省存储空间，降低发生下溢的可能

4. 栈用于递归、迷宫求解、括号匹配、深度优先、进制转换

5. 队列用于缓冲区、CPU竞争资源（页面替换算法）

6. 对于同一个问题的递归问题求解和非递归问题求解，非递归算法的效率通常高一些，递归求解效率低，但代码量少

7. 在计算输入输出受限的双端队列时，先划出一个道路然后右边可以进可以出，只在左边进行受限的限制

8. 十字链表和三元组表适合稀疏矩阵

9. 在计算矩阵元素在数组中下标时一定要注意数组是否从0开始！！！，如果说存入C语言的数组就默认从0开始！！，还要注意是行优先还是列优先！！！



