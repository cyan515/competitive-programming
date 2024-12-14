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
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

vector<vector<long long>> comb(const int& n, const ll& mod) {
  vector<vector<long long>> v(n + 1,vector<long long>(n + 1, 0));
  for (int i = 0; i < v.size(); i++) {
    v[i][0] = 1;
    v[i][i] = 1;
  }
  for (int j = 1; j < v.size(); j++) {
    for (int k = 1; k < j; k++) {
      v[j][k] = (v[j - 1][k - 1] + v[j - 1][k])%mod;
    }
  }
  return v;
}
int main() {
  ll n;cin>>n;
  vector<ll> a(n);cin>>a;
  vector<pair<int,ll>> b(n);
  vector<ll> c;
  rep(i,n) {
    ll x = a.at(i);
    int cnt = 0;
    while(x%2==0) {
      cnt++;
      x/=2;
    }
    b.at(i) = pair(cnt,x);
    if(cnt==0) c.push_back(x);
  }
  sort(all(b));
  // sum, cnt
  vector<pair<ll,int>> vec(30);
  ll ans = 0;
  rep(i,n) {
    auto [fac,x] = b.at(i);
    ll y = 1;
    rep(_,fac) y*=2;
    rep(j,30) {
      if(y==1) break;
      ans += vec.at(j).first;
      ans += y*x*vec.at(j).second;
      y /= 2;
    }
    vec.at(fac).first += x;
    vec.at(fac).second++;
  }
  auto xxx = comb(30,LINF);
  rep(i,30) {
    ll xx = vec.at(i).first;
    while(xx%2==0&&xx>0) xx/=2;
    if(vec.at(i).second==0) continue;
    ans += xx*xxx.at(vec.at(i).second).at(2);
  }
  cout << ans << endl;

  return 0;
}
