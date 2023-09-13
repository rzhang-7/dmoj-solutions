#include <iostream>
#include <math.h>
using namespace std;

// https://dmoj.ca/problem/sac22cc4jp3

const double PI = 3.14159265;
int n, a, ans = 0;
double mn = INT32_MAX;

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> a;
  for (int i = 1, x, y; i <= n; i++) {
    cin >> x >> y;
    double b = atan2(y, x) * 180/PI;
    b = b<=0?360-abs(b):abs(b);
    if (min(360 - abs(a - b), abs(a - b)) < mn) {
      ans = i;
      mn = min(360 - abs(a - b), abs(a - b));
    }
  }
  cout << ans << "\n";
}