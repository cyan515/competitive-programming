#include <bits/stdc++.h>
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

void solve() {
  int n;cin>>n;
  vector<ll> a(n);cin>>a;
  auto nx = [&](int x) -> int {
    return (x+1)%n;
  };
  auto pv = [&](int x) -> int {
    return (x-1+n)%n;
  };
  int zero;
  rep(i,n) {
    a.at(nx(i)) -= a.at(i);
    chmax(a.at(nx(i)),0LL);
    if(a.at(nx(i))==0) zero = nx(i);
  }
  vector<int> cnt(n,0);
  cnt.at(nx(zero)) = INF;
  for(int i=nx(zero);i!=zero;i=nx(i)) {
    if(cnt.at(pv(i))==INF) {
      int alive = 0;
      int dead = INF+1;
      while(abs(alive-dead)>1) {
        ll mid = (alive+dead) / 2;
        if(a.at(nx(i))-mid*a.at(i)>0) alive = mid;
        else dead = mid;
      }
      cnt.at(nx(i)) = alive;
    } else {
      int alive = 0;
      int dead = INF+1;
      while(abs(alive-dead)>1) {
        ll mid = (alive+dead)/2;
        if(mid>cnt.at(i)) {
          
        } else {
          
        }
      }
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t;cin>>t;
  while(t--) solve();

  return 0;
}
