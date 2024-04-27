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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int n,t;cin>>n>>t;
  vector<ll> p(n,0);
  multiset<ll> ms;
  rep(i,n) ms.insert(0);
  int cnt = 1;
  rep(_,t) {
    ll a,b;cin>>a>>b;
    a--;
    auto it = ms.find(p.at(a));
    ll val = *it;
    p.at(a) += b;
    auto found = ms.find(p.at(a));
    if(found==ms.end()) cnt++;
    ms.erase(it);
    ms.insert(p.at(a));
    it = ms.find(val);
    if(it==ms.end()) cnt--;
    cout << cnt << endl;
  }

  return 0;
}
