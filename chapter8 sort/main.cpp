#include <iostream>
using namespace std;
void InsertSort(int A[], int n){
    int i,j, temp;
    for(i=1;i<n;i++){
        if(A[i]<A[i-1])
            temp = A[i];
        for(j=i-1;j>=0&&A[j]>temp;--j){
            A[j+1]=A[j];
        }
        A[j+1] = temp;
    }
}
// 直接插入排序 最好情况O（n）最差情况O（n^2） 算法稳定性 稳定


void InsertSortBinary(int A[], int n){
    int i,j,low,high,mid;
    for(i=2;i<=n;i++){
        A[0] = A[i];
        low = 1;
        high = i-1;
        while(low<=high){
            mid = (low+high)/2;
            if(A[mid]>A[0]) high = mid+1;
            else low = mid +1;
        }
        for(j=i-1;j>=high+1;--j)
            A[j+1] = A[j];
        A[high+1] = A[0];
    }
}
//折半插入排序时间复杂度O（n^2）稳定性
void ShellSort(int A[], int n){
    int d,i,j;
    for(d=n/2;d>=1;d=d/2)
        for(i=d+1;i<=n;++i){
            if(A[i]<A[i-d]){
                A[0] = A[i];
                for(j=i-d;j>0&&A[0]<A[j];j-=d)
                    A[j+d] = A[0];
            }
        }
}
//希尔排序 最好O(n^1.3) 最坏时间复杂度O(n^2) 不稳定 仅适用于顺序表
int main() {
    return 0;
}
