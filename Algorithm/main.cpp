#include <iostream>
#include <assert.h>
#include "queue"
typedef struct SeqList{

    int *data;
    int length;

}SeqList;

using namespace std;

///initiate the SeqList
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


///display
/// \param L SeqList
void displaySeqList(SeqList L){
    cout<<"----------display start -----------"<<endl;
    for(int i=0;i<L.length;i++)
        cout<<"array["<<i<<"]="<<L.data[i]<<endl;
    cout<<"----------display end -----------"<<endl;
}

/// without guard
/// \param L SeqList
void insertSort(SeqList &L){
    int i,j,temp;
    for(i=1;i<L.length;i++){
        if(L.data[i] < L.data[i-1]){
            temp = L.data[i];
            for(j=i-1;j>=0&&L.data[j]>temp;j--){
                L.data[j+1] = L.data[j];
            }
            L.data[j+1] = temp;
        }
    }
}

/// insertSort Use BinarySearch
/// \param L SeqList
void insertSortWithBinarySearch(SeqList &L){
    int i,j,temp,low,high,mid;
    low = 0;
    for(i=1;i<L.length;i++){
        if(L.data[i]<L.data[i-1]){
            high = i;
            temp = L.data[i];
            while(low<=high){
                mid = (low + high)/2;
                if(L.data[mid]>temp)
                    high = mid-1;
                else
                    low = mid+1;
            }
            for(j=i-1;j>=low;j--)
                L.data[j+1] = L.data[j];
            L.data[low] = temp;
        }
    }
}

/// swap two int data
/// \param a int data
/// \param b int data
void swap(int &a, int &b){
    int temp=a;
    a = b;
    b = temp;
}
/// bubble sort(Swap)
/// \param L SeqList
void bubbleSort(SeqList &L){
    int i,j;
    for(i=0;i<L.length;i++){
        bool flag = false;
        for(j=L.length-1;j>=0;j--){
            if(L.data[j]<L.data[j-1]){
                swap(L.data[j], L.data[j-1]);
                flag = true;
            }
        }
        if(!flag){
            return;
        }
    }
}

/// partition the SeqList and return the low position
/// \param L SeqList
/// \param low Left pos
/// \param high Right pos
/// \return
int partition(SeqList &L, int low, int high){
    int pivot = L.data[low];
    cout<<"current pivot is "<<pivot<<endl;
    while(low<high){
        while(L.data[high]>=pivot&&high>low) --high;
        L.data[low] = L.data[high];
        while(L.data[low]<pivot&&low<high) ++low;
        L.data[high] = L.data[low];
    }
    L.data[low] = pivot;
    return low;
}

/// Quick Sort(recursion)
/// \param L SeqList
/// \param low Left pos
/// \param high Right pos
void quickSort(SeqList &L, int low, int high){
    if(low<high){
        int pivotPosition = partition(L, low, high);
        cout<<"current pivotPosition is "<<pivotPosition<<endl;
        quickSort(L, low, pivotPosition-1);
        quickSort(L, pivotPosition+1, high);
    }
}

/// easy SelectSort swap
/// \param L SeqList
void selectSort(SeqList &L){
    int i,j;
    for(i=0;i<L.length-2;i++){
        int min = i;
        for(j=i+1;j<L.length-1;j++){
            if(L.data[j]<L.data[min]) min=j;
        }
        if(min!=i){
            swap(L.data[i], L.data[min]);
        }
    }
}

/// adjust to big root heap
/// \param array chosen array
/// \param k use k as root
/// \param Length array.Length
void headAdjustBig(int array[], int k, int Length){
    array[0] = array[k];//register the root
    for(int i=2*k;i<=Length;i*=2){
        if(i<Length&&array[i]<array[i+1])//i<Length to judge if there is a right brother
            i++;//choose right node
        if(array[0]>=array[i]) break;//need't to adjust
        //need to adjust
        else{
            array[k] = array[i];//adjust to the parent's pos
            k = i;//k is the pos where need to insert
        }
    }
    array[k] = array[0];//finish the descent
}

/// build big root heap
/// \param array chosen array
/// \param Length array.Length
void buildMaxHeap(int array[], int Length){
    cout<<"--------------build the heap start-------------"<<endl;
    for(int i=Length/2;i>0;i--)
        headAdjustBig(array, i, Length);
    for(int j=0;j<6;j++){
        cout<<"array["<<j<<"]="<<array[j]<<endl;
    }
    cout<<"--------------build the heap end-------------"<<endl;
}

/// heapSort
/// \param array array
/// \param Length array.Length
void bigHeapSort(int array[], int Length){
    buildMaxHeap(array, Length);
    for(int i=Length;i>1;i--){
        swap(array[i], array[1]);//swap with the end element
        headAdjustBig(array, 1, i-1);//adjust to a big root heap
    }
}


void adjustToMinHeap(int array[], int k, int Length){
    array[0] = array[k];
    int i;
    for(i=2*k;i<=Length;i*=2){
        if(array[i]>array[i+1]&&i+1<=Length){
            i++;
        }
        if(array[k]<array[i]) break;
        else{
            array[k] = array[i];
            k = i;
        }
    }
    array[k] = array[0];
}
void buildMinHeap(int array[], int Length){
    for(int i=Length/2;i>0;i--){
        adjustToMinHeap(array, i, Length);
    }
}

