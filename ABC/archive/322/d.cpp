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
  vector<string> a(4);
  vector<string> b(4);
  vector<string> c(4);
  rep(i,4) cin>>a.at(i);
  rep(i,4) cin>>b.at(i);
  rep(i,4) cin>>c.at(i);
  auto f = [](vector<string>& mino) -> vector<string> {
    ll mii = INF;
    ll mai = -1;
    ll mij = INF;
    ll maj = -1;
    rep(i,4) rep(j,4) {
      if(mino.at(i).at(j)=='#') {
        mii = min(mii,i);
        mai = max(mai,i);
        mij = min(mij,j);
        maj = max(maj,j);
      }
    }
    vector<string> ret(mai-mii+1,"");
    reps(i,mii,mai+1) {
      reps(j,mij,maj+1) {
        ret.at(i-mii).push_back(mino.at(i).at(j));
      }
    }
    return ret;
  };
  a = f(a);
  b = f(b);
  c = f(c);
  auto rotate = [](vector<string>& mino) -> vector<string> {
    string str = "";
    rep(i,mino.size()) str += ".";
    vector<string> ret(mino.at(0).size(),str);
    rep(i,mino.size()) rep(j,mino.at(0).size()) {
      ret.at(j).at(mino.size()-1-i) = mino.at(i).at(j);
    }
    return ret;
  };
  auto update = [](vector<vector<char>>& sheet, vector<string> mino, int i_offset, int j_offset) -> bool {
    bool flg = true;
    rep(i,mino.size()) rep(j,mino.at(0).size()) {
      if(i_offset+i>=4||j_offset+j>=4) {
        flg = false;
        break;
      }
      if(sheet.at(i_offset+i).at(j_offset+j)=='#' && mino.at(i).at(j)=='#') flg=false;
      if(mino.at(i).at(j)=='#') sheet.at(i_offset+i).at(j_offset+j) = '#';
    }
    return flg;
  };
  bool ans = false;
  rep(ai,4) rep(aj,4) rep(bi,4) rep(bj,4) rep(ci,4) rep(cj,4) {
    rep(ar,4) rep(br,4) rep(cr,4) {
      bool flg = true;
      vector sheet(4,vector<char>(4,'.'));
      vector A = a;
      vector B = b;
      vector C = c;
      rep(i,ar) A=rotate(A);
      rep(i,br) B=rotate(B);
      rep(i,cr) C=rotate(C);
      flg &= update(sheet,A,ai,aj);
      flg &= update(sheet,B,bi,bj);
      flg &= update(sheet,C,ci,cj);
      rep(i,4) rep(j,4) flg &= sheet.at(i).at(j) == '#';
      ans |= flg;
    }
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  exit(0);
}
