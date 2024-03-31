#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  ll n;cin>>n;
  vector<ll> c(n);cin>>c;
  vector<ll> x(n);cin>>x;
  rep(i,n) c.at(i)--,x.at(i)--;
  fenwick_tree<ll> ft(n);
  ll inv = 0;
  rep(i,n) {
    ft.add(x.at(i),1);
    inv += ft.sum(x.at(i)+1,n);
  }
  vector a(n,vector<ll>());
  rep(i,n) {
    a.at(c.at(i)).push_back(x.at(i));
  }
  rep(i,n) {
    vector<ll> arr = a.at(i);
    sort(all(arr));
    arr.erase(unique(all(arr)),arr.end());
    vector<ll> res(a.at(i).size());
    rep(j,a.at(i).size()) {
      res.at(j) = lower_bound(all(arr),a.at(i).at(j)) - arr.begin();
    }
    fenwick_tree<ll> t(arr.size());
    ll cnt = 0;
    rep(j,res.size()) {
      t.add(res.at(j),1);
      cnt += t.sum(res.at(j)+1,arr.size());
    }
    inv -= cnt;
  }
  cout << inv << endl;

  return 0;
}
