#include <iostream>
#define MaxSize 10
#define ElemType int
typedef struct SeqList{
    int *data;
    int length;
}SeqList;
using namespace std;
void InitSeqListWithOutInput(SeqList &L, int Length){
    L.data = (int *)malloc(MaxSize* sizeof(int));
    L.length = Length;
}
void InitSeqList(SeqList &L, int Length){
    if(Length > MaxSize)
        cout<<"too long";
    L.data = (int *)malloc(MaxSize* sizeof(int));
    L.length = Length;
    for(int i=0;i<L.length;i++){
        cin>>L.data[i];
    }
    cout<<"input end"<<endl;
}
void DisplaySeqList(SeqList L){
    for(int i=0;i<L.length;i++){
        cout<<L.data[i]<<endl;
    }
    cout<<"---------end----------"<<endl;
}
bool exercise_1(SeqList &L, int &x){
    if(L.length==0)
        return false;
    int i=1;
    int pos=0;
    int min = L.data[0];
    for(;i<L.length;i++){
        if(L.data[i] < min){
            min = L.data[i];
            pos = i;
        }
    }
    x = min;
    L.data[pos] = L.data[L.length-1];
    L.length --;
    return true;
}

void exercise_2(SeqList &L){
    for(int i=0;i<L.length/2;i++){
        ElemType temp;
        temp = L.data[i];
        L.data[i] = L.data[L.length-i-1];
        L.data[L.length-i-1] = temp;
    }

}

void exercise_3(SeqList &L, int x){
    int deleteNum = 0;
    for(int i=0;i<L.length;i++){
        if(L.data[i]==x)
            deleteNum +=1;
        else{
            L.data[i-deleteNum] = L.data[i];
        }
    }
    L.length = L.length - deleteNum;
}

bool exercise_4(SeqList &L, int s, int t){
    if(s>=t || L.length==0)
        return false;
    int i, j;
    for(i=0;i<L.length&&L.data[i]<s;i++);
    if (i>=L.length)
        return false;
    for(j=i;j<L.length&&L.data[j]<=t;j++);
    for(;j<L.length;i++,j++)
        L.data[i] = L.data[j];
    L.length = i;
    return true;
}

bool exercise_5(SeqList &L, int s, int t){
    if(s>=t||L.length==0)
        return false;
    int deleteNum = 0;
    for(int i=0;i<L.length;i++){
        if(L.data[i]>=s&&L.data[i]<=t)
            deleteNum +=1;
        else{
            L.data[i-deleteNum] = L.data[i];
        }
    }
    L.length = L.length - deleteNum;
    return true;
}

bool exercise_6(SeqList &L){
    if(L.length==0)
        return false;
    int i,j;
    for(i=0,j=1;j<L.length;j++){
        if(L.data[i]!=L.data[j])
            L.data[++i] = L.data[j];
    }
    L.length = i+1;
    return true;
}

bool exercise_7(SeqList A, SeqList B, SeqList &C){
    if(A.length+B.length>C.length)
        return false;
    int i=0,j=0,k=0;
    while(i<A.length&&j<B.length){
        if(A.data[i]<B.data[j]){
            C.data[k++] = A.data[i++];
        } else{
            C.data[k++] = B.data[j++];
        }
    }
    while(i<A.length)
        C.data[k++] = A.data[i++];
    while(j<B.length)
        C.data[k++] = B.data[j++];
    C.length = k;
    return true;

}
void ReverseSeqList(SeqList &L){
    for(int i=0;i<L.length/2;i++){
        int temp = L.data[i];
        L.data[i] = L.data[L.length-i-1];
        L.data[L.length-i-1] = temp;
    }
}
void ReverseArray(int R[], int From, int To){
    for(int i=0;i<=(To-From)/2;i++){
        int temp;
        temp = R[i+From];
        R[i+From] = R[To-i];
        R[To-i] = temp;
    }
}
void exercise_8(int Array[], int left, int right, int Length){
    ReverseArray(Array, 0, left-1);
    ReverseArray(Array, left, Length-1);
    ReverseArray(Array, 0, Length-1);
    for(int i=0;i<Length;i++){
        cout<<Array[i]<<endl;
    }

}

