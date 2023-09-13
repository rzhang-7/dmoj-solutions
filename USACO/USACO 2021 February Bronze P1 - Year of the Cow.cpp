#include <iostream>
#include <map>
using namespace std;

// https://dmoj.ca/problem/usaco21febb1

// https://usaco.guide/problems/usaco-1107-year-of-the-cow/solution

string z[12] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};

string animal(int y){
  int a = 0, c = 2021;
  while(c < y){
    c++;
    a++;
    if(a == 12) a = 0;
  }
  while(c > y){
    c--;
    a--;
    if(a == -1) a = 11;
  }
  return z[a];
}

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  string name, fill, order, year, nm;
  map<string, int> b;  
  b["Bessie"] = 2021;
  cin>>n;
  while(n--){
    cin>>name>>fill>>fill>>order>>year>>fill>>fill>>nm;
    b[name] = b[nm];
    do{
      if(order == "previous"){
        b[name]--;
      }
      else{
        b[name]++;
      }
    } while(animal(b[name]) != year);
  }
  cout<<abs(b["Bessie"] - b["Elsie"])<<"\n";
}