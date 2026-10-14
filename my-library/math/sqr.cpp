#include <bits/stdc++.h>
using namespace std;

/**
 * @fn
 * 誤差のない sqrt
 * x が平方数でない場合、小数点以下は切り捨てる
 * 言い換えると、a**2 が x を超えない最大の a を返却する
 * @brief 平方根
 */
long long sqr(const long long& x) {
  assert(x >= 0);
  long long r = sqrtl(static_cast<long double>(x));
  while (static_cast<__int128>(r + 1) * (r + 1) <= x) r++;
  while (static_cast<__int128>(r) * r > x) r--;
  return r;
}
