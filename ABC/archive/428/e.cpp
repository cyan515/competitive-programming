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
  int n;cin>>n;
  vector g(n,vector<int>());
  rep(i,n-1) {
    int a,b;cin>>a>>b;a--;b--;
    g.at(a).push_back(b);
    g.at(b).push_back(a);
  }
  int x,y;
  {
    queue<int> q;
    q.push(0);
    vector<int> dist(n,INF);
    dist.at(0) = 0;
    while(q.size()) {
      int v = q.front();q.pop();
      for(auto nv:g.at(v)) {
        if(dist.at(nv)!=INF) continue;
        dist.at(nv) = dist.at(v)+1;
        q.push(nv);
      }
    }
    int ma = *max_element(all(dist));
    rep(i,n) if(ma==dist.at(i)) x = i;
  }
  vector<int> dist_x(n,INF);
  {
    queue<int> q;
    q.push(x);
    dist_x.at(x) = 0;
    while(q.size()) {
      int v = q.front();q.pop();
      for(auto nv:g.at(v)) {
        if(dist_x.at(nv)!=INF) continue;
        dist_x.at(nv) = dist_x.at(v)+1;
        q.push(nv);
      }
    }
    int ma = *max_element(all(dist_x));
    rep(i,n) if(ma==dist_x.at(i)) y = i;
  }
  vector<int> dist_y(n,INF);
  {
    queue<int> q;
    q.push(y);
    dist_y.at(y) = 0;
    while(q.size()) {
      int v = q.front();q.pop();
      for(auto nv: g.at(v)) {
        if(dist_y.at(nv)!=INF) continue;
        q.push(nv);
        dist_y.at(nv) = dist_y.at(v) + 1;
      }
    }
    int ma = *max_element(all(dist_y));
    rep(i,n) if(ma==dist_y.at(i)) x = i;
  }
  x++;
  y++;
  rep(i,n) {
    if(dist_x.at(i)>dist_y.at(i)) cout << x << endl;
    else if(dist_x.at(i)<dist_y.at(i)) cout << y << endl;
    else cout << max(x,y) << endl;
  }

  return 0;
}
