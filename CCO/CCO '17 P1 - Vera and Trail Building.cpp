#include <iostream>
#include <algorithm>
#include <vector>

// https://dmoj.ca/problem/cco17p1

/*
// Solution
// A number of beautifully connected pairs can be written as cycles.
// For instance, a cycle of 1->2->3->1
// The number of beautifully connected pairs in these cycles will be the n-1th triangle number, where n is the number of vertices
// The cycle mentioned above will have 3 pairs ((1,2), (1,3), (2,3))
// Moreover, the second triangle number is 3
// This works because if you started at node 1, you would have two choices: pairing with node 2 or 3.
// The next option is just node 2 or 3, which can only pair with each other since both have already paired with node 1.
// Thus the there are 2 + 1 = 3 edges, and if K is a triangular number we just output a cycle of n-1 nodes.

// We can apply this concept to non-triangular numbers with the knowledge that they can be expressed as a sum of triangular numbers.
// For instance, 5 is equal to 1 + 1 + 3
// Thus, we output two cycles for 1 and a cycle for 3 and connect them all together
*/

using namespace std;
const int MM = 1e7+1;

int k, v, sum;
vector<pair<int,int>> g;
vector<int> vi;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>k;
  vi.push_back(0); vi.push_back(0);
  for(int i = 1; sum < MM; i++){
    sum += i;
    if(sum < MM) vi.push_back(sum);
  }
  int idx = 1;
  do {
    // find the index of the triangle number less than or equal to k
    int f = lower_bound(vi.begin(), vi.end(), k) - vi.begin();
    // get the value of the triangle number
    int val = (vi[f] == k ? vi[f] : vi[--f]);

    // create a cycle of size f and update the number of vertices
    for(int i = 0; i<f; i++){
      g.push_back({idx+i,(i == f-1 ? idx : idx+i+1)});
      if(i == f-2) v = idx + i + 1;
      // cout<<idx+i<<" "<<(i == f-1 ? idx : idx+i+1)<<"\n";
    }

    // update vertex value and decrease k
    idx += f;
    k -= val;

    // connect the cycles together
    if(k > 0) {
      g.push_back({idx-1, idx});
      // cout<<idx-1<<" "<<idx<<"\n";
    }
  } while(k > 0);
  cout<<v<<" "<<g.size()<<"\n";
  for(auto x : g){
    cout<<x.first<<" "<<x.second<<"\n";
  }
}