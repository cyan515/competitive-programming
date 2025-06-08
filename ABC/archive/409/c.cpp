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
  ll n,l;cin>>n>>l;
  if(l%3!=0) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = 0;
  vector<ll> cnt(l,0);
  cnt.at(0)++;
  vector<ll> a(n,0);
  rep(i,n-1) {
    ll d;cin>>d;
    a.at(i+1) = a.at(i)+d;
    cnt.at(a.at(i+1)%l)++;
  }
  rep(i,l/3) {
    ans += cnt.at(i)*cnt.at(i+l/3)*cnt.at(i+l/3*2);
  }
  cout << ans << endl;

  return 0;
}
