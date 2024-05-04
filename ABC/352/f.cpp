#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  ll n,m;cin>>n>>m;
  map<pair<ll,ll>,ll> w;
  dsu uf(n);
  rep(i,m) {
    ll a,b,c;cin>>a>>b>>c;a--;b--;
    w[pair(a,b)] = c;
    uf.merge(a,b);
  }
  vector ans(n,vector<ll>());
  vector<vector<int>> ps;
  for(auto g : uf.groups()) {
    if(g.size()==1) continue;
    ps.push_back(g);
  }
  sort(all(ps));
  do {
    vector<ll> row(n,-1);
    auto f = [&](auto f,int idx) -> void {
      if(idx==ps.size()) {
        rep(i,n) if(row.at(i)!=-1) ans.at(row.at(i)).push_back(i+1);
        return;
      }
      auto p = ps.at(idx);
      rep(i,n) {
        bool ok = true;
        map<int,int> mp;
        auto ele = p.front();
        mp[i] = ele;
        vector<int> dists(p.size(),vector<int>(p.size(),INF));
        rep(i,dists.size()) dists.at(i).at(i)=0;
        
        for(auto eee: p) {
          
        }
        dists.at(0) = 0;
        rep(j,p.size()) {
        }
        if(ok) {
          for(auto [k,v] : mp) {
            row.at(k) = v;
          }
          f(f,idx+1);
          for(auto [k,v] : mp) {
            row.at(k) = -1;
          }
        }
      }
    };
  } while(next_permutation(all(ps)));
  
  rep(i,n) {
    if(i) cout << " ";
    if(ans.at(i).size()==1) {
      cout << ans.at(i).front();
    } else {
      cout << -1;
    }
  }
  cout << endl;

  return 0;
}
