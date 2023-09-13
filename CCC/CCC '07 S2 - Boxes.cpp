#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// https://dmoj.ca/problem/ccc07s2

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  vector<vector<int>> box, sz; 
  multimap<int,vector<int>> mvi; // like regular map, but allows duplicate keys
  
  cin>>n;
  for(int i = 0; i<n; i++){
    vector<int> dim; // store dimensions of box
    int v = 1; // store volume of box
    for(int j = 0, x; j < 3; j++){
      cin>>x;
      dim.push_back(x);
      v *= x;
    }
    sort(dim.begin(), dim.end()); // sort the dimensions in ascending order for convenience
    mvi.insert(make_pair(v,dim)); // use map to automatically sort boxes by volume 
  }

  for(auto x : mvi){
    box.push_back(x.second); // transfer sorted dimensions to a vector for convenience
  }
  
  cin>>m;
  for(int i = 0; i<m; i++){
    vector<int> dim;
    for(int j = 0, x; j < 3; j++){
      cin>>x;
      dim.push_back(x);
    }
    sort(dim.begin(), dim.end());
    sz.push_back(dim);
  }

  for(int i = 0; i<m; i++){ // check every item
    bool fit = true;
    for(int j = 0; j<n; j++){  // go through available boxes
      fit = true;
      for(int k = 0; k<3; k++){  // compare dimensions of item with dimensions of box - if former is bigger, box is too small
        if(sz[i][k] > box[j][k]){
          fit = false;
        }
      }
      if(fit){ // we only need to check if the item fits because we already know that the current box is the smallest fit
        int vol = 1;
        for(int k = 0; k<3; k++){
          vol *= box[j][k]; // re-calculate volume, technically unnecessary if the boxes were kept in the map
        }
        cout<<vol<<"\n";
        break; // stop checking all the boxes and skip to next item
      }
    }
    if(!fit) cout<<"Item does not fit.\n"; // item failed all checks
  }
}