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
  long long r = sqrt(x)-2;
  while((r+1)*(r+1)<=x)r++;
  return r;
}
