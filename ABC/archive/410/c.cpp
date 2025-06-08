#include <bits/stdc++.h>
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
  ll n,Q;cin>>n>>Q;
  vector<ll> a(n);
  rep(i,n) a.at(i) = i+1;
  ll cur = 0;
  while(Q--) {
    int op;cin>>op;
    if(op==1) {
      ll p,x;cin>>p>>x;p--;
      a.at((p-cur+n)%n) = x;
    } else if(op==2) {
      ll p;cin>>p;p--;
      cout << a.at((p-cur+n)%n) << endl;
    } else {
      ll k;cin>>k;
      k %= n;
      cur -= k;
      cur += n;
      cur %= n;
    }
  }

  return 0;
}
