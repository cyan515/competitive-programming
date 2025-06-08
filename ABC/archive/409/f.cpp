#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001*2;
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
  int n,Q;cin>>n>>Q;
  vector<int> x(n),y(n);
  rep(i,n) cin>>x.at(i)>>y.at(i);
  priority_queue<tuple<int,int,int>> q;
  rep(i,n) rep(j,n) {
    int dist = abs(x.at(i)-x.at(j))+abs(y.at(i)-y.at(j));
    q.push(tuple(-dist,i,j));
  }
  dsu uf(n+1500);
  while(Q--) {
    int t;cin>>t;
    if(t==1) {
      int a,b;cin>>a>>b;
      rep(i,n) {
        int dist = abs(a-x.at(i))+abs(b-y.at(i));
        q.push(tuple(-dist,i,n));
      }
      n++;
      x.push_back(a);
      y.push_back(b);
    } else if(t==2) {
      int dist = INF;
      while(q.size()&&dist==INF) {
        auto [d,u,v] = q.top();q.pop();
        if(uf.same(u,v)) continue;
        chmin(dist,-d);
        uf.merge(u,v);
      }
      while(q.size()&&get<0>(q.top())==-dist) {
        auto [d,u,v] = q.top();q.pop();
        uf.merge(u,v);
      }
      if(dist==INF) dist = -1;
      cout << dist << endl;
    } else {
      int u,v;cin>>u>>v;u--;v--;
      cout << (uf.same(u,v)?Yes:No) << endl;
    }
  }

  return 0;
}
