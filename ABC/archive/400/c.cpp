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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};
// sqrt の誤差補正込みのやつ　平方数じゃない場合小数点以下切り捨て
long long sqr(const long long& x) {
  long long r = sqrt(x)-2;
  while((r+1)*(r+1)<=x)r++;
  return r;
}

int main() {
  ll n;cin>>n;
  ll x = 2;
  ll ans = 0;
  while(x<=n) {
    ll ok = 1;
    ll ng = INF;
    while(abs(ok-ng)>1) {
      ll mid = (ok+ng) / 2;
      bool of = false;
      ll y,z;
      of |= __builtin_mul_overflow(x,mid,&y);
      of |= __builtin_mul_overflow(y,mid,&z);
      if(of || x*mid*mid>n) ng = mid;
      else ok = mid;
    }
    ans += (ok+1)/2;
    x *= 2;
  }
  cout << ans << endl;

  return 0;
}
