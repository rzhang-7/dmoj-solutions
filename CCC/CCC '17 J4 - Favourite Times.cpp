#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc17j4

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int d;
  cin>>d;
  int a = d/720, b = d%720;
  int time = 0;
  for(int i = 0; i <= b; i++){
    int hTen = 1;
    int hOne = (i/60)%10;
    int mTen = i%60/10;
    int mOne = i%10;
    if(i > 59 && i < 600) hTen = 0;
    if(i < 60) hOne = 2;
    if(hTen == 1){
      if((mOne - mTen) == (mTen - hOne) && (mTen - hOne) == (hOne - hTen)) time++;
    } 
    else if(mOne - mTen == mTen - hOne) time++;
  }
  cout<<a*31 + time<<"\n";
}