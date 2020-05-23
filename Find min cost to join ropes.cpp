#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define ll long long

int compare(int x , int y , int z = INT_MAX){
    return min(x , min(y , z));
}

void downHeapify(vector<int> &heap , int idx = 0){
    if(heap.size() <= 1){
        return;
    }
    int left = 2*idx + 1;
    int right = left+1;
    if(left < heap.size()){
        int x = 0;
        if(right < heap.size()){
            x = compare(heap[idx] , heap[left] , heap[right]);
            if(x == heap[right]){
                swap(heap[idx] , heap[right]);
                return downHeapify(heap , right);
            }
        }
        else{
            x = compare(heap[idx] , heap[left]);
        }
        if(x == heap[idx]){
            return;
        }
        else{
            swap(heap[idx] , heap[left]);
            return downHeapify(heap , left);
        }
    }
    return;
}

void upHeapify(vector<int> &heap , int idx){
    if(idx <= 0 or idx >= heap.size()){
        return;
    }
    bool cmp = heap[(idx-1)/2] <= heap[idx];
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
    heap.reserve(10000000);
    for(int i = 0 ; i < n ; i++){
        int d;
        cin>>d;
        heap.push_back(d);
        upHeapify(heap , i);
    }
    return heap;
}

void delete_root(vector<int> &heap){
    if(heap.size() <= 0){
        return;
    }
    swap(heap[0] , heap[heap.size()-1]);
    heap.pop_back();
    downHeapify(heap);
    return;
}

void const print_heap(const vector<int> &heap){
    for(auto x : heap){
        cout<<x<<" ";
    }
    cout<<endl;
}
ll min_cost_of_joining_ropes(vector<int> &heap , ll cost = 0){
    if(heap.size() <= 1){
        return cost;
    }
    ll curr_cost = 0;
    curr_cost += heap[0];
    delete_root(heap);
    curr_cost += heap[0];
    delete_root(heap);
    heap.push_back(curr_cost);
    upHeapify(heap , heap.size() - 1);
    return min_cost_of_joining_ropes(heap , cost + curr_cost);

}

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int> heap = buildHeap();
        cout<<min_cost_of_joining_ropes(heap);
        cout<<endl;
    }
    
    return 0;
}
