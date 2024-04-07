#include <bits/stdc++.h>
// #include <atcoder/dsu>
// using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int n;cin>>n;
  string s,t;cin>>s>>t;
  int a = s.size();
  int b = t.size();
  ll ok = 0;
  ll ng = LINF;
  while((ok-ng)>1) {
    ll mid = (ok+ng)/2;
    ll cnt = 0;
    int idx = 0;
    rep(i,b) {
      a;
      
    }
    if(cnt<=n) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;

  return 0;
}
