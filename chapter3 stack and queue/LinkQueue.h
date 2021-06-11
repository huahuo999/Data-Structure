//
// Created by ls on 2021/6/11.
//

#ifndef CHAPTER3_STACK_AND_QUEUE_LINKQUEUE_H
#define CHAPTER3_STACK_AND_QUEUE_LINKQUEUE_H
typedef struct Linknode{
    ElemType data;
    struct Linknode *next;
}Linknode;

typedef struct {
    Linknode *front, *rear;
}LinkQueue;
//链式队列

void InitQueue(LinkQueue &Q){
    Q.front=Q.rear=(Linknode*)malloc(sizeof(Linknode));
    Q.front->next=nullptr;
}
//初始化带头结点

void EnQueue(LinkQueue &Q, ElemType x){
    Linknode *s = (Linknode *)malloc(sizeof(Linknode));
    s->data = x;
    s->next = nullptr;
    Q.rear->next = s;
    Q.rear = s;
}
//新元素入队带头结点

bool DeQueue(LinkQueue &Q, ElemType &x){
    if(Q.rear==Q.front)
        return false;
    Linknode *p = Q.front->next;
    x = p->data;
    Q.front->next = p->next;
    if(Q.rear==p)
        Q.rear=Q.front;
    free(p);
    return true;
}
//队头元素出队带头结点
#endif //CHAPTER3_STACK_AND_QUEUE_LINKQUEUE_H
