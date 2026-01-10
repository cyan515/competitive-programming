#include <bits/stdc++.h>
#include <atcoder/modint>
#include <atcoder/segtree>
#include <atcoder/fenwicktree>
using namespace atcoder;
using namespace std;
using mint = modint998244353;
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
using S = mint;
S op(S a,S b) {
  return a+b;
}
S e() {
  return mint(0);
}

int main() {
  int n;cin>>n;
  vector<int> p(n);cin>>p;
  rep(i,n) p.at(i)--;
  // last-is-up, last-is-down
  vector seg(2,segtree<S,op,e>(n));
  fenwick_tree<mint> ft(n);
  rep(i,n) {
    {
      mint cnt = seg.at(0).get(p.at(i));
      cnt += seg.at(0).prod(0,p.at(i));
      cnt += seg.at(1).prod(0,p.at(i));
      cnt += ft.sum(0,p.at(i));
      seg.at(0).set(p.at(i),cnt);
    }
    {
      mint cnt = seg.at(1).get(p.at(i));
      cnt += seg.at(0).prod(p.at(i)+1,n);
      cnt += seg.at(1).prod(p.at(i)+1,n);
      seg.at(1).set(p.at(i),cnt);
    }
    // seg.at(0).set(p.at(i),seg.at(0).prod(0,p.at(i)))
    ft.add(p.at(i),1);
  }
  mint ans = seg.at(1).all_prod();
  cout << ans.val() << endl;

  return 0;
}
