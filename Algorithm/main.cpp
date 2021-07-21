#include <iostream>

typedef struct SeqList{

    int *data;
    int length;

}SeqList;

using namespace std;

///
/// \param L SeqList
/// \param Length SeqList.Length
void initSeqList(SeqList &L, int Length){

    L.data = (int *)malloc(sizeof(int)*Length);
    L.length = Length;
    cout<<"----------input start-----------"<<endl;
    for(int i=0;i<L.length;i++){
        cout<<"please input "<<endl;
        cin>>L.data[i];
    }
    cout<<"----------input end-----------"<<endl;
}

///
/// \param L SeqList
void displaySeqList(SeqList L){
    cout<<"----------display start -----------"<<endl;
    for(int i=0;i<L.length;i++)
        cout<<"array["<<i<<"]="<<L.data[i]<<endl;
    cout<<"----------display end -----------"<<endl;
}

int main() {
    SeqList L;
    initSeqList(L, 5);
    displaySeqList(L);
    return 0;
}
