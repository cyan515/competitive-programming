#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
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

int main() {
  ll n;cin>>n;
  vector<ll> h(n);cin>>h;
  vector<ll> ans(n,0);
  ll cur = 0;
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> q;
  rep(i,n) {
    ll cnt = 1;
    while(q.size()&&q.top().first<=h.at(i)) {
      auto [hh,ww] = q.top();
      cnt += ww;
      cur -= hh*ww;
      q.pop();
    }
    q.push(pair(h.at(i),cnt));
    cur += h.at(i)*cnt;
    ans.at(i) = cur+1;
  }
  rep(i,n) {
    if(i) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;

  return 0;
}
