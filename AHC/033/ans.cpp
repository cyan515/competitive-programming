#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
// using mint =  modint1000000007;
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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

vector<string> solve(int& n,vector<vector<int>>& a) {
  vector<string> ans(n,"");
  
  rep(i,n) rep(j,n) if(j!=n-1) ans.at(i) += "PRRRRQLLLL"; else ans.at(i) += "PRRRRQ";
  
  return ans;
}

int main() {
  int n;cin>>n;
  vector a(n,vector<int>(n));
  rep(i,n) cin>>a.at(i);
  auto ans = solve(n,a);
  rep(i,n) cout << ans.at(i) << endl;
  
  return 0;
}
