#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int , pair<int , int>> customPair;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    if(n == 0){
        return -1;
    }
    priority_queue<customPair , vector<customPair> , greater<customPair> >pq;
    for(int i = 0 ; i < n ; i++){
        pq.push({matrix[0][i] , {0 , i} });
    }
    int ans;
    while(k--){
        customPair x = pq.top();
        pq.pop();
        ans = x.first;
        int a = x.second.first;
        int b = x.second.second;
        if(a+1 < n){
            pq.push({ matrix[a+1][b] , {a+1 , b}});
        }
    }
    return ans;
}


int main(){
    //int n;
    //cin>>n;
    int k;
    cin>>k;
    vector<vector<int>> matrix = { {10, 20, 30, 40}, 
                    {15, 25, 35, 45}, 
                    {25, 29, 37, 48}, 
                    {32, 33, 39, 50}, 
                  }; 
    //matrix.reserve(100000);
    /*for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>matrix[i][j];
        }
    }*/
    cout<<kthSmallest(matrix , k)<<endl;
    return 0;
}
