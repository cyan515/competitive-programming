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
  ll n;cin>>n;
  ll m;cin>>m;
  vector<ll> a(m),b(m),c(m);
  rep(i,m) {
    cin>>a.at(i)>>b.at(i);a.at(i)--;b.at(i)--;c.at(i)=i;
  }
  dsu uf(n);
  vector<tuple<int,int,int>> rest;
  rep(i,m) {
    if(uf.same(a.at(i),b.at(i))) {
      rest.push_back(tuple(a.at(i),b.at(i),c.at(i)));
    } else {
      uf.merge(a.at(i),b.at(i));
    }
  }
  auto g = uf.groups();
  if(g.size()==1) {
    cout << 0 << endl;
    return 0;
  } else cout << g.size()-1 << endl;
  map<int,vector<tuple<int,int,int>>> es;
  rep(i,rest.size()) {
    auto [x,y,z] = rest.at(i);
    es[uf.leader(x)].push_back(tuple(x,y,z));
  }
  set<int> leaders;
  rep(i,g.size()) {
    int v = g.at(i).front();
    es[uf.leader(v)];
    leaders.insert(uf.leader(v));
  }
  for(auto [leader,vec] : es) {
    if(leaders.count(leader)==0) continue;
    queue<tuple<int,int,int>> q;
    for(auto vv:vec) q.push(vv);
    while(leaders.size()>1&&q.size()) {
      auto [x,y,z] = q.front();q.pop();
      int l = *leaders.begin();
      if(leader==l) {
        auto it = leaders.begin();it++;
        l = *it;
      }
      cout << z+1 << " " << y+1 << " " << l+1 << endl;
      for(auto vv:es[l]) q.push(vv);
      leaders.erase(l);
    }
  }

  return 0;
}
