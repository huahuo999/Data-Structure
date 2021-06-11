//
// Created by ls on 2021/6/11.
//

#ifndef CHAPTER3_STACK_AND_QUEUE_SQSTACK_H
#define CHAPTER3_STACK_AND_QUEUE_SQSTACK_H
typedef int ElemType;
//初始化ElemType的类型
#define MaxSize 10
typedef struct {
    ElemType data[MaxSize];
    //以ElemType为类型，MaxSize为长度的数组
    int top;
    //top指向第一个元素 记录数组下标 初始的时候top=-1
    //top指针也有可能指向第一个元素的前一个位置注意审题
}SqStack;
//顺序栈

bool Push(SqStack &S, ElemType x){
    if(S.top==MaxSize-1)
        return false;
    S.data[++S.top] = x;
    //++S.top表示先加再进行运算
    return true;
}
//新元素入栈

bool Pop(SqStack &S, ElemType &x){
    if(S.top==-1)
        return false;
    x=S.data[S.top--];
    //S.top先运算再减1
    return true;
}
//出栈操作

bool GetTop(SqStack S, ElemType &x){
    if (S.top==-1)
        return false;
    x=S.data[S.top];
    return true;
}
//读取栈顶元素

#endif //CHAPTER3_STACK_AND_QUEUE_SQSTACK_H
