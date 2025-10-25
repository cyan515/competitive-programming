#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
#include <atcoder/segtree>
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
  ll n;cin>>n;
  vector<ll> a(n);cin>>a;
  ll ans = 0;
  map<int,ll> le,ri;
  rep(i,n) {
    ri[a.at(i)]++;
  }
  rep(j,n) {
    ri[a.at(j)]--;
    {
      // i j 同じ
      ans += le[a.at(j)]*(n-j-1-ri[a.at(j)]);
    }
    {
      // j k 同じ
      ans += ri[a.at(j)]*(j-le[a.at(j)]);
    }
    le[a.at(j)]++;
  }
  vector x(n+1,vector<ll>());
  rep(i,n) {
    x.at(a.at(i)).push_back(i);
  }
  for(auto vec : x) {
    if(vec.size()<2) continue;
    rep(i,vec.size()-1) {
      ll s = vec.at(i);
      ll t = vec.at(i+1);
      ll cnt = t-s-1;
      ans += cnt*(i+1)*(vec.size()-i-1);
    }
  }
  cout << ans << endl;

  return 0;
}
