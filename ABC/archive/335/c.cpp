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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int n;cin>>n;
  int Q;cin>>Q;
  vector<pair<int,int>> ans;
  rep(i,n) {
    ans.emplace_back(n-i,0);
  }
  int x = 1,y = 0;
  while(Q--) {
    int t;cin>>t;
    if(t==1) {
      char c;cin>>c;
      if(c=='R') x++;
      if(c=='L') x--;
      if(c=='U') y++;
      if(c=='D') y--;
      ans.emplace_back(x,y);
    } else {
      int p;cin>>p;
      cout << ans.at(ans.size()-p).first << " " << ans.at(ans.size()-p).second << endl;
    }
  }

  exit(0);
}
