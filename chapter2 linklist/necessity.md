# chapter 2 Link List

## necessity

***

1. 在循环双链表中，头结点的prior也要指向尾结点，尾结点的next要指向头结点
2. 静态链表要求预先分配一大片连续的内存空间，指针指的是数组中的相对位置
3. 头指针或尾指针是用来指明链表中的第一个结点或最后一个结点，如果只有尾指针是无法访问到单链表的头结点的！！！（不是都是从头开始要看指针）
4. 头结点是在第一个结点前的一个结点，但无论有没有头结点都有头指针都指向第一个结点