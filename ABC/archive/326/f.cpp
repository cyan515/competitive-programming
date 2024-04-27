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
  int n;cin>>n;
  string r,c;cin>>r>>c;
  vector<string> ans(n,string(5,'.'));
  int r_mi = INF;
  int r_mi_idx = INF;
  set<int> c_end;
  rep(i,n) {
    bool flg = false;
    rep(j,n) {
      if(r.at(i)==c.at(j)&&c_end.find(j)==c_end.end()) {
        ans.at(i).at(j) = r.at(i);
        if(r_mi > j) {
          r_mi = j;
          r_mi_idx = i;
        }
        c_end.insert(j);
        flg = true;
        j=n;
        break;
      }
    }
    if(!flg) {
      if(c_end.empty()) {
        cout << "No" << endl;
        return 0;
      }
      auto it = c_end.begin();
      ans.at(i).at(*it) = r.at(i);
    }
  }
  rep(i,n) {
    if(c_end.count(i)==0) {
      ans.at(r_mi_idx).at(i) = c.at(i);
    }
  }
  cout << "Yes" << endl;
  rep(i,n) cout << ans.at(i) << endl;

  exit(0);
}
