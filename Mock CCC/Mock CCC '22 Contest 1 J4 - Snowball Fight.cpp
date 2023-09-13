#include <iostream>
#include <deque>
#include <string.h>
using namespace std;

// https://dmoj.ca/problem/mccc3j4

int main() {
  int n, t;
  cin>>n>>t;
  int last[n+1], cur[n+1];
  deque<int> lst[n+1];
  for(int i = 1, x; i<=n; i++){ // declare var in for loop
    cin>>x;
    lst[i].push_back(x);
  }
  for(int k = 1; k <= t; k++){
    memset(cur, 0, sizeof(cur)); //fills cur with 0
    for(int i = 1; i<=n; i++){
      if(!lst[i].empty()){
        last[i] = cur[i] = lst[i].front();
        // assigns lst[i].front() to last[i] and cur[i]  
        lst[i].pop_front();
      }
    }
    for(int i = 1; i<=n; i++){
      // if cur[i] is not 0 (value of 0 is false)
      if(cur[i]) lst[cur[i]].push_back(i);
    }
  }
  for(int i = 1; i<=n; i++){
    cout<<last[i]<<(i == n ? "\n" : " ");
    // cout<<last[i]<<" \n"[i==n];
    // if i==n is true, it is a value of 1, which is the second index of " \n"
  }
}


// Attempted Solution

  // int n,t,p;
  // map<int,queue<int>> order,temp;
  // map<int,int> thrown;
  // cin>>n>>t;
  // for(int i = 1; i<=n; i++){
  //   cin>>p;
  //   order[i].push(p);
  // }
  // for(int i = 0; i<t; i++){
  //   for(int j = 1; j<=n; j++){
  //     if(!order[j].empty()){        
  //       thrown[j] = order[j].front();  
  //       temp[thrown[j]].push(j);
  //       order[j].pop();
  //     }
  //   }
  //   for(int j = 1; j<=n; j++){
  //     while(!temp[j].empty()){
  //       order[j].push(temp[j].front());
  //       temp[j].pop();
  //     }
  //   }

  // }
  // for(auto x : thrown){
  //   if(x.first == n) break;
  //   cout<<x.second<<" "; 
  // }
  // cout<<thrown[n]<<"\n";