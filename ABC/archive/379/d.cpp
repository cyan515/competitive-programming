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

int main() {
  int Q;cin>>Q;
  map<ll,int> mp;
  ll cur = 0;
  while(Q--) {
    int w;cin>>w;
    if(w==1) {
      mp[cur]++;
    } else if(w==2) {
      ll t;cin>>t;
      cur += t;
    } else {
      ll h;cin>>h;
      ll ans = 0;
      while(mp.size()&&(*mp.begin()).first<=cur-h) {
        ans += (*mp.begin()).second;
        mp.erase(mp.begin());
      }
      cout << ans << endl;
    }
  }

  return 0;
}
