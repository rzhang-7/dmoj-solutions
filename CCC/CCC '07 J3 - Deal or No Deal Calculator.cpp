#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc07j3

int n, b, tot, arr[] = {100,500,1000,5000,10000,25000,50000,100000,500000,1000000};

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 0, x; i<n; i++){
    cin>>x;
    arr[x-1] = 0;
  }
  cin>>b;
  for(int i = 0; i<10; i++){
    tot += arr[i];
  }
  tot /= 10-n;
  cout<<(tot < b ? "deal" : "no deal")<<"\n";
}