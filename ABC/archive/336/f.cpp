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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int h,w;

vector<set<vector<vector<int>>>> bfs(vector<vector<int>>& init, int lim) {
  vector<pair<int,int>> xy = {{0,0},{1,0},{0,1},{1,1}};
  auto swp = [&](vector<vector<int>> state,int op) -> vector<vector<int>> {
    auto [x,y] = xy.at(op);
    rep(i,(h-1)/2) rep(j,w-1) {
      swap(state.at(i+x).at(j+y),state.at(h-2-i+x).at(w-2-j+y));
    }
    if((h-1)%2) {
      rep(j,(w-1)/2) {
        swap(state.at((h-1)/2+x).at(j+y),state.at((h-1)/2+x).at(w-2-j+y));
      }
    }
    return state;
  };
  vector<set<vector<vector<int>>>> ret(lim+1);
  ret.at(0).insert(init);
  map<vector<vector<int>>,int> dists;
  dists[init] = 0;
  queue<pair<vector<vector<int>>,int>> q;
  q.emplace(init,4);
  while(q.size()) {
    auto [v,op] = q.front();q.pop();
    int vd = dists.at(v);
    rep(i,4) {
      if(op==i) continue;
      auto nv = swp(v,i);
      if(dists.find(nv)!=dists.end()) continue;
      dists[nv] = vd+1;
      ret.at(vd+1).insert(nv);
      if(vd+1==lim) continue;
      q.emplace(nv,i);
    }
  }
  
  return ret;
}

int main() {
  cin>>h>>w;
  vector s(h,vector<int>(w));
  rep(i,h) cin>>s.at(i);
  vector t(h,vector<int>(w));
  rep(i,h) rep(j,w) t.at(i).at(j) = w*i+j+1;
  vector<set<vector<vector<int>>>> s_states = bfs(s,10);
  vector<set<vector<vector<int>>>> t_states = bfs(t,10);
  int ans = INF;
  rep(i,10) {
    if(s_states.at(i).count(t)) {
      ans = min(ans,int(i));
    }
  }
  map<vector<vector<int>>,int> mp;
  rep(i,11) {
    for(auto ele : t_states.at(i)) mp[ele] = i;
  }
  for(auto s_s : s_states.at(10)) {
    auto it = mp.find(s_s);
    if(it==mp.end()) continue;
    ans = min(ans,10+(*it).second);
  }
  if(ans==INF) ans=-1;
  cout << ans << endl;

  exit(0);
}
