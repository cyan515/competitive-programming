#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using rpqi = priority_queue<int, vector<int>, greater<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

int main() {
  ll n;cin>>n;
  ll k;cin>>k;
  set<pair<ll,ll>> ab;
  rep(i,n) {
    ll a,b;cin>>a>>b;
    auto itr = ab.find(make_pair(a,b));
    if(itr == ab.end()) ab.emplace(a,b);
    else ab.erase(itr), ab.emplace(a,(*itr).second+b);
  }
  ll sum = 0;
  for(auto ele:ab) {
    sum += ele.second;
  }
  if(sum<=k) {
    cout << 1 << endl;
    exit(0);
  }
  for(auto ele:ab) {
    sum -= ele.second;
    if(sum<=k) {
      cout << ele.first+1 << endl;
      exit(0);
    }
  }

  exit(0);
}
