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
  int n,Q;cin>>n>>Q;
  vector<ll> a(n);cin>>a;
  fenwick_tree<ll> ft(n);
  rep(i,n) ft.add(i,a.at(i));
  ll h = 0;
  while(Q--) {
    int op;cin>>op;
    if(op==1) {
      ll c;cin>>c;
      h += c;
      h %= n;
    } else {
      ll l,r;cin>>l>>r;l--;
      l += h;
      l %= n;
      r += h;
      r %= n;
      if(l<r) {
        cout << ft.sum(l,r) << endl;
      } else {
        cout << ft.sum(l,n) + ft.sum(0,r) << endl;
      }
    }
  }

  return 0;
}
