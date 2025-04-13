#include <bits/stdc++.h>
using namespace std;

/**
 * @fn
 * ax + by = gcd(a, b) を満たす (x, y) が格納される
 * @brief 拡張ユークリッドの互除法
 * @return gcd(a, b)
 */
long long ext_gcd(const long long& a, const long long& b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = ext_gcd(b, a%b, y, x);
  y -= a/b * x;
  return d;
}
