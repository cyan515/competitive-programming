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

int main() {
  ll n;cin>>n;
  int Q;cin>>Q;
  int ans = 0;
  vector<int> pos(n);
  vector<int> cnt(n,1);
  rep(i,n) pos.at(i) = i;
  while(Q--) {
    int t;cin>>t;
    if(t==1) {
      ll p,h;cin>>p>>h;p--;h--;
      ll fpos = pos.at(p);
      ll fcnt = cnt.at(pos.at(p));
      ll tcnt = cnt.at(h);
      pos.at(p) = h;
      cnt.at(fpos)--;
      cnt.at(h)++;
      if(tcnt==1) ans++;
      if(fcnt==2) ans--;
    } else {
      cout << ans << endl;
    }
  }

  return 0;
}
