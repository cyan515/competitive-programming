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

ll solve(int n,vector<ll>& t,vector<ll>& d) {
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> q;
  priority_queue<ll,vector<ll>,greater<>> dead_line;
  rep(i,n) q.emplace(t.at(i),d.at(i));
  ll now = 0;
  ll ans = 0;
  while(q.size()) {
    while(q.size() && now>=q.top().first) {
      dead_line.push(q.top().second);
      q.pop();
    }
    if(dead_line.empty()) {
      now = q.top().first;
      dead_line.push(q.top().second);
      q.pop();
      while(q.size() && now>=q.top().first) {
        dead_line.push(q.top().second);
        q.pop();
      }
    }
    while(dead_line.size() && dead_line.top()>=now) {
      ans++;
      now++;
      dead_line.pop();
      while(dead_line.size() && dead_line.top()<now) dead_line.pop();
      while(q.size() && now>=q.top().first) {
        dead_line.push(q.top().second);
        q.pop();
      }
    }
  }
  return ans;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll n;cin>>n;
  vector<ll> t(n);
  vector<ll> d(n);
  rep(i,n) cin>>t.at(i)>>d.at(i);
  rep(i,n) d.at(i) += t.at(i);
  vector<pair<ll,ll>> v(n);
  rep(i,n) v.at(i).first = t.at(i),v.at(i).second = d.at(i);
  ll ans = solve(n,t,d);
  cout << ans << endl;

  exit(0);
}
