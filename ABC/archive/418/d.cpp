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
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  ll n;cin>>n;
  string t;cin>>t;
  ll ans = 0;
  int zero = 0;
  vector<int> x(2,0);
  rep(i,n) {
    if(t.at(i)=='0') zero++;
    x.at(zero%2)++;
  }
  rep(i,n) {
    if(t.at(i)=='0') {
      swap(x.at(0),x.at(1));
      x.at(0)--;
      ans += x.at(1);
    } else {
      ans += x.at(0);
      x.at(0)--;
    }
  }
  cout << ans << endl;

  return 0;
}
