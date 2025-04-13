#include <bits/stdc++.h>
using namespace std;

// 繰り返し二乗法
/**
 * @fn
 * base**exponent を計算する
 * @brief 繰り返し二乗法
 */
long long powll(long long base, long long exponent) {
  long long ret = 1;
  while (exponent > 0) {
    if (exponent & 1) ret = ret * base;
    base = base * base;
    exponent >>= 1;
  }
  return ret;
}
