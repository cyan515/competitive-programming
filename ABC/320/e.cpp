#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using rpqi = priority_queue<int, vector<int>, greater<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  ll n,m;cin>>n>>m;
  // time, in-or-out(0,1), when outed if in, weight
  vector<tuple<ll,ll,ll,ll>> event;
  rep(i,m) {
    ll t,w,s;cin>>t>>w>>s;
    event.emplace_back(t,1,-1,w);
    event.emplace_back(t+s,0,t,-1);
  }
  sort(all(event));
  set<int> row;
  map<ll,ll> out_memo;
  vector<ll> ans(n,0);
  rep(i,n) row.insert(i);
  rep(i,event.size()) {
    ll time = get<0>(event.at(i));
    ll io = get<1>(event.at(i));
    ll when_out = get<2>(event.at(i));
    ll weight = get<3>(event.at(i));
    if(io==0) {
      if(out_memo.find(when_out)==out_memo.end()) continue;
      row.insert(out_memo.at(when_out));
    } else {
      auto it = row.begin();
      if(it==row.end()) continue;
      int who = *it;
      row.erase(it);
      ans.at(who) += weight;
      out_memo[time] = who;
    }
  }
  rep(i,n) cout << ans.at(i) << endl;

  exit(0);
}
