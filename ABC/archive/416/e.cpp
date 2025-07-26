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

int main() {
  int n,m;cin>>n>>m;
  vector g(n+1,vector<ll>(n+1,LINF));
  rep(i,n) g.at(i).at(i) = 0;
  rep(i,m) {
    int a,b;ll c;cin>>a>>b>>c;a--;b--;
    chmin(g.at(a).at(b),c);
    chmin(g.at(b).at(a),c);
  }
  int k;ll t;cin>>k>>t;
  vector<int> d(k);cin>>d;
  rep(i,k) d.at(i)--;
  rep(i,k) {
    g.at(d.at(i)).at(n) = t;
    g.at(n).at(d.at(i)) = 0;
  }
  rep(kk,n+1) rep(i,n+1) rep(j,n+1) {
    chmin(g.at(i).at(j),g.at(i).at(kk)+g.at(kk).at(j));
  }
  ll ans = 0;
  rep(i,n) rep(j,n) {
    if(g.at(i).at(j)==LINF) continue;
    ans += g.at(i).at(j);
  }
  int Q;cin>>Q;
  while(Q--) {
    int op;cin>>op;
    if(op==1) {
      int x,y;cin>>x>>y;x--;y--;
      ll z;cin>>z;
      chmin(g.at(x).at(y),z);
      chmin(g.at(y).at(x),z);
      for(auto kk : {x,y}) rep(i,n+1) rep(j,n+1) {
        ll bef = g.at(i).at(j);
        if(chmin(g.at(i).at(j),g.at(i).at(kk)+g.at(kk).at(j))) {
          if(bef==LINF) ans += g.at(i).at(j);
          else ans -= bef - g.at(i).at(j);
        }
      }
    } else if(op==2) {
      int x;cin>>x;x--;
      chmin(g.at(x).at(n),t);
      chmin(g.at(n).at(x),0LL);
      for(auto kk : {x,n}) rep(i,n+1) rep(j,n+1) {
        ll bef = g.at(i).at(j);
        if(chmin(g.at(i).at(j),g.at(i).at(kk)+g.at(kk).at(j))) {
          if(bef==LINF) ans += g.at(i).at(j);
          else ans -= bef - g.at(i).at(j);
        }
      }
    } else {
      ll anss = 0;
      rep(i,n) rep(j,n) if(g.at(i).at(j)!=LINF) anss += g.at(i).at(j);
      cout << anss << endl;
      // cout << ans << endl;
    }
  }

  return 0;
}
