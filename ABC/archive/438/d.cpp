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
  vector<ll> a(n),b(n),c(n);cin>>a>>b>>c;
  vector dp(n,vector<ll>(3,-LINF));
  dp.at(0).at(0) = a.at(0);
  reps(i,1,n) {
    chmax(dp.at(i).at(0),dp.at(i-1).at(0)+a.at(i));
    chmax(dp.at(i).at(1),dp.at(i-1).at(0)+b.at(i));
    chmax(dp.at(i).at(1),dp.at(i-1).at(1)+b.at(i));
    chmax(dp.at(i).at(2),dp.at(i-1).at(1)+c.at(i));
    chmax(dp.at(i).at(2),dp.at(i-1).at(2)+c.at(i));
  }
  cout << dp.at(n-1).at(2) << endl;

  return 0;
}
