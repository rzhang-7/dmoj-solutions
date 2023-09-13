#include <iostream>
using namespace std;

// https://dmoj.ca/problem/cheerio3p1

int n, m;
string arr[1000];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m;
  for(int i = 0; i<n; i++){
    cin>>arr[i];  
  }
  for(int i = 0; i<n; i++){
    for(int j = 0; j<m; j++){
      if(arr[i][j] == 'W'){
        cout<<"W";
      } else {
        if(arr[i][j+!(j==m-1)] == 'W' || arr[i][j-!(j==0)] == 'W'){
          cout<<'C';
        }
        else if(arr[i+!(i==n-1)][j] == 'W' || arr[i-!(i==0)][j] == 'W'){
          cout<<'C';
        }
        else {
          cout<<".";
        }
      }
    }
    cout<<"\n";
  }  
}