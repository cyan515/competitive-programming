#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
const string Yes = "Yes";
const string No = "No";
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n,m;cin>>n>>m;
  vector<ll> p(n),v(n);
  rep(i,n) cin>>p.at(i)>>v.at(i);
  vector ldp(n+1,vector<ll>(m+1,-LINF));
  ldp.at(0).at(0) = 0;
  rep(i,n) rep(j,m+1) {
    chmax(ldp.at(i+1).at(j),ldp.at(i).at(j));
    if(j+p.at(i)<=m) chmax(ldp.at(i+1).at(j+p.at(i)),ldp.at(i).at(j)+v.at(i));
  }
  ll ma = -LINF;
  rep(j,m+1) chmax(ma,ldp.at(n).at(j));
  vector dp(n+1,vector<ll>(m+1,-LINF));
  rep(j,m+1) if(ldp.at(n).at(j)==ma) dp.at(n).at(j) = ma;
  vector<bool> up(n,false);
  vector<bool> stay(n,false);
  for(int i=n;i>0;i--) rep(j,m+1) {
    if(dp.at(i).at(j)==-LINF) continue;
    if(dp.at(i).at(j)==ldp.at(i-1).at(j)) {
      stay.at(i-1) = true;
      dp.at(i-1).at(j) = dp.at(i).at(j);
    }
    if(j-p.at(i-1)>=0 && dp.at(i).at(j)-v.at(i-1)==ldp.at(i-1).at(j-p.at(i-1))) {
      up.at(i-1) = true;
      dp.at(i-1).at(j-p.at(i-1)) = ldp.at(i-1).at(j-p.at(i-1));
    }
  }
  rep(i,n) {
    if(up.at(i)&&stay.at(i)) cout << "B";
    else if(up.at(i)) cout << "A";
    else cout << "C";
  }
  cout << endl;

  return 0;
}
