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

int main() {
  ll n,a;cin>>n>>a;
  queue<ll> q;
  rep(i,n) {
    ll t;cin>>t;
    q.push(t);
  }
  vector<ll> ans;
  ll t = 0;
  while(q.size()) {
    ll v = q.front();q.pop();
    if(t<v) t = v;
    t += a;
    ans.push_back(t);
  }
  rep(i,n) cout << ans.at(i) << endl;

  return 0;
}