void smallHeapSort(int array[], int Length){
    buildMinHeap(array, Length);
    for(int i=Length;i>1;i--){
        swap(array[i], array[1]);
        adjustToMinHeap(array, 1, i-1);
    }
}
/// Merge the array(the two array has already been arranged)
/// \param array array
/// \param low low pos
/// \param mid mid pos
/// \param high high pos
void Merge(int array[], int low, int mid, int high){
    int *assist = (int *)malloc(sizeof(array)* sizeof(int));
    int i,j,k;
    for(k=low;k<=high;k++)
        assist[k] = array[k];
    for(i=low,j=mid+1,k=i;i<=mid&&j<=high;k++){
        if(assist[i]<=assist[j])
            array[k] = assist[i++];
        else
            array[k] = assist[j++];
    }
    while(i<=mid) array[k++] = assist[i++];
    while(j<=high) array[k++] = assist[j++];
}

/// mergeSort the array
/// \param array array
/// \param low low pos
/// \param high high pos
void mergeSort(int array[], int low, int high){
    if(low < high){
        int mid = (low+high)/2;//partition from the mid
        mergeSort(array, low, mid);//merge sort the left portion
        mergeSort(array, mid+1, high);//merge sort the right portion
        Merge(array, low, mid, high);//merge the array

    }
}
/// Initial Breath First Search
/// \param G the Graph
/// \param v the chosen vertex
void BFS(int G[][8], int v){
    bool visited[8] ={false, false, false, false, false, false, false, false};
    queue<int >q;
    q.push(v);
    visited[v] = true;
    cout<<"current node is "<<v+1<<endl;
    while(!q.empty()){
        int current_node = q.front();
        q.pop();
        for(int i=0; i<8;i++){
            if (G[current_node][i]==1 && !visited[i]){
                q.push(i);
                visited[i] = true;
                cout<<"current node is "<<i+1<<endl;
            }
        }
        cout<<endl;
    }

}

/// use BFS to find singular source min path
/// \param G the graph C++ array must have a finite column
/// \param v the chosen vertex
void BFS_MIN_DISTANCE(int G[][8], int v){
    bool visited[8] ={false, false, false, false, false, false, false, false};
    int distance[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
    int path[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
    queue<int >q;
    q.push(v);
    visited[v] = true;
    cout<<"current node is "<<v+1<<endl;
    distance[v] = 0;
    while(!q.empty()){
        int current_node = q.front();
        q.pop();
        for(int i=0; i<8;i++){
            if (G[current_node][i]==1 && !visited[i]){
                visited[i] = true;
                cout<<"current node is "<<i+1<<endl;
                distance[i] = distance[current_node] + 1;
                path[i] = current_node;
                q.push(i);
            }
        }
        cout<<endl;
    }
    for(int j=0;j<8;j++){
        cout<<"distance from "<<v+1<<" to "<<j+1<<" is "<<distance[j]<<endl;
    }
}

/// Dijkstra find singular source min path O(v^2)=O(n^2)
/// \param G G the graph C++ array must have a finite column
/// \param v the chosen vertex
void Dijkstra(int G[][5], int v){
    bool final[5] = {false, false, false, false, false};
    int distance[5] = {10000, 10000, 10000, 10000, 10000};
    int path[5] = {-1, -1, -1, -1, -1};
    distance[v] = 0;
    queue<int>q;
    q.push(v);
    while(!q.empty()){
        int current_node = q.front();
        q.pop();
        final[current_node] = true;
        cout<<"current_node is "<<current_node<<endl;
        for(int j=0;j<5;j++){
            if(G[current_node][j]!=0 && !final[j]&&(G[current_node][j] +distance[current_node] < distance[j])){
                distance[j] = G[current_node][j] +distance[current_node];
                path[j] = current_node;
            }
        }
        for(int i=0;i<5;i++){
            cout<<"the distance from v"<<v<<" to v"<<i<<" is "<<distance[i]<<endl;
        }
        int minVal = 100000;
        int minNode = -1;
        for(int i=0;i<5;i++){
            if(distance[i] < minVal && !final[i])
            {
                minVal = distance[i];
                minNode = i;
            }
        }
        if(minNode==-1)
            break;
        q.push(minNode);
        cout<<"current minNode is "<<minNode<<endl;
    }
    for(int i=0;i<5;i++){
        cout<<"the distance from v"<<v<<" to v"<<i<<" is "<<distance[i]<<endl;
    }
}
int main() {
    /* Dijkstra
     *  int G[5][5] = {
            {0, 10, 0, 0, 5},
            {0, 0, 1, 0, 2},
            {0, 0, 0, 4, 0},
            {7, 0, 6, 0, 0},
            {0, 3, 9, 2, 0}
    };
    Dijkstra(G, 0);

     */
    /* BFS
     *     int G[8][8] = {
            {0, 1, 0, 0, 1, 0, 0, 0},
            {1, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 1, 0, 1, 1, 0},
            {0, 0, 1, 0, 0, 0, 1, 1},
            {1, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 1, 0, 0, 0, 1, 0},
            {0, 0, 1, 0, 0, 1, 0, 1},
            {0, 0, 0, 1, 0, 0, 1, 0}
    };
    BFS_MIN_DISTANCE(G, 1);
     */




    /*    merge sort
     *     int a[5] = {2,3,4,1,5};
    mergeSort(a, 0, 4);
    for(int i=0;i<=4;i++){
       cout<<"array["<<i<<"]= "<<a[i]<<endl;
    }
     *
     */
    /*smallHeapSort
     *     int array[6] = {0,2,3,4,1,5};
    smallHeapSort(array, 5);
        for(int i=0;i<6;i++){
            cout<<"array["<<i<<"]="<<array[i]<<endl;
        }
     */
    /*selectSort and bubbleSort and quickSort
     *     SeqList L;
    initSeqList(L, 5);
    selectSort(L);
    bubbleSort(L);
    insertSortWithBinarySearch(L);
    quickSort(L, 0, 4);
    displaySeqList(L);
     */

    return 0;
}
