#include <bits/stdc++.h>
using namespace std;

// 繰り返し二乗法
long long powll(long long BASE, long long EXPONENT) {
  long long RET = 1;
  while (EXPONENT > 0) {
    if (EXPONENT & 1) RET = RET * BASE;
    BASE = BASE * BASE;
    EXPONENT >>= 1;
  }
  return RET;
}