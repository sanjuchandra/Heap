#include <iostream>
#include <vector>
using namespace std;

void upHeapify(vector<int> &heap , int idx){
    if(idx <= 0){
        return;
    }
    bool cmp = heap[(idx-1)/2] > heap[idx];
    if(cmp){
        return;
    }
    swap(heap[(idx-1)/2] , heap[idx]);
    return upHeapify(heap , (idx-1)/2);
}

vector<int> buildHeap(){
    int n;
    cin>>n;
    vector<int> heap;
    heap.reserve(1000);
    for(int i = 0 ; i < n ; i++){
        int d;
        cin>>d;
        heap.push_back(d);
        upHeapify(heap , i);
    }
    return heap;
}

void const print_heap(const vector<int> &heap){
    for(auto x : heap){
        cout<<x<<" ";
    }
    cout<<endl;
}
int main(){
    vector<int> heap = buildHeap();
    print_heap(heap);
    return 0;
}
