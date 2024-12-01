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

using S = int;
S op(S a,S b) {
  return min(a,b);
}
S e() {
  return INF;
}

int main() {
  ll n,m;cin>>n>>m;
  vector<ll> a(n),b(m);cin>>a>>b;
  vector<pair<ll,int>> aa(n);
  rep(i,n) aa.at(i) = pair(a.at(i),i);
  sort(all(aa));
  segtree<S,op,e> st(n);
  rep(i,n) st.set(i,aa.at(i).second);
  rep(i,m) {
    auto it = upper_bound(all(aa),pair(b.at(i),INF));
    int idx = it - aa.begin();
    int ans = st.prod(0,it-aa.begin());
    if(ans==INF) ans=-1;
    else ans++;
    cout << ans << endl;
  }

  return 0;
}
