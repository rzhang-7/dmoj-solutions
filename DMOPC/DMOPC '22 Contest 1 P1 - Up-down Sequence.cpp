#include <iostream>
#include <limits>
using namespace std;

// https://dmoj.ca/problem/dmopc22c1p1

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int t,n;
  cin>>t;
  while(t--){
    cin>>n;
    int a[n];
    int b[n];
    for(int i = 0; i<n; i++){
      int x;
      cin>>x;
      a[i] = x;
      b[i] = x;
    }
    // updown a[0] < a[1] > a[2] < a[3] > a[4] ...
    bool updown = true;
    for(int i = 1; i<n; i+=2){
      if(a[i] == 0) a[i] = numeric_limits<int>::max();
      if(a[i-1] >= a[i] || (i+1<n && a[i]<=a[i+1]))
        updown = false;
    }
    // downup a[0] > a[1] < a[2] > a[3] < a[4] ...
    bool downup = true;
    for(int i = 0; i<n; i+=2){
      if(b[i] == 0) b[i] = numeric_limits<int>::max();
      if((i-1>=0 && b[i-1]>=b[i]) || (i+1<n && b[i]<=b[i+1])) downup = false;
    }
    if(updown || downup) cout<<"YES\n";
    else cout<<"NO\n";
  }
}

/*
  WA on batch 2 (only scores 20/100)
  int t,n,a;
  cin>>t;
  while(t--){
    cin>>n;
    int arr[n];
    bool valid = true;
    for(int i = 0; i<n; i++){
      cin>>a;
      arr[i] = a;
    }
    for(int i = 1; i<n-1; i++){        
      if(arr[i-1] == 0 || arr[i] == 0 || arr[i+1] == 0){
        if(arr[i-1] == arr[i] || arr[i] == arr[i+1]){
          if((arr[i-1] == 0 && arr[i] == 0) || (arr[i] == 0 && arr[i+1] == 0) || (arr[i-1] == 0 && arr[i+1] == 0)) continue;
          else{
            cout<<"NO"<<"\n";
            valid = !valid;
            break;
          }
        }
        continue;
      }
      if((arr[i-1] < arr[i] && arr[i] > arr[i+1]) || (arr[i-1] > arr[i] && arr[i] < arr[i+1])) continue;
      else{        
        if(arr[i-1] == 0 || arr[i] == 0 || arr[i+1] == 0){
          continue;
        }
        cout<<"NO"<<"\n";
        valid = !valid;
        break;
      }
    }
    if(valid) cout<<"YES"<<"\n";
  }
*/