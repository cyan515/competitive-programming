#include <bits/stdc++.h>
using namespace std;

// 10進数表現の整数を受け取って BASE 進数に変換して返す
string convert_base(const long long n, const int base,int fixed_len = -1) {
  string ret = "";
  long long cur = n;
  if (cur == 0LL) {
    ret = "0";
  } else {
    while (cur > 0) {
      char c = '0' + (cur % base);
      ret += c;
      cur /= base;
    }
    reverse(ret.begin(), ret.end());
  }
  if(ret.size()<fixed_len) ret = string(fixed_len-ret.size(),'0')+ret;
  return ret;
}
