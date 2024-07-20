#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
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

int main() {
  int h,w;cin>>h>>w;
  int y;cin>>y;
  vector a(h,vector<int>(w));
  rep(i,h) cin>>a.at(i);
  vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1},};
  auto in = [&](unsigned s, unsigned t) -> bool {
    return s<h&&t<w;
  };
  priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;
  vector seen(h,vector(w,false));
  rep(i,h) rep(j,w) {
    if(i==0||i==h-1||j==0||j==w-1) {
      pq.push(tuple(a.at(i).at(j),i,j));
      seen.at(i).at(j) = true;
    }
  }
  int ans = h*w;
  rep(x,y) {
    while(pq.size()&&get<0>(pq.top())<=x+1) {
      ans--;
      auto [hight,i,j] = pq.top();pq.pop();
      for(auto [di,dj] : dir) {
        int ni = i+di;
        int nj = j+dj;
        if(!in(ni,nj)) continue;
        if(seen.at(ni).at(nj)) continue;
        seen.at(ni).at(nj) = true;
        pq.push(tuple(a.at(ni).at(nj),ni,nj));
      }
    }
    cout << ans << endl;
  }

  return 0;
}
