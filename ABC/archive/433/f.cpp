#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint998244353;
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
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

// https://drken1215.hatenablog.com/entry/2018/06/08/210000
vector<mint> fac, finv, inv;

/// nCk 計算のための前計算処理
/// 計算量は O(n)
void init_comb(int n, int mod) {
  fac.resize(n);
  finv.resize(n);
  inv.resize(n);
  fac.at(0) = fac.at(1) = 1;
  finv.at(0) = finv.at(1) = 1;
  inv.at(1) = 1;
  for (int i = 2; i < n; i++) {
    fac.at(i) = fac.at(i-1) * i;
    inv.at(i) = mod - inv.at(mod%i) * (mod / i);
    finv.at(i) = finv.at(i-1) * inv.at(i);
  }
}

/// nCk を計算して返す。
/// 計算量は O(1)
mint comb(int n, int k) {
  if (n < k) return 0;
  if (n < 0 || k < 0) return 0;
  return fac.at(n) * finv.at(k) * finv.at(n-k);
}

/// nHk を計算して返す。
/// 計算量は O(1)
mint hom(int n, int k) {
  return comb(n+k-1, k);
}

int main() {
  string s;cin>>s;
  map<char,ll> le,ri;
  int n = s.size();
  init_comb(n+10,998244353);
  rep(i,n) {
    ri[s.at(i)]++;
  }
  mint ans = 0;
  rep(i,n) {
    ri[s.at(i)]--;
    ll l = le[s.at(i)]++;
    ll r = ri[s.at(i)+1];
    ans += comb(l+r,l+1);
  }
  cout << ans.val() << endl;

  return 0;
}
