#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool zero_sum_subarray(int *arr , int n){
    unordered_map<int , int> m;
    int csum = 0;
    for(int i = 0 ; i < n ; i++){
        csum += arr[i];
        if(csum == 0 or m[csum] != 0){
            return true;
        }
        m[csum]++;
    }
    return false;
}

bool zero_sum_subarray2(int *arr , int n){
    unordered_set<int> s;
    int csum = 0;
    for(int i = 0 ; i < n ; i++){
        csum += arr[i];
        if(csum == 0 or s.find(csum) != s.end()){
            return true;
        }
        s.insert(csum);
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    int *arr = new int[n+100];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }
    if(zero_sum_subarray(arr , n)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    if(zero_sum_subarray2(arr , n)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
