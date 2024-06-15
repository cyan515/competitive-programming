#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace atcoder;
using namespace std;
using mint = modint998244353;
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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

vector<vector<mint>> comb(int n) {
  vector<vector<mint>> v(n + 1,vector<mint>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
    }
  }
  return v;
}

int main() {
  ll k;cin>>k;
  int n = 26;
  vector<ll> c(n);cin>>c;
  vector dp(27,vector<mint>(k+1,0));
  dp.front().front() = 1;
  auto base = comb(k+1);
  rep(i,26) rep(j,k+1) rep(cnt,c.at(i)+1) {
    if(j+cnt>k) continue;
    if(j==0) dp.at(i+1).at(j+cnt) += dp.at(i).at(j);
    else {
      dp.at(i+1).at(j+cnt) += dp.at(i).at(j)*base.at(j+cnt).at(cnt).val();
    }
  }
  mint ans = 0;
  reps(i,1,k+1) {
    ans += dp.at(26).at(i);
  }
  cout << ans.val() << endl;

  return 0;
}
