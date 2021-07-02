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
// 直接插入排序 最好情况O（n）最差情况O（n^2） 算法稳定性 稳定 插入排序


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
//折半插入排序时间复杂度O（n^2）稳定性 稳定 插入排序
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
//希尔排序 最好O(n^1.3) 最坏时间复杂度O(n^2) 不稳定 仅适用于顺序表 插入排序

int Partition(int A[], int low, int high){
    int pivot = A[low];
    while(low<high){
        while(low<high&&A[high]>=pivot)--high;
        A[low] = A[high];
        while (low<high&&A[low]<=pivot)++low;
        A[high]=A[low];
    }
    A[low] = pivot;
    return low;
}
int QuickSort(int A[], int low, int high){
    if(low<high){
        int pivotpos = Partition(A, low, high);
        QuickSort(A, low, pivotpos-1);
        QuickSort(A, pivotpos+1, high);
    }
}
//快速排序 最好O(n*log2^n) 最坏O(n^2) 如果本身有序就是最慢的
//如果每一个枢轴都将待排序序列划分为两个均匀的部分，则递归深度最小，算法效率最高
//优化时可以改变枢轴元素的选择
//快速排序是所有内部的排序算法平均性能最优秀的算法 O(log2^n) 稳定性 不稳定
//注意一趟排序和一次划分的区别 一次划分可以确定一个元素的最终位置，一趟排序也许可以确定多个元素的最终位置

void SelectSort(int A[], int n){
    for(int i=0;i<n-1;i++){
        int min = i;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[min]) min=j;
        }
        if(min!=i) swap(A[i], A[min]); //swap函数共移动元素三次
    }
}
//简单选择排序(选择排序) 空间复杂度O（1）时间复杂度O（n^2） 稳定性 不稳定 既可以用于顺序表也可以用于链表
//不会因为初始状态不同而改变 一定要n-1趟
void HeadAdjust(int A[], int k,int len){
    A[0] = A[k];
    for(int i=2*k;i<=len;i*=2){
        if(i<len&&A[i]<A[i+1])
            i++;
        if(A[0]>=A[i]) break;
        else{
            A[k] = A[i];
            k=i;
        }
    }
    A[k] = A[0];
}

void BuildMaxHeap(int A[], int len){
    for(int i=len/2;i>0;i--){
        HeadAdjust(A, i, len);
    }
}


void HeapSort(int A[], int len){
    BuildMaxHeap(A, len);
    for(int i=len;i>1;i--){
        swap(A[i], A[1]);
        HeadAdjust(A,1,i-1);
    }
}

//建立初始堆是O（n）空间复杂度O(1) 时间复杂度O(n*log2^n) 稳定性 不稳定
//插入时要放到表尾巴 删除时要用表尾元素代替再进行下坠



int *B = (int *)malloc(5* sizeof(int));
void Merge(int A[], int low, int mid, int high){
    int i,j,k;
    for(k=low;k<=high;k++){
        B[k] = A[k];
    }
    for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++){
        if(B[i]>B[j])
            A[k] = B[i++];
        else
            A[k] = B[j++];
    }
}
void MergeSort(int A[], int low, int high){
    if(low<high){
        int mid= (low+high)/2;
        MergeSort(A, low, mid);
        MergeSort(A, mid+1, high);
        Merge(A, low, mid, high);
    }
}
//归并算法 稳定 空间复杂度O(n) 空间复杂度O(n*log2^n)


//基数排序 空间复杂度O（r） 时间复杂度O（d(n+r)） 通常基于链式存储 稳定 适于方便差分的 关键字取值范围不大 数据元素个数大
int main() {
    return 0;
}
