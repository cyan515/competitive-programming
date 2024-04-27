#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 1000000007;

int main() {
  string s;cin>>s;
  int n = s.length();
  vector<bool> even(10,true);
  map<vector<bool>, ll> mp;
  mp[even]++;
  for(int i=0;i<n;i++) {
    int num = s.at(i) - '0';
    even.at(num) = !even.at(num);
    mp[even]++;
  }

  ll ans = 0;
  for(auto a : mp) {
    ans += a.second*(a.second-1)/2;
  }

  cout << ans << endl;

  exit(0);
}
