#include <bits/stdc++.h>
using namespace std;

// https://dmoj.ca/problem/ccc08j2

int b, n;
deque<char> dq = {'A', 'B', 'C', 'D', 'E'};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	while(b != 4){
		cin>>b>>n;
		if(b == 1) {
			for(int i = 0; i<n; i++){
				char tmp = dq.front(); dq.pop_front();
				dq.push_back(tmp);
			}
		} else if(b == 2) {
			for(int i = 0; i<n; i++){
				char tmp = dq.back(); dq.pop_back();
				dq.push_front(tmp);
			}	
		} else if(b == 3) {
			n %= 2;
			if(n){
				char tmp1 = dq.front(); dq.pop_front();
				char tmp2 = dq.front(); dq.pop_front();
				dq.push_front(tmp1); dq.push_front(tmp2);
			}
		}
	}
	for(char c : dq){
		cout<<c<<" ";
	}
	cout<<"\n";
}