#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  string s;cin>>s;
  map<char,int> mp;
  char c;
  rep(i,s.size()) {
    mp[s.at(i)]++;
  }
  for(auto [k,v]:mp) {
    if(v==1) c = k;
  }
  int ans;
  rep(i,s.size()) {
    if(s.at(i)==c) cout << i+1 << endl;
  }

  return 0;
}
