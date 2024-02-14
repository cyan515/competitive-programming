#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int n;cin>>n;
  vector<ll> q(n),a(n),b(n);cin>>q>>a>>b;
  int ma = 0;
  int MA = 1000001;
  rep(i,MA) {
    bool aflg = true;
    rep(j,n) {
      aflg &= q.at(j)-a.at(j)*i>=0;
    }
    if(!aflg) continue;
    int ok = 0;
    int ng = MA;
    while(abs(ok-ng)>1) {
      ll mid = (ok+ng)/2;
      bool flg = true;
      rep(j,n) {
        flg &= q.at(j)-a.at(j)*i>=b.at(j)*mid;
      }
      if(flg) ok = mid;
      else ng = mid;
    }
    ma = max(ma,(int)i+ok);
  }
  cout << ma << endl;

  exit(0);
}
