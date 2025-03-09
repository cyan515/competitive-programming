#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
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
  string s;cin>>s;
  vector<ll> a(2,0),b(2,0);
  vector<ll> pref(n,0),suff(n,0);
  ll cur = 0;
  rep(i,n) {
    a.at(s.at(i)-'0')++;
    if(s.at(i)=='0') {
      cur += a.at(1);
    }
    pref.at(i) = cur;
  }
  cur = 0;
  for(int i=n-1;i>=0;i--) {
    b.at(s.at(i)-'0')++;
    if(s.at(i)=='0') {
      cur += b.at(1);
    }
    suff.at(i) = cur;
  }
  ll ans = min(suff.at(0),pref.at(n-1));
  rep(i,n-1) chmin(ans,pref.at(i)+suff.at(i+1));
  cout << ans << endl;

  return 0;
}
