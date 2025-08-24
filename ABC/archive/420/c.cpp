#include <bits/stdc++.h>
#include <atcoder/segtree>
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
using S = ll;
S op(S a, S b) {
  return a+b;
}
S e() {
  return 0;
}
int main() {
  int n,Q;cin>>n>>Q;
  vector<ll> a(n),b(n);cin>>a>>b;
  atcoder::segtree<S,op,e> seg(n);
  rep(i,n) seg.set(i,min(a.at(i),b.at(i)));
  while(Q--) {
    char c;cin>>c;
    ll x,v;cin>>x>>v;
    x--;
    if(c=='A') {
      a.at(x) = v;
    } else {
      b.at(x) = v;
    }
    seg.set(x,min(a.at(x),b.at(x)));
    cout << seg.all_prod() << endl;
  }

  return 0;
}
