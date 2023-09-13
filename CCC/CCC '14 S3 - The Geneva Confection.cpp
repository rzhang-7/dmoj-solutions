#include <iostream>
#include <deque>
using namespace std;

// https://dmoj.ca/problem/ccc14s3

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  deque<char> out;
  while(t--){
    int n, num = 1;
    deque<int> mtn, branch;
    cin>>n;
    for(int i = 0; i<n; i++){
      int c;
      cin>>c;
      mtn.push_front(c);
    }
    for(int i = 0; i < (int)mtn.size(); i++){
      if(mtn[i] == num){
        num++;
      } else if(!branch.empty() && branch.front() == num){
        branch.pop_front();
        num++;
        i--;
      } else {
        branch.push_front(mtn[i]);
      }
    }
    for(int i = 0; i < (int)branch.size(); i++){
      if(branch[i] == num) num++;
    }      
    if(num - 1 != n) out.push_back('N');
    else out.push_back('Y');
  }    
  for(int i = 0; i < (int)out.size(); i++)
    cout<<out[i]<<"\n";
}

// Alternate Solution using stack

// cin.sync_with_stdio(0);
// cin.tie(0);
// int t;
// for(cin>>t; t>0; i--){
//   int n; cin>>n;
//   int car[n];
//   for(int i = 0; i<n; i++){
//     cin>>car[i]; 
//   }
//   stack<int> branch;
//   int expect = 1;
//   for(int i = n-1; i >= 0; i--){
//     branch.push(car[i]);
//     while(!branch.empty() && branch.top() == expect){
//       branch.pop();
//       expect++;
//     }
//   }
//   cout<<(branch.empty() ? "Y\n" : "N\n");
// }