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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

// ll nsolve(ll n,vector<ll> a) {
//   ll ans = 0;
//   rep(i,n) {
//     reps(j,i+1,n) {
//       ll tmp = 0;
//       reps(k,i,j+1) {
//         tmp ^= a.at(k);
//       }
//       ans += tmp;
//     }
//   }
//   return ans;
// }

// ll solve(ll n, vector<ll> a) {
  
//   ll ans = 0;
//   rep(i,n) ans-=a.at(i);
//   rep(bit,60) {
//     vector<ll> x(n+1,0);
//     rep(i,n) {
//       if(a.at(i)&(1LL<<bit)) x.at(i+1) = x.at(i)^1;
//       else x.at(i+1) = x.at(i);
//     }
//     ll one = 0;
//     rep(i,n+1) one += x.at(i) == 1;
//     ll zero = n-one;
//     rep(i,n) {
//       if(x.at(i)==1) ans += zero*(1LL<<bit);
//       else ans += one*(1LL<<bit);
//       if(x.at(i+1)==1) one--;
//       else zero--;
//     }
//   }
//   return ans;
// }

int main() {
  ll n;cin>>n;
  vector<ll> a(n);cin>>a;
  // rep(_,10000) {
  //   ll n = rand()%100;
  //   vector<ll> a(n);
  //   rep(i,n) a.at(i) = rand()%100000;
  //   ll x = solve(n,a);
  //   ll y = nsolve(n,a);
  //   if(x!=y) {
  //     cout << "hoge" << endl;
  //   }
  // }
  
  ll ans = 0;
  rep(i,n) ans-=a.at(i);
  rep(bit,60) {
    vector<ll> x(n+1,0);
    rep(i,n) {
      if(a.at(i)&(1LL<<bit)) x.at(i+1) = x.at(i)^1;
      else x.at(i+1) = x.at(i);
    }
    ll one = 0;
    rep(i,n+1) one += x.at(i) == 1;
    ll zero = n-one;
    rep(i,n) {
      if(x.at(i)==1) ans += zero*(1LL<<bit);
      else ans += one*(1LL<<bit);
      if(x.at(i+1)==1) one--;
      else zero--;
    }
  }
  cout << ans << endl;

  return 0;
}
