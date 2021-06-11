//
// Created by ls on 2021/6/11.
//

#ifndef CHAPTER3_STACK_AND_QUEUE_SQQUEUE_H
#define CHAPTER3_STACK_AND_QUEUE_SQQUEUE_H
typedef int ElemType;
#define MaxSize 10
typedef struct{
    ElemType data[MaxSize];
    int front, rear;
    /*front指向队头元素
      rear指向队尾元素的下一个位置
      这些规定都不是固定的，注意审题
      method1 = 牺牲一个单元
      method2 = 如果加一个数据成员size区分队空还是队满
      method3 = 如果加一个数据成员tag 0表示最近进行删除（导致队空） 1表示最近进行了插入（导致队满）
    */
}SqQueue;

void InitQueue(SqQueue &Q){
    Q.rear=Q.front=0;
    //队尾入队，队头出队
}
//初始化队列

bool QueueEmpty(SqQueue Q){
    return Q.rear == Q.front;
}
//判断是否为空

bool EnQueue(SqQueue &Q, ElemType x){
    if((Q.rear+1) % MaxSize==Q.front)
        //判断是否队满,必须要牺牲一个单元来判断是队空还是队满
        return false;
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1) % MaxSize;
    //队尾指针加1取模 映射到[0,MaxSize-1]

    return true;
}
//入队操作

bool DeQueue(SqQueue &Q, ElemType &x){
    if(Q.rear==Q.front)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front+1) % MaxSize;
    return true;
}
//出队操作

bool GetHead(SqQueue Q, ElemType &x){
    if(Q.rear==Q.front)
        return false;
    x = Q.data[Q.front];
    return true;
}
//获取队头的值返回给x

int GetLength(SqQueue Q){
    return (Q.rear + MaxSize - Q.front) % MaxSize;
}
//获得队列元素个数
#endif //CHAPTER3_STACK_AND_QUEUE_SQQUEUE_H
