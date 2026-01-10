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
  vector<int> a(n);cin>>a;
  map<int,ll> le,ri;
  rep(i,n) {
    ri[a.at(i)]++;
  }
  ll ans = 0;
  rep(j,n) {
    ri[a.at(j)]--;
    le[a.at(j)]++;
    if(a.at(j)%5) continue;
    ll y = a.at(j)/5;
    ll lcnt = le[y*3]*le[y*7];
    ll rcnt = ri[y*3]*ri[y*7];
    ans += lcnt + rcnt;
  }
  cout << ans << endl;

  return 0;
}
