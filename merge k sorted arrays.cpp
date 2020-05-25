#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int , pair<int , int> > p;

vector<int> merge_k_arrays(const vector<vector<int> > & arr){
    vector<int> ans;
    priority_queue <p , vector<p> , greater<p> > pq;
    for(int i = 0 ; i < arr.size() ; i++){
        pq.push({arr[i][0] , {i , 0}});
    }
    while(!pq.empty()){
        p x = pq.top();
        pq.pop();
        ans.push_back(x.first);
        //cout<<x.first<<" , ";
        int a = x.second.second;
        int b = x.second.first;
        if(a + 1 < arr[b].size()){
            pq.push({arr[b][a+1] , { b , a+1}});
        }
    }
    return ans;
}

int main(void){
    vector<vector<int>> arr ={
                        {1, 5, 6, 8},
                        {2, 4, 10, 12},
                        {3, 7, 9, 11},
                        {13, 14, 15, 16}
                        } ;
    /*                    
    for(auto x : arr){
        for(auto y : x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    int k;
    cin>>k;
    int n;
    cin>>n;
    for(int i = 0 ; i < k ; i++){
        for(int j = 0 ; j < n ; j++){
            int d;
            cin>>d;
            arr[i].push_back(d);
        }
    }*/
    vector<int> ans = merge_k_arrays(arr);
    for(auto x : ans){
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}
