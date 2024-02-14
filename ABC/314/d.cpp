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
  string s;cin>>s;
  vector<int> ch(n,-1);
  int l = -2;
  int u = -2;
  int q;cin>>q;
  rep(i,q) {
    int t,x;char c;cin>>t>>x>>c;
    x--;
    if(t==1) {
      s.at(x) = c;
      ch.at(x) = i;
    } else if(t==2) {
      l = i;
    } else {
      u = i;
    }
  }
  string ans = "";
  rep(i,n) {
    if(ch.at(i)>max(l,u)) ans += s.at(i);
    else if(u>ch.at(i) && ch.at(i)>l) ans += (char)toupper(s.at(i));
    else if(l>ch.at(i) && ch.at(i)>u) ans += (char)tolower(s.at(i));
    else if(l>u) ans += (char)tolower(s.at(i));
    else ans += (char)toupper(s.at(i));
  }
  cout << ans << endl;

  exit(0);
}
