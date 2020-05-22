#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int compare(int x , int y , int z = INT_MIN){
    return max(x , max(y , z));
}

void downHeapify(vector<int> &heap , int idx = 0){
    if(idx >= heap.size()){
        return;
    }
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    if(left < heap.size()){ //child exist
        int x = 0;
        if(right < heap.size()){
            x = compare(heap[left] , heap[right] , heap[right]);
            if(x == heap[right]){
                swap(heap[idx] , heap[right]);
                return downHeapify(heap , right); 
            }
            else{
                x = compare(heap[idx] , heap[left]);
            }
            if(x == heap[idx]){
                return;
            }
            else{ //left is king
                swap(heap[idx] , heap[left]);
                return downHeapify(heap , right);
            }
        }
    }
    return;
}

void delete_root(vector<int> &heap){
    if(heap.size() == 0){
        return;
    }
    swap(heap[0] , heap[heap.size()-1]);
    heap.pop_back();
    downHeapify(heap);
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
    if(heap.empty()){
        cout<<"Empty heap"<<endl;
        return;
    }
    for(auto x : heap){
        cout<<x<<" ";
    }
    cout<<endl;
}

void delete_particular_node(vector<int> &heap , int idx){
    if(idx < 0 or idx >= heap.size()){
        cout<<"No such idx/data to delete"<<endl;
        return;
    }
    cout<<heap[idx]<<" deleted successfully!"<<endl;
    heap[idx] = INT_MAX;
    swap(heap[0] , heap[idx]);
    upHeapify(heap , idx);
    delete_root(heap);
    return;
}

int main(){
    vector<int> heap = buildHeap();
    int idx = 2;
    print_heap(heap);
    delete_particular_node(heap , idx);
    print_heap(heap);
    delete_particular_node(heap , idx);
    print_heap(heap);
    delete_particular_node(heap , idx);
    print_heap(heap);
    delete_particular_node(heap , idx);
    print_heap(heap);
    delete_particular_node(heap , idx);
    print_heap(heap);
    delete_particular_node(heap , idx);
    print_heap(heap);
    delete_particular_node(heap , idx);
    print_heap(heap);
    delete_particular_node(heap , idx);
    print_heap(heap);
    delete_particular_node(heap , idx);
    print_heap(heap);
    delete_particular_node(heap , idx);
    print_heap(heap);
    delete_particular_node(heap , idx);
    print_heap(heap);
    delete_particular_node(heap , idx);
    print_heap(heap);
    delete_particular_node(heap , idx);
    print_heap(heap);
    delete_particular_node(heap , 0);
    print_heap(heap);
    delete_particular_node(heap , 0);
    print_heap(heap);
    delete_particular_node(heap , 0);
    print_heap(heap);
    return 0;
}
