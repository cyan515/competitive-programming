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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  ll n,m;cin>>n>>m;
  vector<pair<ll,ll>> xa(m);
  rep(i,m) cin>>xa.at(i).first;
  rep(i,m) cin>>xa.at(i).second;
  sort(all(xa));
  vector<ll> x(m),a(m);
  rep(i,m) {
    auto [s,t] = xa.at(i);
    x.at(i) = s;
    a.at(i) = t;
  }
  if(x.front()!=1) {
    cout << -1 << endl;
    return 0;
  }
  x.push_back(n+1);
  a.push_back(1);
  ll ans = 0;
  rep(i,m) {
    if(i+a.at(i)-1>n) {
      cout << -1 << endl;
      return 0;
    }
    if(x.at(i)+a.at(i)-1==x.at(i+1)-1) {
      ans += (a.at(i)-1)*a.at(i)/2;
    } else if(x.at(i)+a.at(i)-1<x.at(i+1)-1) {
      cout << -1 << endl;
      return 0;
    } else {
      ll need = x.at(i+1)-x.at(i);
      ans += (need-1)*need/2;
      a.at(i+1) += a.at(i)-need;
      ans += (x.at(i+1)-x.at(i))*(a.at(i)-need);
    }
  }
  if(a.at(m)!=1) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }

  return 0;
}
