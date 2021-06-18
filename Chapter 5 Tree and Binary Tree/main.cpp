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
//链表存储


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

typedef struct BSTNode{
    int key;
    struct BSTNode *lchild,*rchild;
}BSTNode, *BSTree;


BSTNode *BST_Search(BSTree T,int key){
    while (T!= nullptr&&key!=T->key){
        if(key<T->key) T=T->lchild;
        else T=T->rchild;
    }
    return T;
}
//在二叉排序树找到key的结点

int BST_insert(BSTree &T, int k){
    if(T== nullptr){
        T=(BSTree)malloc(sizeof(BSTNode));
        T->key=k;
        T->lchild=T->rchild= nullptr;
        return 1;
    }
    else if(k==T->key)
        return 0;
    else if(k<T->key)
        return BST_insert(T->lchild, k);
    else
        return BST_insert(T->rchild, k);
}
//插入关键字K
int main() {
}

/*
 *     BiTree root = nullptr;
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
 */
