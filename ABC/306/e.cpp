#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using rev_priority_queue = priority_queue<int, vector<int>, greater<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 998244353;

int main() {
  int n;cin>>n;
  int k;cin>>k;
  int Q;cin>>Q;
  vector<ll> a(n,0);
  multiset<ll> hi;
  for(int i=0;i<k;i++) hi.insert(0);
  multiset<ll> lo;
  for(int i=0;i<n-k;i++) lo.insert(0);
  ll sum = 0;
  while(Q--) {
    ll x,y;cin>>x>>y;x--;
    auto hii = hi.begin();
    if(*hii<=a.at(x)) {
      hi.erase(hi.find(a.at(x)));
      sum -= a.at(x);
    } else {
      lo.erase(lo.find(a.at(x)));
    }
    if(*hii<y) {
      hi.insert(y);
      sum += y;
    } else {
      lo.insert(y);
    }
    for(int i=0;i<k-(ll)hi.size();i++) {
      auto it = lo.end();
      it--;
      sum += *it;
      hi.insert(*it);
      lo.erase(it);
    }
    for(int i=0;i<n-k-(ll)lo.size();i++) {
      auto it = hi.begin();
      sum -= *it;
      lo.insert(*it);
      hi.erase(it);
    }
    a.at(x) = y;

    cout << sum << endl;
  }

  exit(0);
}
