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
  ll h,w,x;cin>>h>>w>>x;
  int si,sj;cin>>si>>sj;si--;sj--;
  vector s(h,vector<ll>(w));
  rep(i,h) cin>>s.at(i);
  priority_queue<tuple<ll,int,int>,vector<tuple<ll,int,int>>,greater<>> pq;
  vector seen(h,vector<bool>(w,false));
  seen.at(si).at(sj) = true;
  auto in = [&](unsigned int ii,unsigned int jj) -> bool {
    return ii<h&&jj<w;
  };
  for(auto [di,dj] : dir) {
    int ni = si+di;
    int nj = sj+dj;
    if(!in(ni,nj)) continue;
    pq.push(tuple(s.at(ni).at(nj),ni,nj));
    seen.at(ni).at(nj) = true;
  }
  ll ans = s.at(si).at(sj);
  while(pq.size()) {
    auto [a,vi,vj] = pq.top();pq.pop();
    if(a<(ans+x-1)/x) {
      ans += a;
    } else continue;
    for(auto [di,dj] : dir) {
      int ni = vi+di;
      int nj = vj+dj;
      if(!in(ni,nj)) continue;
      if(seen.at(ni).at(nj)) continue;
      pq.push(tuple(s.at(ni).at(nj),ni,nj));
      seen.at(ni).at(nj) = true;
    }
  }
  cout << ans << endl;

  return 0;
}
