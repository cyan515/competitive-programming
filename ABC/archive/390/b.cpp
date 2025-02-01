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

int main() {
  int n;cin>>n;
  vector<ll> a(n);cin>>a;
  ll x,y;
  ll z = gcd(a.at(0),a.at(1));
  x = a.at(0)/z;
  y = a.at(1)/z;
  rep(i,n-1) {
    ll g = gcd(a.at(i),a.at(i+1));
    ll xx = a.at(i)/g;
    ll yy = a.at(i+1)/g;
    if(x!=xx||y!=yy) {
      cout << No << endl;
      return 0;
    }
  }
  cout << Yes << endl;
  
  return 0;
}
