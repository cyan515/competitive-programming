#include <bits/stdc++.h>
#include <atcoder/dsu>
using namespace atcoder;
using namespace std;
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
void YN(bool b){cout<<(b?"Yes":"No")<<endl;}

int main() {
  int n,Q;cin>>n>>Q;
  vector e(10,vector<pair<int,int>>());
  rep(i,n-1) {
    int a,b,c;cin>>a>>b>>c;a--;b--;c--;
    e.at(c).push_back(pair(a,b));
  }
  vector<dsu> ufs(10,0);
  rep(i,10) {
    dsu uf(n);
    rep(j,i+1) {
      for(auto [a,b] : e.at(j)) {
        if(uf.same(a,b)) continue;
        uf.merge(a,b);
      }
    }
    ufs.at(i) = uf;
  }
  rep(i,10) if(ufs.at(i).groups().size()==0) ufs.at(i) = dsu(n);
  vector<int> cnt(10,0);
  rep(i,10) {
    cnt.at(i) = (n-1-(ufs.at(i).groups().size()-1));
  }
  while(Q--) {
    int a,b,c;cin>>a>>b>>c;a--;b--;
    bool flg = false;
    reps(i,c-1,10) {
      if(flg) cnt.at(i)--;
      if(!ufs.at(i).same(a,b)) {
        flg = true;
      }
    }
    ll ans = 0;
    rep(i,10) {
      ans += cnt.at(i)*(i+1);
    }
    cout << ans << endl;
  }

  return 0;
}
