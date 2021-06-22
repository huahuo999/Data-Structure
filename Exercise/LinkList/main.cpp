#include <iostream>
using namespace std;
#define ElemType int

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;


void InitLinkList(LinkList &L, const int Array[], int Length){
    LNode *s;
    int index = 0;
    L = (LinkList)malloc(sizeof(LNode));
    L->next = nullptr;
    while(index<Length){
        s = (LNode*)malloc(sizeof(LNode));
        s->data = Array[index];
        s->next = L->next;
        L->next = s;
        index++;
    }

}

void InitArray(int Array[], int Length){
    for(int i=0;i<Length;i++){
        cin>>Array[i];
    }
    cout<<"input end"<<endl;
}
void DisplayLinkList(LinkList L){
    L = L->next;
    while(L!= nullptr){
        cout<<L->data<<"->";
        L = L->next;
    }
}
int main() {
    int Array[5];
    InitArray(Array, 5);
    LinkList L;
    InitLinkList(L, Array, 5);
    DisplayLinkList(L);
    return 0;
}
