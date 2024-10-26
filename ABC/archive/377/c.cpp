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
vector<pair<int,int>> dir = {{-1,2},{-1,-2},{1,2},{1,-2},{2,-1},{-2,-1},{2,1},{-2,1},};

int main() {
  ll n,m;cin>>n>>m;
  vector<int> a(m),b(m);
  rep(i,m) cin>>a.at(i)>>b.at(i);
  rep(i,m) a.at(i)--,b.at(i)--;
  set<pair<int,int>> ng;
  rep(i,m) {
    ng.insert(pair(a.at(i),b.at(i)));
  }
  auto in = [&](unsigned int i,unsigned int j) -> bool {
    return i<n&&j<n;
  };
  rep(i,m) {
    int x = a.at(i);
    int y = b.at(i);
    for(auto [dx,dy] : dir) {
      int nx = x+dx;
      int ny = y+dy;
      if(!in(nx,ny)) continue;
      ng.insert(pair(nx,ny));
    }
  }
  cout << n*n - ng.size() << endl;

  return 0;
}
