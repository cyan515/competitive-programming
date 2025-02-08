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
  ll n,w;cin>>n>>w;
  vector<ll> x(n),y(n);
  rep(i,n) cin>>x.at(i)>>y.at(i);
  rep(i,n) x.at(i)--,y.at(i)--;
  // (y, index)
  vector qs(w,priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>>());
  rep(i,n) {
    qs.at(x.at(i)).push(pair(y.at(i),i));
  }
  vector<ll> vanish(n,LINF);
  ll cur = 0;
  while(1) {
    ll ma = -INF;
    bool ended = false;
    vector<int> idxs(w);
    rep(i,w) {
      if(qs.at(i).empty()) {
        ended = true;
        break;
      }
      auto [yy,idx] = qs.at(i).top();qs.at(i).pop();
      idxs.at(i) = idx;
      chmax(ma,yy-cur);
    }
    if(ended) break;
    cur += ma;
    rep(i,w) vanish.at(idxs.at(i)) = cur;
  }
  int Q;cin>>Q;
  while(Q--) {
    ll t,a;cin>>t>>a;a--;
    if(vanish.at(a)<t) cout << No << endl;
    else cout << Yes << endl;
  }

  return 0;
}
