#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/mockccc14s3

int R, C, N, col;
int main() {
    cin>>R>>C;
    vector<vector<int>> arr(R, vector<int>(C, 0));
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            cin>>arr[i][j];
        }
    }
    for(cin>>N; N>0; N--){
        cin>>col;
        col--;
        stable_sort(arr.begin(), arr.end(), [](auto &x, auto &y){
            return x[col] < y[col];
        });
    }
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }  
}