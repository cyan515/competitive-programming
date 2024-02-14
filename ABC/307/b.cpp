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
  vector<string> s(n);
  rep(i,n) cin>>s.at(i);
  bool ans = false;
  rep(i,n) rep(j,n) {
    if(i==j) continue;
    string t = s.at(i) + s.at(j);
    int len = t.length();
    bool flg = true;
    rep(k,len) flg &= t.at(k)==t.at(len-1-k);
    ans |= flg;
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  exit(0);
}
