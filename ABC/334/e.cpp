#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  int h,w;cin>>h>>w;
  vector<string> s(h);
  rep(i,h) cin>>s.at(i);
  dsu uf(h*w);
  auto f = [&](int i, int j) -> int {
    return w*i+j;
  };
  auto in = [&](int i, int j) -> bool {
    return 0<=i && i<h && 0<=j && j<w;
  };
  auto is_red = [&](int i, int j) -> bool {
    if(in(i,j)) return s.at(i).at(j)=='.';
    else return true;
  };
  int red = 0;
  rep(i,h) rep(j,w) {
    if(s.at(i).at(j)=='.') red++;
    if(j!=w-1) {
      if(s.at(i).at(j)=='#'&&s.at(i).at(j+1)=='#') uf.merge(f(i,j),f(i,j+1));
    }
    if(i!=h-1) {
      if(s.at(i).at(j)=='#'&&s.at(i+1).at(j)=='#') uf.merge(f(i,j),f(i+1,j));
    }
  }
  mint ans = 0;
  int cnt = uf.groups().size() - red;
  rep(i,h) rep(j,w) {
    if(s.at(i).at(j)=='#') continue;
    if(is_red(i,j-1)&&is_red(i,j+1)&&is_red(i-1,j)&&is_red(i+1,j)) {
      ans += cnt+1;
    } else {
      set<int> st;
      if(in(i,j-1) && s.at(i).at(j-1)=='#') {
        st.insert(uf.leader(f(i,j-1)));
      }
      if(in(i,j+1) && s.at(i).at(j+1)=='#') {
        st.insert(uf.leader(f(i,j+1)));
      }
      if(in(i-1,j) && s.at(i-1).at(j)=='#') {
        st.insert(uf.leader(f(i-1,j)));
      }
      if(in(i+1,j) && s.at(i+1).at(j)=='#') {
        st.insert(uf.leader(f(i+1,j)));
      }
      ans += cnt-st.size()+1;
    }
  }
  ans /= red;
  cout << ans.val() << endl;

  exit(0);
}

