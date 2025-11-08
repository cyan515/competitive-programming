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
  ll n,m,k;cin>>n>>m>>k;
  vector<ll> h(n),b(m);cin>>h>>b;
  sort(all(h));
  sort(all(b));
  bool ok = true;
  rep(i,k) {
    ok &= h.at(i) <= b.at(m-k+i);
  }
  cout<<(ok?Yes:No)<<endl;

  return 0;
}
