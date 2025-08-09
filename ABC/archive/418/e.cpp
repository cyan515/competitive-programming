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
  vector<ll> x(n),y(n);
  rep(i,n) cin>>x.at(i)>>y.at(i);
  auto conv = [&](ll xx, ll yy) -> ll {
    return xx * 100000000LL + yy;
  };
  unordered_map<ll,ll> mp;
  map<pair<ll,ll>,ll> mpp;
  ll z = 0;
  rep(i,n) reps(j,i+1,n) {
    ll dx = x.at(j)-x.at(i);
    ll dy = y.at(j)-y.at(i);
    ll dz = dx*dx+dy*dy;
    if(dx==0) {
      mp[conv(0,1)]++;
      mpp[pair(conv(0,1),dz)]++;
    } else if(dy==0) {
      mp[conv(1,0)]++;
      mpp[pair(conv(1,0),dz)]++;
    } else {
      ll g = gcd(abs(dx),abs(dy));
      dx /= g;
      dy /= g;
      if(dx<0) {
        dx *= -1;
        dy *= -1;
      }
      mp[conv(dx,dy)]++;
      mpp[pair(conv(dx,dy),dz)]++;
    }
  }
  ll ans = 0;
  for(auto [k,v] : mp) {
    ans += v*(v-1)/2;
  }
  for(auto [k,v] : mpp) {
    z += v*(v-1)/2;
  }
  z /= 2;
  cout << ans - z << endl;

  return 0;
}
