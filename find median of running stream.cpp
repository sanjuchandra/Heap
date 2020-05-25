#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void insert_in_correct_heap(priority_queue<int , vector<int> , greater<int>> &min_heap , int &h_min , priority_queue<int> &max_heap , int &h_max , int data){
    if(h_max == 0){
        max_heap.push(data);
        h_max++;
        return;
    }
    if(data <= max_heap.top()){
        max_heap.push(data);
        h_max++;
    }
    else{
        min_heap.push(data);
        h_min++;
    }
    if(abs(h_max - h_min) <= 1){
        return;
    }
    else{
        if(h_max >= h_min+1){
            min_heap.push(max_heap.top());
            max_heap.pop();
            h_max--;
            h_min++;
        }
        else{
            max_heap.push(min_heap.top());
            min_heap.pop();
            h_max++;
            h_min--;
        }
    }
    return;
}

void print_median_of_running_stream(queue<int> stream , int n){
    if(n == 0){
        return;
    }
    priority_queue<int> max_heap;
    priority_queue<int , vector<int> ,greater<int> > min_heap;
    int h_max = 0 , h_min = 0;
    while(!stream.empty()){
        insert_in_correct_heap(min_heap , h_min , max_heap , h_max , stream.front());
        stream.pop();
        if(h_max == h_min){
            cout<<(min_heap.top() + max_heap.top())/2<<endl;
        }
        else{
            if(h_max > h_min){
                cout<<max_heap.top()<<endl;
            }
            else{
                cout<<min_heap.top()<<endl;
            }
        }
    }
}

int main(){
    int n;
    queue<int> stream;
    cin>>n;
    for(int i = 0 ; i < n ; i++){
        int d;
        cin>>d;
        //cout<<d;
        stream.push(d);
    }
    print_median_of_running_stream(stream , n);
    return 0 ;
}
