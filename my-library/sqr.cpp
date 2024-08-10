#include <bits/stdc++.h>
using namespace std;

// sqrt の誤差補正込みのやつ　平方数じゃない場合小数点以下切り捨て
long long sqr(const long long& x) {
  long long r = sqrt(x)-2;
  while((r+1)*(r+1)<=x)r++;
  return r;
}
