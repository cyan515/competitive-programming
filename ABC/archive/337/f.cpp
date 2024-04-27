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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int n,m,k;cin>>n>>m>>k;
  vector<int> c(n);cin>>c;
  rep(i,n) c.at(i)--;
  rep(i,n) c.push_back(c.at(i));
  int nn = n*2;
  vector<int> pref(nn+1,0);
  {
    vector<bool> seen(n,false);
    reps(i,1,nn) {
      pref.at(i) += pref.at(i-1);
      if(seen.at(c.at(i))) continue;
      pref.at(i)++;
      seen.at(c.at(i)) = true;
    }
  }
  vector<int> col_cnt(n,0);
  vector<int> ans(n,0);
  int cnt = 0;
  vector<bool> can(n,false);
  {
    int kind_cnt = 0;
    rep(i,n) {
      if(col_cnt.at(c.at(i))==0) kind_cnt++;
      if(kind_cnt<=m || can.at(c.at(i))) cnt++,can.at(c.at(i))=true;
      col_cnt.at(c.at(i))++;
    }
  }
  ans.at(0) = cnt;
  int idx = 0;
  reps(i,n,nn) {
    int it = lower_bound(all(pref),m+pref.at(i+1)) - pref.begin();
    it -= 1;
    it -= i-n;
  }
  
  rep(i,n) cout << ans.at(i) << endl;

  exit(0);
}
