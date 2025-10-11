#include <bits/stdc++.h>
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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

#include <atcoder/modint>
using namespace std;
using mint = atcoder::modint;

/**
 * @fn
 * k = 0,1,...,n について nCk を計算して返す。
 * ret[i][j] = iCj の値。
 * 計算量 O(N^2)
 * @param n 総数
 * @param mod 法
 */
vector<vector<long long>> comb(const int& n, const int& mod) {
  vector<vector<long long>> v(n + 1,vector<long long>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k])%mod;
    }
  }
  return v;
}

// /// nCk を計算して返す。
// /// 計算量は O(1)
// mint comb(int n, int k) {
//   if (n < k) return 0;
//   if (n < 0 || k < 0) return 0;
//   return fac.at(n) * finv.at(k) * finv.at(n-k);
// }

// /// nHk を計算して返す。
// /// 計算量は O(1)
// mint hom(int n, int k) {
//   return comb(n+k-1, k);
// }

int main() {
  int T;cin>>T;
  int m;cin>>m;
  auto nck = comb(5010,m);
  mint::set_mod(m);
  while(T--) {
    ll n;cin>>n;
    vector<ll> c(n);cin>>c;
    mint ans = 0;
    ans = 1;
    ll sum = 0;
    sum += c.at(0);
    reps(i,1,n) {
      ans *= nck.at(sum+c.at(i)).at(c.at(i));
      sum += c.at(i);
    }
    cout<<ans.val() << endl;
  }

  return 0;
}
