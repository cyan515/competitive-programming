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
  int h,w;cin>>h>>w;
  int d;cin>>d;
  vector<string> s(h);cin>>s;
  int ans = 0;
  rep(xi,h) rep(xj,w) rep(yi,h) rep(yj,w) {
    if(pair(xi,xj)>=pair(yi,yj)) continue;
    if(s.at(xi).at(xj)=='#') continue;
    if(s.at(yi).at(yj)=='#') continue;
    auto t = s;
    rep(i,h) rep(j,w) {
      if(t.at(i).at(j)=='#') continue;
      if(abs(i-xi)+abs(j-xj)<=d) t.at(i).at(j)='o';
      if(abs(i-yi)+abs(j-yj)<=d) t.at(i).at(j)='o';
    }
    int cnt = 0;
    rep(i,h) rep(j,w) cnt += t.at(i).at(j)=='o';
    ans = max(ans,cnt);
  }
  cout << ans << endl;

  return 0;
}
