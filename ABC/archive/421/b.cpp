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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  ll x,y;cin>>x>>y;
  vector<ll> dp(10,0);
  dp.at(0) = x;
  dp.at(1) = y;
  auto f = [&](ll a, ll b) -> ll {
    string s = to_string(a+b);
    reverse(all(s));
    return stoll(s);
  };
  reps(i,2,10) {
    dp.at(i) = f(dp.at(i-2),dp.at(i-1));
  }
  cout << dp.back() << endl;

  return 0;
}
