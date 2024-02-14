#include <bits/stdc++.h>
using namespace std;

// sqrt の誤差補正込みのやつ　平方数じゃない場合小数点以下切り捨て
long long sqr(long long X) {
  long long R = sqrt(X)-2;
  while((R+1)*(R+1)<=X)R++;
  return R;
}