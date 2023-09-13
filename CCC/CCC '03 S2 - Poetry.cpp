#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc03s2

int n;

string findRhyme(string str){
  string r = "";
  for(int i = str.length()-1; i>=(str.find_last_of(" ")==-1?0:(int)str.find_last_of(" ")); i--){
    if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
      r = str.substr(i, str.length()-i+1);
      break;
    }
  }
  if(r == ""){
    r = (str.find(" ") == -1 ? str : str.substr(str.find_last_of(" "), str.length() - str.find_last_of(" ")));
  }
  return r;
}

string lower(string str){
  string s = "";
  for(char c : str){
    s += tolower(c);
  }
  return s;
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for(int i = 0; i<n; i++){
    string l1, l2, l3, l4, r1, r2, r3, r4;
    string temp;
    if(i==0)getline(cin, temp);
    getline(cin, l1);
    getline(cin, l2);
    getline(cin, l3);
    getline(cin, l4);
    l1 = lower(l1);
    l2 = lower(l2);
    l3 = lower(l3);
    l4 = lower(l4);
    r1 = findRhyme(l1);
    r2 = findRhyme(l2);
    r3 = findRhyme(l3);
    r4 = findRhyme(l4);
    //cout<<r1<<"\n"<<r2<<"\n"<<r3<<"\n"<<r4<<"\n";
    if(r1 == r2 && r1 == r3 && r1 == r4 && r2 == r3 && r2 == r4 && r3 == r4){
      cout<<"perfect\n";
    } else if(r1 == r2 && r3 == r4){
      cout<<"even\n";
    } else if(r1 == r3 && r2 == r4){
      cout<<"cross\n";
    } else if(r1 == r4 && r2 == r3){
      cout<<"shell\n";
    } else {
      cout<<"free\n";
    }
  }
}