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
  vector a(9,vector<int>(9));
  rep(i,9) rep(j,9) cin>>a.at(i).at(j);
  bool ans = true;
  rep(i,9) {
    set<int> st;
    rep(j,9) {
      st.insert(a.at(i).at(j));
    }
    if(st.size()!=9) ans = false;
  }
  rep(j,9) {
    set<int> st;
    rep(i,9) {
      st.insert(a.at(i).at(j));
    }
    if(st.size()!=9) ans = false;
  }
  rep(i,3) {
    rep(j,3) {
      set<int> st;
      rep(k,3) {
        rep(l,3) {
          st.insert(a.at(i*3+k).at(j*3+l));
        }
      }
      if(st.size()!=9) ans = false;
    }
  }
  
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  exit(0);
}
