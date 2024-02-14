#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 1000000007;

ll binaryToDecimal(string S) {
  int len = S.length();
  ll ret = 0;
  for(int i=0;i<len;i++) {
    ret *= 2LL;
    if(S.at(i)=='1') ret++;
  }
  return ret;
}

int main() {
  string s;cin>>s;
  ll n;cin>>n;
  int len = s.length();
  ll sum = binaryToDecimal(s);
  vector<ll> a(len);
  a.at(0) = 1;
  for(int i=1;i<len;i++) a.at(i) = a.at(i-1) * 2;
  reverse(a.begin(),a.end());

  if(sum>n) {
    cout << -1 << endl;
    exit(0);
  }

  for(int i=0;i<len;i++) {
    if(s.at(i)=='?' && sum+a.at(i)<=n) sum+=a.at(i);
  }
  cout << sum << endl;

  exit(0);
}

