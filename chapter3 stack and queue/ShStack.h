//
// Created by ls on 2021/6/11.
//
typedef int ElemType;
//初始化ElemType的类型
#define MaxSize 10
#ifndef CHAPTER3_STACK_AND_QUEUE_SHSTACK_H
#define CHAPTER3_STACK_AND_QUEUE_SHSTACK_H
typedef struct {
    ElemType data[MaxSize];
    int top0;//0号栈栈顶的位置
    int top1;//1号栈栈顶的位置
}ShStack;
//共享栈


void InitShStack(ShStack &S){
    S.top0 = -1;
    S.top1 = MaxSize;
}
//初始化共享栈
//判断是否栈满的条件是 top0 + 1 == top1
#endif //CHAPTER3_STACK_AND_QUEUE_SHSTACK_H
