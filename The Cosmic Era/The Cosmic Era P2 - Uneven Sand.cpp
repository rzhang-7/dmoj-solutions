#include <iostream>
using namespace std;
typedef long long ll;

// https://dmoj.ca/problem/seed2

int main() {
  string ans;
  ll lo = 0, hi = 2e9, mid;
  while(ans != "OK"){
    mid = (lo+hi)/2;
    cout<<mid<<endl;
    cin>>ans;
    if(ans == "SINKS"){
      lo = mid + 1;
    } else if(ans == "FLOATS"){
      hi = mid - 1;
    }
  }
}