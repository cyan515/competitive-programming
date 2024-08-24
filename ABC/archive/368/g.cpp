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
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int n;cin>>n;
  vector<ll> a(n),b(n);cin>>a>>b;
  int Q;cin>>Q;
  while(Q--) {
    int t;cin>>t;
    if(t==1) {
      int i;cin>>i;i--;cin>>a.at(i);
    } else if(t==2) {
      int i;cin>>i;i--;cin>>b.at(i);
    } else {
      int l,r;cin>>l>>r;l--;
      
    }
  }

  return 0;
}
