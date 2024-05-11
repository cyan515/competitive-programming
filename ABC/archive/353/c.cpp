#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const ll MOD = 100000000LL;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

ll solve(ll n,vector<ll> a) {
  sort(all(a));
  vector<ll> pref(n+1,0);
  rep(i,n) pref.at(i+1) = pref.at(i)+a.at(i);
  ll ans = 0;
  rep(i,n) {
    ll idx = lower_bound(all(a),MOD-a.at(i)) - a.begin();
    if(idx>i) {
      ans += pref.at(idx)-pref.at(i+1);
      ans += a.at(i)*(idx-i-1);
      ans += (pref.at(n)-pref.at(idx)+a.at(i)*(n-idx))-MOD*(n-idx);
    } else {
      ans += (pref.at(n)-pref.at(i+1)+a.at(i)*(n-i-1))-MOD*(n-i-1);
    }
  }
  return ans;
}

ll naive(ll n,vector<ll> a) {
  ll ans = 0;
  rep(i,n) reps(j,i+1,n) {
    ans += (a.at(i)+a.at(j))%MOD;
  }
  return ans;
}

int main() {
  ll n;cin>>n;
  vector<ll> a(n);cin>>a;
  cout << solve(n,a) << endl;
  // int n=3;
  // rep(i,10000) {
  //   vector<ll> a(n);
  //   rep(j,n) a.at(j) = random()%100000000;
  //   // vector<ll> a = {94320152, 92532621, 62924393};
  //   int my = solve(n,a);
  //   int ni = naive(n,a);
  //   if(my!=ni) {
  //     int x = 0;
  //   }
  // }

  return 0;
}
