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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  ll n,m;cin>>n>>m;
  ll cx,cy;cin>>cx>>cy;
  vector<ll> x(n),y(n);
  rep(i,n) cin>>x.at(i)>>y.at(i);
  map<ll,multiset<ll>> tate,yoko;
  rep(i,n) {
    tate[x.at(i)].insert(y.at(i));
    yoko[y.at(i)].insert(x.at(i));
  }
  int ans = 0;
  while(m--) {
    char d;cin>>d;
    ll c;cin>>c;
    ll dx,dy;
    if(d=='U') {
      dx = dir.at(0).first;
      dy = dir.at(0).second;
    }
    if(d=='D') {
      dx = dir.at(1).first;
      dy = dir.at(1).second;
    }
    if(d=='L') {
      dx = dir.at(3).first;
      dy = dir.at(3).second;
    }
    if(d=='R') {
      dx = dir.at(2).first;
      dy = dir.at(2).second;
    }
    dx *= c;
    dy *= c;
    if(dy==0) {
      // 横移動
      ll lw = min(cx,cx+dx);
      ll hi = max(cx,cx+dx);
      auto itt = yoko.find(cy);
      if(itt!=yoko.end()) {
        auto& st = (*itt).second;
        auto it = st.lower_bound(lw);
        while(it!=st.end()&&(*it)<=hi) {
          st.erase(it);
          auto tateit = tate[*it].find(cy);
          tate[*it].erase(tateit);
          ans++;
          it = st.lower_bound(lw);
        }
      }
    }
    if(dx==0) {
      // 縦移動
      ll lw = min(cy,cy+dy);
      ll hi = max(cy,cy+dy);
      auto itt = tate.find(cx);
      if(itt!=tate.end()) {
        auto& st = (*itt).second;
        auto it = st.lower_bound(lw);
        while(it!=st.end()&&(*it)<=hi) {
          st.erase(it);
          auto yokoit = yoko[*it].find(cx);
          yoko[*it].erase(yokoit);
          ans++;
          it = st.lower_bound(lw);
        }
      }
    }
    cx += dx;
    cy += dy;
  }
  cout << cx << " " << cy << " " << ans << endl;

  return 0;
}
