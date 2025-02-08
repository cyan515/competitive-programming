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
  int n,m;cin>>n>>m;
  vector<string> s(n);cin>>s;
  vector<string> t(m);cin>>t;
  rep(a,n-m+1) rep(b,n-m+1) {
    bool ok = true;
    rep(i,m) rep(j,m) {
      ok &= s.at(a+i).at(b+j) == t.at(i).at(j);
    }
    if(ok) {
      cout << a+1 << " " << b+1 << endl;
      return 0;
    }
  }

  return 0;
}
