#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;
using namespace atcoder;
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
  ll n,Q;cin>>n>>Q;
  vector<ll> a(n);cin>>a;
  sort(all(a));
  fenwick_tree<ll> ft(n);
  rep(i,n) ft.add(i,a.at(i));
  while(Q--) {
    ll b;cin>>b;
    if(b==1) {
      cout << 1 << endl;
      continue;
    }
    if(b>a.back()) {
      cout << -1 << endl;
      continue;
    }
    int ok = n;
    int ng = -1;
    while(abs(ok-ng)>1) {
      int mid = (ok+ng)/2;
      if(a.at(mid)>=b) ok = mid;
      else ng = mid;
    }
    ll sum = 0;
    sum += ft.sum(0,ok);
    sum += (n-ok)*(b-1);
    sum++;
    cout << sum << endl;
  }

  return 0;
}
