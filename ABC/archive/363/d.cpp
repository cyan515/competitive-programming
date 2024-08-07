#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
const string Yes = "Yes";
const string No = "No";
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

long long powll(long long BASE, long long EXPONENT) {
  long long RET = 1;
  while (EXPONENT > 0) {
    if (EXPONENT & 1) RET = RET * BASE;
    BASE = BASE * BASE;
    EXPONENT >>= 1;
  }
  return RET;
}

int main() {
  ll n;cin>>n;n--;
  
  ll len = 1;
  ll cnt = 9;
  while (n > cnt) {
    n -= cnt;
    len++;
    cnt = 9 * powll(10, (len - 1) / 2);
  }

  string ans = to_string(powll(10, (len - 1) / 2) + n - 1);
  int si = len%2 ? ans.length() - 2 : ans.length() - 1;
  for(int i=si;i>=0;i--) {
    ans += ans[i];
  }
  cout << ans << endl;

  return 0;
}
