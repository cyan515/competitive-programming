#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int Q;cin>>Q;
  multiset<int> ls;
  multiset<int> rs;
  rep(_,Q) {
    char c;int l,r;cin>>c>>l>>r;
    if(c=='+') {
      ls.insert(l);
      rs.insert(r);
    } else {
      ls.erase(ls.find(l));
      rs.erase(rs.find(r));
    }
    auto it = ls.end();
    if(rs.size()<=1) {
      cout << "NO" << endl;
      continue;
    }
    it--;
    if(*rs.begin()<*it) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  exit(0);
}
