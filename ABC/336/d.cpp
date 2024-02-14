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
  int n;cin>>n;
  vector<int> a(n);cin>>a;
  vector<int> pref(n,0);
  vector<int> suff(n,0);
  pref.at(0) = 1;
  suff.at(n-1) = 1;
  reps(i,1,n) {
    if(a.at(i)>pref.at(i-1)) pref.at(i) = pref.at(i-1) + 1;
    else pref.at(i) = a.at(i);
  }
  for(int i=n-2;i>=0;i--) {
    if(a.at(i)>suff.at(i+1)) suff.at(i) = suff.at(i+1) + 1;
    else suff.at(i) = a.at(i);
  }
  int ans = 0;
  rep(i,n) {
    chmax(ans,min(pref.at(i),suff.at(i)));
  }
  cout << ans << endl;

  exit(0);
}
