#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using rpqi = priority_queue<int, vector<int>, greater<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

int main() {
  int ha,wa,hb,wb,hx,wx;

  cin >> ha >> wa;
  vector<string> a(ha);
  rep(i,ha) cin>>a.at(i);
  cin >> hb >> wb;
  vector<string> b(hb);
  rep(i,hb) cin>>b.at(i);
  cin >> hx >> wx;
  vector<string> x(hx);
  rep(i,hx) cin>>x.at(i);
  ll mih = INF;
  ll mah = 0;
  ll miw = INF;
  ll maw = 0;
  rep(i,ha) rep(j,wa) {
    if(a.at(i).at(j)=='#') {
      mih = min(mih, i);
      miw = min(miw, j);
      mah = max(mah, i);
      maw = max(maw, j);
    }
  }
  rep(i,ha) {
    if(i+mih>=ha) break;
    a.at(i) = a.at(i+mih);
  }
  ha = mah - mih + 1;
  a.resize(ha);
  wa = maw - miw + 1;
  rep(i,ha) a.at(i) = a.at(i).substr(miw,wa);

  mih = INF;
  mah = 0;
  miw = INF;
  maw = 0;
  rep(i,hb) rep(j,wb) {
    if(b.at(i).at(j)=='#') {
      mih = min(mih, i);
      miw = min(miw, j);
      mah = max(mah, i);
      maw = max(maw, j);
    }
  }
  rep(i,hb) {
    if(i+mih>=hb) break;
    b.at(i) = b.at(i+mih);
  }
  hb = mah - mih + 1;
  b.resize(hb);
  wb = maw - miw + 1;
  rep(i,hb) b.at(i) = b.at(i).substr(miw,wb);

  bool ans = false;
  rep(ai,hx-ha+1) rep(aj,wx-wa+1) rep(bi,hx-hb+1) rep(bj,wx-wb+1) {
    bool flg = true;
    rep(xi,hx) rep(xj,wx) {
      bool ablack = true;
      if(xi-ai<0||ha<=xi-ai) ablack=false;
      if(xj-aj<0||wa<=xj-aj) ablack=false;
      if(ablack && a.at(xi-ai).at(xj-aj)!='#') ablack=false;
      bool bblack = true;
      if(xi-bi<0||hb<=xi-bi) bblack=false;
      if(xj-bj<0||wb<=xj-bj) bblack=false;
      if(bblack && b.at(xi-bi).at(xj-bj)!='#') bblack=false;
      if(x.at(xi).at(xj)=='#') {
        if(!ablack && !bblack) flg = false;
      } else {
        if(ablack || bblack) flg = false;
      }
    }
    ans |= flg;
  }
  if(ans) cout << "Yes";
  else cout << "No";
  cout << endl;

  exit(0);
}
