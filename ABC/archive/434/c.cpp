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
  int T;cin>>T;
  while(T--) {
    ll n,h;cin>>n>>h;
    vector<ll> t(n),l(n),u(n);
    rep(i,n) cin>>t.at(i)>>l.at(i)>>u.at(i);
    ll cl = h;
    ll cu = h;
    ll ct = 0;
    bool ok = true;
    rep(i,n) {
      ll dt = t.at(i)-ct;
      ll nl = cl - dt;
      ll nu = cu + dt;
      if(nu < l.at(i) || nl > u.at(i)) {
        ok = false;
        break;
      }
      cu = min(nu,u.at(i));
      cl = max(nl,l.at(i));
      if(cu<=0) cu = 0;
      if(cl<=0) cl = 0;
      ct = t.at(i);
    }
    cout << (ok?Yes:No) << endl;
  }

  return 0;
}
