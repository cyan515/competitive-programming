#include <bits/stdc++.h>
// #include <atcoder/modint>
// using namespace atcoder;
using namespace std;
// using mint = modint998244353;
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

vector<vector<ll>> multiply(vector<vector<ll>>& a,vector<vector<ll>>& b) {
  ll n = a.size();
  vector ret(n, vector<ll>(n,-LINF));
  rep(i,n) rep(j,n) rep(k,n) {
    chmax(ret.at(i).at(j), a.at(i).at(k)+b.at(k).at(j));
  }
  return ret;
}

vector<vector<ll>> matrix_power(vector<vector<ll>> base, ll exp) {
  ll n = base.size();
  vector<vector<ll>> ret(n, vector<ll>(n,-LINF));
  rep(i,n) ret.at(i).at(i) = 0;
  while(exp>0) {
    if(exp%2==1) ret = multiply(ret,base);
    base = multiply(base,base);
    exp /= 2;
  }
  return ret;
}

int main() {
  ll h,w,k;cin>>h>>w>>k;
  ll si,sj;cin>>si>>sj;si--;sj--;
  vector<vector<ll>> a(h,vector<ll>(w));
  rep(i,h) cin>>a.at(i);

  ll n = h*w;
  vector<vector<ll>> t(n, vector<ll>(n,-LINF));
  vector<pair<int,int>> dir = {{0,1},{0,-1},{0,1},{0,-1},};
  auto in = [&](int x,int y) -> bool {
    return 0<=x&&x<h&&0<=y&&y<w;
  };
  auto conv = [&](int x,int y) -> int {
    return x*w+y;
  };
  rep(i,h) rep(j,w) {
    ll cur = conv(i,j);
    t.at(cur).at(cur) = a.at(i).at(j);
    for(auto [dx,dy] : dir) {
      int nx = i + dx;
      int ny = j + dy;
      if(!in(nx,ny)) continue;
      t.at(cur).at(conv(nx,ny)) = a.at(nx).at(ny);
    }
  }

  vector<vector<ll>> result = matrix_power(t, k);
  ll ans = -LINF;
  ll s = conv(si,sj);
  rep(i,n) {
    chmax(ans, result.at(s).at(i));
  }

  cout << ans << endl;

  return 0;
}
