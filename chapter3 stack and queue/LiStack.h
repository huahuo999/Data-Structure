//
// Created by ls on 2021/6/11.
//

#ifndef CHAPTER3_STACK_AND_QUEUE_LISTACK_H
#define CHAPTER3_STACK_AND_QUEUE_LISTACK_H

typedef int ElemType;

typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}*LiStack;
//链栈
#endif //CHAPTER3_STACK_AND_QUEUE_LISTACK_H
