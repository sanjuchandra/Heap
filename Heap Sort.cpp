#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int compare(int x , int y , int z = INT_MIN){
    return max(x , max(y , z));
}

void downHeapify(vector<int> &heap , int size ,  int idx = 0){
    if(idx >= size){
        return;
    }
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    if(left < size){ //child exist
        int x = 0;
        if(right < size){
            x = compare(heap[left] , heap[right] , heap[right]);
            if(x == heap[right]){
                swap(heap[idx] , heap[right]);
                return downHeapify(heap , size , right); 
            }
            else{
                x = compare(heap[idx] , heap[left]);
            }
            if(x == heap[idx]){
                return;
            }
            else{ //left is king
                swap(heap[idx] , heap[left]);
                return downHeapify(heap , size , left);
            }
        }
    }
    return;
}

void upHeapify(vector<int> &heap , int idx){
    if(idx <= 0){
        return;
    }
    bool cmp = heap[(idx-1)/2] > heap[idx];
    if(cmp){
        return;
    }
    else{
        swap(heap[(idx-1)/2] , heap[idx]);
        return upHeapify(heap , (idx-1)/2);
    }
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
    if(heap.empty()){
        cout<<"Empty heap"<<endl;
        return;
    }
    for(auto x : heap){
        cout<<x<<" ";
    }
    cout<<endl;
}

void heapSort(vector<int> & heap){
    int size = heap.size();
    if(size <= 1){
        return;
    }
    
    for(int i = size ; i >= 1 ; i--){
        swap(heap[0] ,heap[i-1]);
        //print_heap(heap);
        downHeapify(heap , i-1);
        //print_heap(heap);
    }
    return;
}

int main(){
    vector<int> heap = buildHeap();
    print_heap(heap);
    heapSort(heap);
    print_heap(heap);
    return 0;
}
