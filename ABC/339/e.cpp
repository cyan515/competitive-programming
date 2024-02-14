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

int op(int a,int b) {
  return max(a,b);
}

int e() {
  return 0;
}

int main() {
  int n;cin>>n;
  int d;cin>>d;
  vector<int> a(n);cin>>a;
  segtree<int,op,e> seg(500010);
  rep(i,500010) seg.set(i,0);
  rep(i,n) {
    int l = max(a.at(i)-d,0);
    int r = min(a.at(i)+d+1,500010);
    int res = seg.prod(l,r);
    seg.set(a.at(i),max(seg.get(a.at(i)),res+1));
  }
  int ans = 0;
  rep(i,500010) {
    ans = max(ans,seg.get(i));
  }
  cout << ans << endl;

  exit(0);
}
