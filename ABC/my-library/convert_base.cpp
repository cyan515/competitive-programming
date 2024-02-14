#include <bits/stdc++.h>
using namespace std;

// 10進数表現の int を受け取って BASE 進数に変換して返す
string convert_base(int _N, int BASE) {
  string RET = "";
  if (_N == 0LL) {
    RET = "0";
  } else {
    while (_N > 0) {
      char c = '0' + (_N % BASE);
      RET += c;
      _N /= BASE;
    }
    reverse(RET.begin(), RET.end());
  }
  return RET;
}