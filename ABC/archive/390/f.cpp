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
  ll n;cin>>n;
  vector<ll> a(n);cin>>a;
  vector<int> x(n+2,-1);
  ll ans = 0;
  ll cnt = 0;
  rep(i,n) {
    cnt = ans;
    int s = x.at(a.at(i)-1);
    int t = x.at(a.at(i));
    int u = x.at(a.at(i)+1);
    int ma = max({s,t,u});
    if(ma==-1) cnt += i+1;
    else {
      cnt += abs(i-ma);
      if(s==-1) s = INF;
      if(t==-1) t = INF;
      if(u==-1) u = INF;
      int mi = min({s,u});
      if(mi!=INF) cnt -= mi;
    }
    ans += cnt;
    x.at(a.at(i)) = i;
  }
  cout << ans << endl;

  return 0;
}
