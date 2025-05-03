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
  int n;cin>>n;
  vector<int> c(n,0),a(n,0);
  a.at(0)++;
  reps(i,1,n) cin>>c.at(i);
  reps(i,1,n) cin>>a.at(i);
  vector g(n,vector<int>());
  rep(i,n) {
    reps(j,i-c.at(i),i) g.at(j).push_back(i);
  }
  vector<int> dist(n,INF);
  queue<int> q;
  rep(i,n) if(a.at(i)) {
    q.push(i);
    dist.at(i) = 0;
  }
  while(q.size()) {
    int v = q.front();q.pop();
    for(auto nv: g.at(v)) {
      if(dist.at(nv)!=INF) continue;
      dist.at(nv) = dist.at(v) + 1;
      q.push(nv);
    }
  }
  ll ans = 0;
  for(int i=n-1;i;i--) {
    if(a.at(i)==0) continue;
    int mi = INF;
    int pos = -1;
    reps(j,i-c.at(i),i) {
      if(a.at(j)!=0) {
        pos = j;
        break;
      }
      if(chmin(mi,dist.at(j))) pos = j;
    }
    a.at(pos) += a.at(i);
    a.at(i) = 0;
    ans++;
  }
  cout << ans << endl;

  return 0;
}
