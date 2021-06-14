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
