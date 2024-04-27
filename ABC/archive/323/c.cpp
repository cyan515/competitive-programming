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

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n;cin>>n;
  int m;cin>>m;
  vector<int> a(m);
  rep(i,m) cin>>a.at(i);
  vector<string> s(n);
  rep(i,n) cin>>s.at(i);
  vector<int> p(n);
  vector<pair<int,int>> idx(m);
  rep(i,m) idx.at(i) = make_pair(a.at(i),i);
  sort(all(idx));
  reverse(all(idx));
  int ma = -1;
  rep(i,n) {
    int cnt = 0;
    rep(j,m) {
      if(s.at(i).at(j)=='o') cnt += a.at(j);
    }
    p.at(i) = cnt+i+1;
    ma = max((ll)ma,cnt+i+1);
  }
  int ma_cnt = 0;
  rep(i,n) if(p.at(i)==ma) ma_cnt++;
  rep(i,n) {
    if(p.at(i)==ma) {
      if(ma_cnt==1) cout << 0 << endl;
      else cout << 1 << endl;
    } else {
      int rest = ma - p.at(i);
      int plus = 0;
      int ans = 0;
      for(int j=0;j<m;j++) {
        int id = idx.at(j).second;
        if(s.at(i).at(id) == 'o') continue;
        plus += a.at(id);
        ans++;
        if(plus>rest) break;
      }
      cout << ans << endl;
    }
  }

  exit(0);
}
