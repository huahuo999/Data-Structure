#include <iostream>
using namespace std;
/*
#include "LiStack.h"
//链栈
#include "ShStack.h"
//共享栈
#include "SqStack.h"
//顺序栈
#include "SqQueue.h"
//顺序队列
#include "LinkQueue.h"
//链式队列
 */
#define MaxSize 10
typedef struct {
    char data[MaxSize];
    int top;
}SqStack;

void InitSqStack(SqStack &S){
    S.top = -1;
}

bool Push(SqStack &S, char x){
    if(S.top == MaxSize-1){
        return false;
    }
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, char &x){
    if(S.top==-1)
        return false;
    x = S.data[S.top--];
    return true;
}

bool StackEmpty(SqStack &S){
    return S.top == -1;
}

bool bracketCheck(char str[], int length){
    SqStack S;
    InitSqStack(S);
    for(int i=0;i<length;i++){
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            Push(S, str[i]);
        else{
            if(StackEmpty(S))
                return false;
            char topElem;
            Pop(S, topElem);
            if(str[i]==')' && topElem != '(')
                return false;
            if(str[i]==']' && topElem != '[')
                return false;
            if(str[i]=='}' && topElem != '{')
                return false;
        }
    }
    return StackEmpty(S);
};
//括号匹配算法
using namespace std;
int main() {
    char str[5]="{{}}";
    cout<<boolalpha<<bracketCheck(str, 4);
    return 0;
}
