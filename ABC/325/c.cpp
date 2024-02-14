#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int h,w;cin>>h>>w;
  vector<string> s(h);
  rep(i,h) cin>>s.at(i);
  vector<pair<int,int>> ps;
  rep(i,h) rep(j,w) if(s.at(i).at(j)=='#') ps.emplace_back(i,j);
  map<pair<int,int>,int> mp;
  {
    int i = 0;
    for(auto p : ps) {
      mp[p] = i;
      i++;
    }
  }
  dsu uf(ps.size());
  for(auto [i,j] : ps) {
    if(i+1< h && s.at(i+1).at(j)=='#') uf.merge(mp[make_pair(i,j)],mp[make_pair(i+1,j)]);
    if(j+1< w && s.at(i).at(j+1)=='#') uf.merge(mp[make_pair(i,j)],mp[make_pair(i,j+1)]);
    if(i+1< h && j-1>=0 && s.at(i+1).at(j-1)=='#') uf.merge(mp[make_pair(i,j)],mp[make_pair(i+1,j-1)]);
    if(i+1< h && j+1< w && s.at(i+1).at(j+1)=='#') uf.merge(mp[make_pair(i,j)],mp[make_pair(i+1,j+1)]);
  }
  cout << uf.groups().size() << endl;

  exit(0);
}
