#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 998244353;

unsigned long long binaryToDecimal(string S) {
  int len = S.length();
  long long ret = 0;
  for(int i=0;i<len;i++) {
    ret *= 2L;
    if(S.at(i)=='1') ret++;
  }
  return ret;
}

int main() {
  string s = "";
  for(int i=0;i<64;i++) {
    string t;cin>>t;
    s = t+s;
  }

  unsigned long long ans = binaryToDecimal(s);
  cout << ans << endl;

  exit(0);
}
