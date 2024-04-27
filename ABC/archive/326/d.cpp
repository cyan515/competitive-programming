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
  vector<string> ans(n,string(n,'.'));
  auto f = [&](int ri,auto f) -> void {
    if(ri==n) {
      bool flg = true;
      rep(i,n) {
        rep(j,n) {
          if(ans.at(i).at(j)=='.') continue;
          if(ans.at(i).at(j)==r.at(i)) break;
          flg=false;
        }
      }
      rep(i,n) {
        rep(j,n) {
          if(ans.at(j).at(i)=='.') continue;
          if(ans.at(j).at(i)==c.at(i)) break;
          flg=false;
        }
      }
      if(flg) {
        cout << "Yes" << endl;
        rep(i,n) cout << ans.at(i) << endl;
        exit(0);
      }
      return;
    }
    vector<char> abc = {'A','B','C'};
    do {
      rep(i,n) ans.at(ri).at(i) = '.';
      auto g = [&](int ii,int idx,auto g) -> void {
        if(idx==3) {
          f(ri+1,f);
          return;
        }
        if(ii==n) {
          return;
        }
        g(ii+1,idx,g);
        rep(i,ri) {
          if(ans.at(i).at(ii)==abc.at(idx)) return;
        }
        ans.at(ri).at(ii) = abc.at(idx);
        g(ii+1,idx+1,g);
        ans.at(ri).at(ii) = '.';
      };
      g(0,0,g);
    } while(next_permutation(all(abc)));
    rep(i,n) ans.at(ri).at(i) = '.';
  };
  f(0,f);
  cout << "No" << endl;

  exit(0);
}