void exercise_9(SeqList &L, int x){
    int low=0,high=L.length-1, mid = 0;
    while(low<=high){
        mid = (low + high)/2;
        if(L.data[mid]==x)
            break;
        else if(L.data[mid]<x){
            low = mid +1;
        } else{
            high = mid-1;
        }
    }
    if(L.data[mid]==x&&L.data[mid+1]!=L.data[mid]){
        int temp = L.data[mid];
        L.data[mid] = L.data[mid+1];
        L.data[mid+1] = temp;
    }
    if(low>high){
        int i;
        for(i=L.length-1;i>high;i--){
            L.data[i+1] = L.data[i];
        }
        L.data[i+1] =x;
    }
}
void exercise_10(int R[], int n, int p){
    ReverseArray(R, 0, p-2);
    ReverseArray(R, p-1, n-1);
    ReverseArray(R,0,n-1);
    for(int i=0;i<n;i++){
        cout<<R[i]<<endl;
    }
}

int exercise_11(SeqList L1, SeqList L2){
    int index1=0, index2=0, count=0;
    int threshold = L1.length;
    while (count<threshold){
        if(L1.data[index1] < L2.data[index2]){
            count++;
            if (count==threshold){
                return L1.data[index1];
            }
            index1++;
        } else{
            count++;
            if (count==threshold){
                return L2.data[index2];
            }
            index2++;
        }
    }

}
int main(){
    SeqList L1;
    InitSeqList(L1, 5);
    SeqList L2;
    InitSeqList(L2, 5);
    cout<<"answer="<<exercise_11(L1, L2);


}
/*  exercise_1
SeqList L;
InitSeqList(L, 5);
int  x=0;
cout<<exercise_1(L, x);
DisplaySeqList(L);
 */

/*  exercise_2
SeqList L;
InitSeqList(L, 5);
exercise_2(L);
DisplaySeqList(L);
 */

/*  exercise_3
 *     SeqList L;
    InitSeqList(L, 5);
    int x=2;
    exercise_3(L, x);
    DisplaySeqList(L);
 */
/*  exercise_4
 *     SeqList L;
    InitSeqList(L, 5);
    int s=2;
    int t=4;
    exercise_4(L, 2, 4);
    DisplaySeqList(L);
 */

/*  exercise_5
 *     SeqList L;
    InitSeqList(L, 5);
    int s=2;
    int t=4;
    exercise_5(L, 2, 4);
    DisplaySeqList(L);
 */


/*  exercise_6
 *     SeqList L;
    InitSeqList(L, 5);
    exercise_6(L);
    DisplaySeqList(L);
 */


/*  exercise_7
 *     SeqList A;
 *SeqList B;
 *SeqList C;
 *InitSeqList(A, 5);
 *InitSeqList(B,5);
 *InitSeqListWithOutInput(C, 10);
 *exercise_7(A,B,C);
 *DisplaySeqList(C);
 *
 */

/*  exercise_8
 * int Array[5];
 * for(int & i : Array)
 * cin>>i;
 * exercise_8(Array, 3, 2, 5);
 */

/*  exercise_9
 *     SeqList L;
    InitSeqList(L, 5);
    exercise_9(L, 3);
    DisplaySeqList(L);

 */
/*  exercise_10
int A[5];
for(int & i : A){
cin>>i;
}
exercise_10(A, 5, 3);
 */
/*  exercise_11
 *     SeqList L1;
    InitSeqList(L1, 5);
    SeqList L2;
    InitSeqList(L2, 5);
    cout<<"answer="<<exercise_11(L1, L2);
 */