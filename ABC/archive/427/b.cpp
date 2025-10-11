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
  ll n;cin>>n;
  vector<ll> a(n+1,0);
  a.at(1) = 1;
  auto f = [&](ll x) -> ll {
    ll ret = 0;
    while(x) {
      ret += x%10;
      x /= 10;
    }
    return ret;
  };
  reps(i,1,n) {
    a.at(i+1) = a.at(i) + f(a.at(i));
  }
  cout << a.at(n) << endl;

  return 0;
}
