#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc18s2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n,f;
  cin>>n;
  int s[n][n];  
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      cin>>f;
      s[i][j] = f;
    }
  }  
  int min = s[0][0];
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      if(s[i][j] < min) min = s[i][j];
    }
  }  
  while(s[0][0] != min){  
    for(int i = 0; i<n/2; i++){
      int last = n - i - 1;
      for(int j = i; j<last; j++){
        int offset = j - i;
        int top = s[i][j];
        int right = s[j][last];
        int bottom = s[last][last-offset];
        int left = s[last-offset][i];
  
        s[i][j] = left;
        s[j][last] = top;
        s[last][last-offset] = right;
        s[last-offset][i] = bottom;
      } 
    }
  } 
  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      cout<<s[i][j]<<" ";
    }
    cout<<"\n";
  }
}
