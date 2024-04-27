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
  int n;cin>>n;
  int m;cin>>m;
  multiset<ll> p;
  vector<pair<ll,ll>> dl(m);
  rep(i,n) {
    int price;cin>>price;
    p.insert(price);
  }
  rep(i,m)cin>>dl.at(i).second;
  rep(i,m)cin>>dl.at(i).first;
  sort(dl.begin(),dl.end());
  reverse(dl.begin(),dl.end());
  ll sum = 0;
  rep(i,m) {
    auto itr = p.lower_bound(dl.at(i).second);
    if(itr!=p.end()) {
      int tmp = *itr;
      tmp -= dl.at(i).first;
      sum += tmp;
      p.erase(itr);
    }
  }
  for(auto ele : p) sum += ele;
  cout << sum << endl;

  exit(0);
}
