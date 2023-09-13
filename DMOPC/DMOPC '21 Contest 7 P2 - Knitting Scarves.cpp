#include <bits/stdc++.h>
using namespace std;

// https://dmoj.ca/problem/dmopc21c7p2

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin>>n>>q;
	vector<pair<int,int>> pos(n+2);
	for(int i = 1; i<=n; i++){
		pos[i] = {i-1, i+1};
	}
	pos[0] = {-1,1}; pos[n+1] = {n,n+1};

	// cout<<"m0 = {\n";
	// for(auto x : pos){
	// 	printf("\t{%d : {%d, %d}},\n", x.first, x.second.first, x.second.second);
	// }
	// cout<<"}\n\n";	

	for(int i = 1, l, r, k; i<=q; i++){
		cin>>l>>r>>k;
		int x = pos[k].second, a = pos[l].first, b = pos[r].second;

		if(l == x) continue;

		// connect l to k
		pos[k].second = l;
		pos[l].first = k;
		
		// append k to l segment to back of r
		pos[r].second = x;
		pos[x].first = r;
	
		// connect elements after r to the segment between k and l
		pos[a].second = b;
		pos[b].first = a;
		
		// printf("m%d = {\n", i);
		// for(auto x : pos){
		// 	printf("\t{%d : {%d, %d}},\n", x.first, x.second.first, x.second.second);
		// }
		// cout<<"}\n";
	}
	int idx = pos[0].second;	
	while(idx != n+1){
		cout<<idx<<" ";
		idx = pos[idx].second;
	}
	cout<<"\n";
	// for(int i = pos[0].second; i != n+1; i = pos[i].second){
	// 	cout<<i<<" \n"[pos[i].second == n+1];
	// }
}