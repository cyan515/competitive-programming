#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}

int main() {
  int n;cin>>n;
  vector<string> ans(n,string(n,'.'));
  rep(i,n) rep(j,n) {
    ll mi = min({i,j,n-i-1,n-j-1});
    if(mi%2==0) ans.at(i).at(j) = '#';
  }
  rep(i,n) cout << ans.at(i) << endl;

  return 0;
}
