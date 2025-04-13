#include <bits/stdc++.h>
using namespace std;

vector<int> z_algo(const string& s) {
  int n = s.size();
  vector<int> z(n, 0);
  z.at(0) = n;
  int l = 0, r = 0;
  
  for (int i = 1; i < n; i++) {
    if (i <= r) {
      z.at(i) = min(r - i + 1, z.at(i - l));
    }
    while (i + z.at(i) < n && s.at(z.at(i)) == s.at(i+z.at(i))) {
      z.at(i)++;
    }
    if (i + z.at(i) - 1 > r) {
      l = i;
      r = i + z.at(i) - 1;
    }
  }
  return z;
}
