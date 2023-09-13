#include <iostream>
using namespace std;

// https://dmoj.ca/problem/aplusb2

int cmp(string a, string b){
  if(a.size() != b.size()) return a.size() > b.size();
  if(a == b) return 2;
  return (a.compare(b) > 0);
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin>>n;
  while(n--){
    string A, B, ans = ""; cin>>A>>B;
    bool carry = 0;
    A = string(A.rbegin(), A.rend());
    B = string(B.rbegin(), B.rend());
    
    if((A.back() == '-') != (B.back() == '-')){
      string aTemp = A, bTemp = B;
      if(A.back() == '-') aTemp.pop_back();
      else bTemp.pop_back();

      aTemp = string(aTemp.rbegin(), aTemp.rend());
      bTemp = string(bTemp.rbegin(), bTemp.rend());

      // A is greater
      if(cmp(aTemp, bTemp) == 1){
        if(A.back() == '-'){ 
          cout<<"-";
          A.pop_back();
        } else B.pop_back();
        // subtract A by B
        for(int i = 0; i<(int)A.size(); i++){
          char c = (i < (int)B.size() ? B[i] : '0');
          int dif = (10+(A[i]-'0')-(c-'0') - carry);
          ans += (char)(dif%10 + '0');
          carry = (dif < 10);
        }
      }
      else if(cmp(aTemp, bTemp) == 0){
        if(B.back() == '-') {
          B.pop_back();
          cout<<'-';
        } else A.pop_back();
        for(int i = 0; i<(int)B.size(); i++){
          char c = (i < (int)A.size() ? A[i] : '0');
          int dif = (10+(B[i]-'0')-(c-'0') - carry);
          ans += (char)(dif%10 + '0');
          carry = (dif < 10);
        }        
      }
      else {
        cout<<0<<"\n";
        continue;
      }
    }
    else {
      if(A == "0" && B == "0"){
        cout<<0<<"\n";
        continue;
      }
      if(A.back() == '-' && B.back() == '-'){
        cout<<"-";
        A.pop_back(); B.pop_back();
      }
      for(int i = 0; i<(int)min(A.size(), B.size()); i++){
        int sum = carry + (A[i] - '0') + (B[i] - '0');
        ans += (char)(sum%10 + '0');
        carry = (sum >= 10);
      }
      
      if(A.size() < B.size()){
        for(int i = (int)A.size(); i<(int)B.size(); i++){
          int sum = carry + (B[i] - '0');
          ans += (char)(sum%10 + '0');
          carry = (sum >= 10);
        }       
      } 
      else {
        for(int i = (int)B.size(); i<(int)A.size(); i++){
          int sum = carry + (A[i] - '0');
          ans += (char)(sum%10 + '0');
          carry = (sum >= 10);
        }
      }
      if(carry)
        ans += '1';
    }
    for(int i = ans.size()-1; i>=0; i--){
      if(ans[i] == '0'){
        ans.pop_back();
      }
      else break;
    }
    ans = string(ans.rbegin(), ans.rend());
    cout<<ans<<"\n";
  }
}