#include <iostream>
#include <vector>
using namespace std;

// https://dmoj.ca/problem/ecoo16r1p3

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i < 10; i++) {
    int n;
    vector<int> now;
    vector<int> past;
    int where[1000];
    cin >> n;
    string t[n];
    for (int j = 0; j < n; j++) {
      string c;
      cin >> c;
      t[j] = c; 
    }
    for (int j = 0; j < n; j++) {
      where[stoi(t[j]) - 1] = j; 
      now.push_back(stoi(t[j])); 
    }
    int ans = 0;
    int lasti = where[n - 1]; 
    for (int j = n - 2; j >= 0; j--) {
      int index = where[j];
      for (unsigned k = 0; k < past.size(); k++) {
        if (past[k] > index)
          index++;
      }
      if (lasti < index) {
        now.insert(now.begin() + now[index], 0);
        now.erase(now.begin() + index + 1);
        past.push_back(index);
        ans += index;
        lasti = 0;
      } else
        lasti = index;
    }
    cout << ans << "\n";
  }
}

/*
5
3 5 1 4 2

4 3 5 1 2  +3
3 4 5 1 2  +1
2 3 4 5 1  +4
1 2 3 4 5  +4
Make the observation that any value X cannot be moved until X + 1 is before X + 2 in order to have the minimal amount of movements. Then iterate starting from N and only move value X if it occurs after X + 1.

for(int i =0; i<10;i++){
  int n,c,cost = 0;
  vector<int>a;
  cin>>n;
  for(int j=0; j<n; j++){
    cin>>c;
    a.push_back(c);
  }
  for(int j=n-1; i>0; i--){
    int low = a.find(a.begin(), a.end(), i) - a.begin();
    int high = a.find(a.begin(), a.end(), i+1) - a.begin();
    if(low>high){
      cost += low;
      a.erase(a.begin() + low);
      a.insert(a.begin(), i);
    }
  }
}
cout<<cost<<"\n";
*/