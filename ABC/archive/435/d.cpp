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
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n,m;cin>>n>>m;
  vector g(n,vector<int>());
  rep(i,m) {
    int u,v;cin>>u>>v;u--;v--;
    g.at(v).push_back(u);
  }
  vector<bool> b(n,false);
  int Q;cin>>Q;
  while(Q--) {
    int op;cin>>op;
    int x;cin>>x;x--;
    if(op==1) {
      if(b.at(x)) continue;
      queue<int> q;q.push(x);
      b.at(x) = true;
      while(q.size()) {
        int v = q.front();q.pop();
        for(auto nv:g.at(v)) {
          if(b.at(nv)) continue;
          b.at(nv)=true;
          q.push(nv);
        }
      }
    } else {
      cout<<(b.at(x)?Yes:No) << endl;
    }
  }

  return 0;
}
