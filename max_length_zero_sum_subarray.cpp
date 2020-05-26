#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int max_length_zero_sum_subarray(int *arr , int n){
    unordered_map<int , int> m;
    int cum_sum = 0;
    int max_len = 0;
    for(int i = 0 ; i < n ; i++){
        cum_sum += arr[i];
        if(cum_sum == 0){
            max_len = max(max_len , i+1);
        }
        if(m.count(cum_sum) == 0){
            m[cum_sum] = i;
            cout<<cum_sum<<" : "<<i<<endl;
        }
        else{
            max_len = max(max_len , i - m[cum_sum]);
        }
    }
    return max_len;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n+100];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    int x = max_length_zero_sum_subarray(arr , n);
    if(x != 0){
        cout<<x<<endl;
    }
    else{
        cout<<"No zero sum subarray"<<endl;
    }
    return 0;
}
