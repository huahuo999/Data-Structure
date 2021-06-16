#include <iostream>
using namespace std;
#define MaxSize 100
struct ElemType{
    int value;
};
struct TreeNode{
    ElemType value;
    bool isEmpty;
};

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;



typedef struct ThreadNode{
    ElemType data;
    struct ThreadNode *lchild,*rchild;
    int ltag,rtag;
}ThreadNode, *ThreadTree;

extern ThreadNode *pre;

void visit(ThreadNode *q){
    if(q->lchild==nullptr){
        q->lchild=pre;
        q->ltag=1;
    }
    if(pre!=nullptr&&pre->rchild==nullptr){
        pre->rchild=q;
        pre->rtag=1;
    }
    pre = q;
}

void InThread(ThreadTree T){
    if(T!=NULL){
        InThread(T->lchild);
        visit(T);
        InThread(T->rchild);
    }
}


int main() {
    BiTree root = nullptr;
    root = (BiTree)malloc(sizeof(BiTNode));
    root->data = {1};
    root->lchild=nullptr;
    root->rchild= nullptr;
    BiTNode *p = (BiTNode*)malloc(sizeof(BiTNode));
    p->data = {2};
    p->lchild= nullptr;
    p->rchild= nullptr;
    root->lchild=p;
    return 0;
}
