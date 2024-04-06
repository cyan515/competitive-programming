#include <bits/stdc++.h>
using namespace std;

// 2進数表現の string を受け取って10進数に変換して返す
// 1 以外は 0 とみなされる
long long binary_to_decimal(string S) {
  int len = S.length();
  long long ret = 0;
  for(int i=0;i<len;i++) {
    ret *= 2L;
    if(S.at(i)=='1') ret++;
  }
  return ret;
}
