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

int main() {
  int n;cin>>n;
  vector<string> s(n),t(n);cin>>s>>t;
  int ans = INF;
  rep(x,4) {
    int cnt = x;
    rep(i,n) rep(j,n) {
      if(s.at(i).at(j)!=t.at(i).at(j)) cnt++;
    }
    ans = min(ans,cnt);
    auto u = s;
    rep(i,n) rep(j,n) {
      u.at(j).at(n-1-i) = s.at(i).at(j);
    }
    swap(s,u);
  }
  cout << ans << endl;

  return 0;
}
