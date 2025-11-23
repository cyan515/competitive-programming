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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};
// sum, cnt
using S = pair<ll,int>;
S op(S a,S b) {
  auto [s,t] = a;
  auto [x,y] = b;
  return pair(s+x,t+y);
}
S e() {
  return pair(0,0);
}

int main() {
  ll n,Q;cin>>n>>Q;
  vector<ll> a(n);cin>>a;
  atcoder::segtree<S,op,e> seg(500010);
  rep(i,n) {
    auto [x,y] = seg.get(a.at(i));
    seg.set(a.at(i),pair(x+a.at(i),y+1));
  }
  while(Q--) {
    int op;cin>>op;
    ll x,y;cin>>x>>y;
    if(op==1) {
      x--;
      auto [s,t] = seg.get(a.at(x));
      seg.set(a.at(x),pair(s-a.at(x),t-1));
      a.at(x) = y;
      auto [ss,tt] = seg.get(a.at(x));
      seg.set(a.at(x),pair(ss+a.at(x),tt+1));
    } else {
      if(x>=y) {
        cout<<x*n<<endl;
        continue;
      }
      ll ans = 0;
      {
        auto [s,t] = seg.prod(0,x);
        ans += t*x;
      }
      {
        auto [s,t] = seg.prod(y+1,500010);
        ans += t*y;
      }
      {
        auto [s,t] = seg.prod(x,y+1);
        ans += s;
      }
      cout << ans << endl;
    }
  }

  return 0;
}
