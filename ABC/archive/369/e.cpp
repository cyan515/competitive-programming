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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

vector<vector<ll>> tsp(const vector<vector<ll>>& dist) {
  const ll LINF = 3001001001001001001;
  int n = dist.size();
  vector<vector<ll>> ret((1<<n),vector<ll>(n,LINF));
  rep(bit,1<<n) rep(from,n) {
    if(((bit&(1<<from))==0)&&(bit!=0)) continue;
    rep(to,n) {
      if(((bit&(1<<to))==0)&&(dist.at(from).at(to)<LINF)) {
        int v = (bit|(1<<to));
        ret.at(v).at(to) = min(ret.at(v).at(to),ret.at(bit).at(from)+dist.at(from).at(to));
      }
    }
  }
  return ret;
}

int main() {
  int n,m;cin>>n>>m;
  vector<tuple<int,int,ll>> es(m);
  rep(i,m) {
    int u,v,t;cin>>u>>v>>t;u--;v--;
    es.at(i) = tuple(u,v,t);
  }
  vector wf(n,vector<ll>(n,LINF));
  rep(i,n) wf.at(i).at(i) = 0;
  rep(i,m) {
    auto [u,v,t] = es.at(i);
    chmin(wf.at(u).at(v),t);
    chmin(wf.at(v).at(u),t);
  }
  rep(k,n) rep(i,n) rep(j,n) {
    if(wf.at(i).at(k)!=LINF&&wf.at(k).at(j)!=LINF) {
      chmin(wf.at(i).at(j),wf.at(i).at(k)+wf.at(k).at(j));
    }
  }
  int Q;cin>>Q;
  while(Q--) {
    int k;cin>>k;
    vector<int> b(k);cin>>b;
    rep(i,k) b.at(i)--;
    vector dp(n,vector<ll>(1<<k,LINF));
    dp.at(0).at(0) = 0;
    rep(bit,1<<k) rep(j,n) rep(i,k) {
      auto [u,v,t] = es.at(b.at(i));
      chmin(dp.at(u).at(bit|(1<<i)),dp.at(j).at(bit)+wf.at(j).at(v)+t);
      chmin(dp.at(v).at(bit|(1<<i)),dp.at(j).at(bit)+wf.at(j).at(u)+t);
    }
    ll ans = LINF;
    rep(i,n) {
      chmin(ans,dp.at(i).at((1<<k)-1)+wf.at(i).at(n-1));
    }
    cout << ans << endl;
  }

  return 0;
}
