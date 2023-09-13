#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/ccc23j3

int arr[5], mx = 0;
vector<int> v;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  for(int i = 0; i<n; i++){
    string str;
    cin>>str;
    for(int j = 0; j<5; j++){
      if(str[j] == 'Y'){
        arr[j]++;
      }
    }
    // for(int k = 0; k<5; k++){
    //   cout<<arr[k]<<" ";
    // }
    // cout<<"\n";
  }      
  
  for(int i = 0; i<5; i++){
    if(arr[i] > mx){
      mx = arr[i];
    } 
  }

  for(int i = 0; i<5; i++){
    if(arr[i] == mx && mx != 0){
      v.push_back(i+1);
    }
  }

  for(int i = 0; i<(int)v.size(); i++){
    cout<<v[i]<<(i == (int)v.size()-1 ? "\n" : ",");
  }
}