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
  ll n,m;cin>>n>>m;
  vector g(n,vector<int>());
  set<pair<int,int>> seenx;
  rep(i,m){
    int u,v;cin>>u>>v;u--;v--;
    if(u==v)continue;
    if(seenx.count(pair(u,v)))continue;
    seenx.insert(pair(u,v));
    g.at(u).push_back(v);
  }
  set<int>cur,nx;
  nx.insert(0);
  rep(i,n){
    if(!nx.count(i)){
      cout<<-1<<endl;
      continue;
    }
    nx.erase(i);
    cur.insert(i);
    queue<int>q;q.push(i);
    while(q.size()){
      int v=q.front();q.pop();
      for(auto nv:g.at(v)){
        if(nv>i){
          nx.insert(nv);
          continue;
        }
        if(cur.count(nv))continue;
        cur.insert(nv);
        q.push(nv);
      }
    }
    if(cur.size()==i+1){
      cout<<nx.size()<<endl;
    }else{
      cout<<-1<<endl;
    }
  }

  return 0;
}
