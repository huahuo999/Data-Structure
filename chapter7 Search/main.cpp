#include <iostream>
using namespace std;
#define ElemType int
typedef struct{
    ElemType *elem;
    int TableLen;
}SSTable;

int Search_Seq(SSTable ST, ElemType key){
    int i;
    for(i=0;i<ST.TableLen&&ST.elem[i]!=key;++i);
    return i==ST.TableLen? -1:i;
}

int main() {
    return 0;
}
