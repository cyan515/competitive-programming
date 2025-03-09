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
  ll n,m;cin>>n>>m;
  vector<ll> b(n),w(m);cin>>b>>w;
  sort(b.rbegin(),b.rend());
  sort(w.rbegin(),w.rend());
  rep(i,n-1) b.at(i+1) += b.at(i);
  rep(i,m-1) w.at(i+1) += w.at(i);
  for(int i=n-2;i>=0;i--) b.at(i) = max(b.at(i),b.at(i+1));
  ll ans = max(b.at(0),0LL);
  rep(i,min(n,m)) {
    ans = max(ans,b.at(i)+w.at(i));
  }
  cout << ans << endl;

  return 0;
}
