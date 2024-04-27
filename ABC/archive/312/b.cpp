#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using rpqi = priority_queue<int, vector<int>, greater<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

int main() {
  int n,m;cin>>n>>m;
  vector<string> s(n);
  rep(i,n) cin>>s.at(i);
  rep(i,n) rep(j,m) {
    bool flg = true;
    rep(k,9) rep(l,9) {
      if(i+k==n || j+l==m) {
        flg=false;k=9;break;
      }
      if((k<3&&l<3)||(k>5&&l>5)) if(s.at(i+k).at(j+l)!='#') flg = false;
      if((k==3&&l<4)||(k<4&&l==3)||(k==5&&l>=5)||(k>=5&&l==5)) if(s.at(i+k).at(j+l)!='.') flg = false;
    }
    if(flg) cout << i+1 << " " << j+1 << endl;
  }

  exit(0);
}
