#include <iostream>
#include <vector>
#include <climits>
using namespace std;


void upHeapify(int arr[] , int idx){
    if(idx <= 0){
        return;
    }
    bool cmp = arr[(idx-1)/2] > arr[idx];
    if(cmp){
        return;
    }
    swap(arr[(idx-1)/2] , arr[idx]);
    return upHeapify(arr , (idx - 1)/2);
}

void const print_array(const int *arr , const int n){
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    return;
}

void build_inplace_heap(int arr[] , int n){
    for(int i = 0 ; i < n ; i++){
        upHeapify(arr , i); //no need to insert already inserted
    }
    return;
}


int main(){
    int n;
    cin>>n;
    int arr[10000] = {0};
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    build_inplace_heap(arr , n);
    print_array(arr , n);
    return 0;
}
