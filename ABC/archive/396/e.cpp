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
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  ll n,m;cin>>n>>m;
  vector<ll> x(m),y(m),z(m);
  rep(i,m) cin>>x.at(i)>>y.at(i)>>z.at(i);
  rep(i,m) x.at(i)--,y.at(i)--;
  dsu uf(n);
  // edge, next node
  vector graph(n,vector<pair<int,int>>());
  rep(i,m) {
    uf.merge(x.at(i),y.at(i));
    graph.at(x.at(i)).push_back(pair(i,y.at(i)));
    graph.at(y.at(i)).push_back(pair(i,x.at(i)));
  }
  vector a(n,vector<int>(62,-1));
  for(auto g : uf.groups()) {
    rep(d,62) {
      queue<int> q;
      q.push(g.front());
      a.at(g.front()).at(d) = 0;
      while(q.size()) {
        int v = q.front();q.pop();
        for(auto [e,nv] : graph.at(v)) {
          if(a.at(nv).at(d)!=-1) {
            if((z.at(e)&(1LL<<d))==0) {
              if(a.at(v).at(d)!=a.at(nv).at(d)) {
                cout << -1 << endl;
                return 0;
              }
            } else {
              if(a.at(v).at(d)==a.at(nv).at(d)) {
                cout << -1 << endl;
                return 0;
              }
            }
            continue;
          }
          if((z.at(e)&(1LL<<d))>0) {
            a.at(nv).at(d) = 1-a.at(v).at(d);
          } else {
            a.at(nv).at(d) = a.at(v).at(d);
          }
          q.push(nv);
        }
      }
      int cnt = 0;
      for(auto ele : g) {
        cnt += a.at(ele).at(d);
      }
      if(cnt>g.size()/2) {
        for(auto ele : g) {
          a.at(ele).at(d) = 1-a.at(ele).at(d);
        }
      }
    }
  }
  rep(i,n) {
    if(i) cout << " ";
    ll ans = 0;
    rep(j,62) if(a.at(i).at(j)) ans += 1LL<<j;
    cout << ans;
  }
  cout << endl;

  return 0;
}
