#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// https://dmoj.ca/problem/usaco19decbronze3

vector<string> name = {"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};

int n;
vector<string> x, y;
string s[6];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 0; i<n; i++){
    for(int j = 0; j<6; j++){
      cin>>s[j];
    }
    x.push_back(s[0]); y.push_back(s[5]);
  }
  sort(name.begin(), name.end());
  do{
    bool valid = true;
    for(int i = 0; i<n; i++){
      int px = find(name.begin(), name.end(), x[i]) - name.begin();
      int py = find(name.begin(), name.end(), y[i]) - name.begin();
      if(abs(px - py) != 1) valid = false;
    }
    if(valid){
      for(string each : name) cout<<each<<"\n";
      return 0;
    }
        
  } while(next_permutation(name.begin(), name.end()));
}