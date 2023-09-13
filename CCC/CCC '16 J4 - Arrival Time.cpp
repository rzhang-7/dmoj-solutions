#include <iostream>
using namespace std;

// https://dmoj.ca/problem/ccc16j4

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  string time;
  cin>>time;
  int h = stoi(time.substr(0,2));
  int m = stoi(time.substr(3,2));
  int tm = h*60 + m;
  
  if(tm >= 320 && tm < 600){
    if(tm < 420){
      tm = 420 + ((120 - (420 - tm))*2);
      if(tm > 600) tm -= (tm%600)/2;
      m = tm%60;
      h = tm/60;
      printf("%.2d:%.2d\n", h, m);
      return 0;
    }
    m += ((600 - tm)/2)%60;
    h += ((600 - tm)/2)/60 + 2;
    // tm = h*60 + m;
  }
  else if(tm >= 800 && tm < 1140){
    if(tm < 900){
      tm = 900 + ((120 - (900 - tm))*2);
      m = tm%60;
      h = tm/60;
      printf("%.2d:%.2d\n", h, m);
      return 0;      
    }
    m += ((1140 - tm)/2)%60;
    if(m > 60){
      m = m%60;
      h++;
    }
    h += ((1140 - tm)/2)/60 + 2;
    tm = h*60 + m;
  }
  else h += 2;
  
  if(h > 23) h -= 24;
  printf("%.2d:%.2d\n", h, m);
}

// more efficient solution:
// int h, m;
// scanf("%d:%d", &h, &m);
// int t = h*60 + m;
// for(int i = 1; i<=120; i++){
//   if((7*60 <= t && t < 10*60) || (15*60 <= t && t < 19*60)) {
//     t += 2;
//   } else { 
//     t++;
//   }
// }
// h = t / 60 % 24;
// m = t % 60;
// printf("%.2d:%.2d\n", h, m);