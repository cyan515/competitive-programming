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

int main() {
  int n;cin>>n;
  int m;cin>>m;
  string s;cin>>s;
  reverse(s.begin(),s.end());
  vector<int> c(n);
  rep(i,n) cin>>c.at(i),c.at(i)--;
  reverse(c.begin(),c.end());
  int fc = c.at(0);
  vector ch(m,queue<int>());
  vector p(m,queue<int>());
  rep(i,n) {
    ch.at(c.at(i)).push(s.at(i));
    if(i!=n-1) p.at(c.at(i)).push(c.at(i+1));
    else p.at(c.at(i)).push(-1);
  }
  rep(i,m) {
    ch.at(i).push(ch.at(i).front());
    ch.at(i).pop();
  }
  string ans = "";
  rep(i,n) {
    ans += ch.at(fc).front();
    ch.at(fc).pop();
    int tmp = p.at(fc).front();
    p.at(fc).pop();
    fc = tmp;
  }
  reverse(ans.begin(),ans.end());
  cout << ans << endl;

  exit(0);
}
