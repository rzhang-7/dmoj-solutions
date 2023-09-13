#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc18j3

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  int arr[5] = {0};
  for(int i = 1; i<5; i++){
    cin>>n;
    arr[i] = n;
  }
  int c = 0;
  int d[5];
  for(int i = 0; i<5; i++){
    c += arr[i];
    d[i] = c;
  }
  for(int i = 0; i<5; i++){
    c = -d[i];    
    for(int j = 0; j<5; j++){
      c += arr[j];  
      cout<<abs(c)<<" ";
    }
    cout<<"\n";
  }
}


/*
int arr[5] = {0};
int n;
for(int i = 1; i < 5; i++){
  cin>>n;
  arr[i] = arr[i-1] + n;
}
for(int i = 0; i < 5; i++){
  for(int j = 0; j < 5; j++){
    cout<<abs(arr[j] - arr[i])<<" ";
  }
  cout<<"\n";
}



*/