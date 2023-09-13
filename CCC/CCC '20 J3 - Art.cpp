#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc20j3

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  int x[n];
  int y[n];
  for(int i = 0; i<n; i++){
    string coord;
    cin>>coord;
    int pos = coord.find(',');
    x[i] = stoi(coord.substr(0,pos));
    y[i] = stoi(coord.substr(pos+1,coord.length()-1));
  }
  int x1 = x[0];
  int x2 = x[0];
  int y1 = y[0];
  int y2 = y[0];
  for(int i = 0; i < n; i++){
    if(x[i] > x2) x2 = x[i];
    else if(x[i] < x1) x1 = x[i];
    if(y[i] > y2) y2 = y[i];
    else if(y[i] < y1) y1 = y[i];
  }
  /*sort(x, x+n);
    sort(y, y+n);
    cout<<x[0]-1<<","<<y[0]-1<<endl;
    cout<<x[n-1]+1<<","<<y[n-1]+1;
  */
  x1--;
  x2++;
  y1--;
  y2++;
  cout<<x1<<","<<y1<<"\n";
  cout<<x2<<","<<y2<<"\n";
}