#include <iostream>
#include <queue>
using namespace std;

void upheapify(int heap[] , int idx){
    if(idx <= 1){
        return;
    }
    bool cmp = heap[idx/2] > heap[idx];
    if(cmp){
        return;
    }
    else{
        swap(heap[idx/2] , heap[idx]);
        return upheapify(heap , idx/2);
    }
}

int *buildHeap(int arr[] , int n){
    int *heap = new int[n+10];
    for(int = 1 ; i<= n ; i++){
        heap[i] = arr[i];
        upheapify(heap , i);
    }
    return heap;
}

void print(int *heap , int n){
    for(int i = 1 ; i<= n ; i++){
        cout<<heap[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[n+10] = {0};
    for(int i = 1; i <= n ; i++){
        cin>>arr[i];
    }
    int *heap = buildHeap(arr , n);
    print(heap);
    return 0;
}
