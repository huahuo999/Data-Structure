#include <iostream>
using namespace std;

void  add1(int a,int b){
    a = a+1;
    b = b+1;
}
void add2(int &a,int  &b){
    a = a+2;
    b = b+2;
}
int main() {
    int c =3;
    int d=2;
    cout<<"c="<<c<<endl;
    cout<<"d="<<d<<endl;
    cout<<"c="<<c<<endl;
    cout<<"d="<<d<<endl;
    return 0;
}
