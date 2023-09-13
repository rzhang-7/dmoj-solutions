#include <iostream>
#include <algorithm>
using namespace std;

// https://dmoj.ca/problem/usaco20decb1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  int arr[7];
  for(int i = 0; i<7; i++){
    cin>>n;
    arr[i] = n;
  }
  sort(arr,arr+7);
  int a = arr[0];
  int b = arr[1];
  int c = arr[6] - a - b;
  cout<<a<<" "<<b<<" "<<c<<"\n";
}