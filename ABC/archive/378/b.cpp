#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
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
  int n;cin>>n;
  vector<ll> q(n),r(n);
  rep(i,n) cin>>q.at(i)>>r.at(i);
  int Q;cin>>Q;
  while(Q--) {
    int t,d;cin>>t>>d;t--;
    ll ok = INF;
    ll ng = -1;
    while(abs(ok-ng)>1) {
      ll mid = (ok+ng)/2;
      if(q.at(t)*mid+r.at(t)>=d) ok = mid;
      else ng = mid;
    }
    cout << q.at(t)*ok+r.at(t) << endl;
  }

  return 0;
}
