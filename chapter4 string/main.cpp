#include <iostream>
using namespace std;

#define MAXLEN 255
typedef struct{
    char ch[MAXLEN];
    int length;
}SString;
//静态数组实现 定长顺序存储
//子串：串中连续的字符组成 可以为空

bool SubString(SString &Sub, SString S, int pos, int len){
    //子串越界
    if(pos+len-1>S.length)
        return false;
    for(int i=pos;i<pos+len;i++)
        Sub.ch[i-pos+1] = S.ch[i];
    Sub.length = len;
    return true;
}
//求子串 用Sub返回串S的第pos个字符起长度为len的子串

int StrCompare(SString S, SString T){
    for(int i=1;i>=S.length && i<=T.length;i++){
        if(S.ch[i]!=T.ch[i])
            return S.ch[i] - T.ch[i];
    }
    return S.length - T.length;
}

int StrLength(SString S){
    return S.length;
}
int Index(SString S, SString T){
    int i=1, n=StrLength(S), m=StrLength(T);
    SString sub;//用于暂存子串
    while(i<=n-m+1){
        SubString(sub, S, i, m);
        if(StrCompare(sub, T)!=0) ++i;
        else return i;
    }
    return 0;
}
//定位子串，返回它在主串S中第一个出现的位置

int Index_Simplicity(SString S, SString T){
    int k=1;
    int i=k, j=1;
    while (i<=S.length && j<=T.length){
        if(S.ch[i] == T.ch[j]){
            ++i;
            ++j;
        } else{
            k++;
            i=k;
            j=1;
        }
    }
    if(j>T.length)
        return k;
    else
        return 0;
}
/*
 * 朴素模式匹配算法 模式串（可能存在的子串）
 * 若模式串长度为m，主串长度为n，则
 * 匹配成功的最好时间复杂度为:O(m)
 * 匹配失败的最好时间复杂度为:O(n-m+1)=O(n-m)~O(n)
 * 最坏时间复杂度：最多需要（n-m+1）*m O(nm)
 */


int Index_KMP(SString S, SString T, int next[]){
    int i=1,j=1;
    while(i<=S.length&&j<=T.length){
        if(j=0||S.ch[i]==T.ch[j]){
            ++i;
            ++j;
        } else
            j=next[j];
    }
    if(j>T.length)
        return i-T.length;
    else
        return 0;
}

//KMP算法
void get_next(SString T, int next[]){
    int i=1,j=0;
    next[1] = 0;
    while(i<T.length){
        //i==T.length时就会直接弹出循环，因为下面赋值总是赋给下一个数
        if(j==0||T.ch[i]==T.ch[j]){
            ++i;
            ++j;
            next[i]=j;
        } else
            j=next[j];
    }
}
/*
 * 获得next数组
 * 串的前缀：包含第一个字符，且不包括最后一个字符的子串
 * 串的后缀：包含最后一个字符，且不包含第一个字符的子串
 * 当第j个字符匹配失败，由前1~j-1个字符组成的串记为S，则：next[j]=S的最长相等前缀后缀长度+1
 * 特别地next数组放弃了第一个next[0]
 * next[1]=0,next[2]=1
 */
/*
 * 获得nextval数组
 * 提出的nextval数组的目的在于如果返回的j值所对应的字母与之前的字母相同就不应该多跳转一回，应当直接赋给之前的字母所对应的next值
 * 用nextval数组可以优化KMP算法
 */
//KMP算法平均时间复杂度为O（n+m）
typedef struct {
    char *ch; //按串长分配存储区，ch指向串的基地址
    int length; //串的长度
}HString;//动态数组实现（堆分配）

void InitHString(HString &S){
    S.ch = (char*)malloc(MAXLEN* sizeof(char));
    //之后还要手动free掉
    S.length = 0;
}

typedef struct StringNode{
    char ch;
    struct StringNode *next;
}StringNode, *String;
//存储密度过低，每个字符1B，每个指针4B

typedef struct StringNode_{
    char ch[4];//每个节点存多个字符
    struct StringNode_ *next;
}StringNode_, *String_;
//存储密度提高
//串的链式存储
int main() {
    return 0;
}
