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

int main() {
  ll n,m;cin>>n>>m;
  vector<ll> a(n),b(m);cin>>a>>b;
  sort(all(a));
  sort(all(b));
  int ai = 0;
  int bi = 0;
  ll c = 0;
  while(1) {
    if(a.at(ai)<b.at(bi)) ai++;
    else {
      c += a.at(ai);
      ai++;
      bi++;
    }
    if(bi==m) {
      break;
    } else if(ai==n) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << c << endl;

  return 0;
}
