#include <iostream>
#include <string.h>
using namespace std;

// https://dmoj.ca/problem/ccc06s1

int recess[5];
int dom[5];

int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n;
  string m, f;
  bool valid = true;
  cin >> m >> f >> n;

  for (int i = 0; i < 10; i += 2) {
    if ((m[i] <= 'E' && m[i + 1] <= 'E') || (f[i] <= 'E' && f[i + 1] <= 'E')) {
      dom[i / 2] = 1;
    }
    if ((m[i] >= 'a' && m[i + 1] >= 'a') && (f[i] >= 'a' && f[i + 1] >= 'a')) {
      recess[i / 2] = 1;
    }
  }

  for (int i = 0; i < n; i++) {
    string b;
    valid = true;
    cin >> b;
    for (int j = 0; j < 5 && valid; j++) {
      if ((b[j] >= 'a' && dom[j]) || (b[j] <= 'E' && recess[j])) {
        cout << "Not their baby!\n";
        valid = false;
      }
    }
    if (valid)
      cout << "Possible baby.\n";
  }
}