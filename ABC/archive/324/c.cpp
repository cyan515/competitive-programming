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
  string t;cin>>t;
  vector<string> s(n);
  rep(i,n) cin>>s.at(i);
  vector<int> ans;
  rep(i,n) {
    bool flg = s.at(i)==t;
    rep(j,min(s.at(i).size(),t.size())) {
      if(s.at(i).at(j)!=t.at(j)) {
        if(s.at(i).size()==t.size()+1) {
          string u = s.at(i).substr(j+1);
          string v = t.substr(j,u.size()+1);
          flg |= u==v;
        } else if(s.at(i).size()+1==t.size()) {
          string u = s.at(i).substr(j);
          string v = t.substr(j+1,u.size()+1);
          flg |= u==v;
        } else {
          string u = s.at(i).substr(j+1);
          string v = t.substr(j+1,u.size()+1);
          flg |= u==v;
        }
        break;
      }
      if(flg) break;
      if(j==min(s.at(i).size(),t.size())-1) {
        flg |= abs((int)s.at(i).size()-(int)t.size()) == 1;
      }
    }
    if(flg) ans.push_back(i+1);
  }
  sort(all(ans));
  cout << ans.size() << endl;
  rep(i,ans.size()) cout << ans.at(i) << " ";
  cout << endl;

  exit(0);
}
