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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  ll n,k;cin>>n>>k;
  vector<ll> a(n),b(n);
  rep(i,n)cin>>a.at(i)>>b.at(i);
  vector dp(n+1,vector(k+1,vector<ll>(2,-LINF)));
  dp.at(0).at(0).at(0)=0;
  rep(i,n)rep(kk,k+1){
    chmax(dp.at(i+1).at(kk).at(0),max(dp.at(i).at(kk).at(0),dp.at(i).at(kk).at(1))+a.at(i));
    if(kk+1<=k)chmax(dp.at(i+1).at(kk+1).at(1),dp.at(i).at(kk).at(0)+b.at(i));
    chmax(dp.at(i+1).at(kk).at(1),dp.at(i).at(kk).at(1)+b.at(i));
  }
  ll ans=-LINF;
  rep(i,n+1)rep(kk,k+1)rep(flg,2)chmax(ans,dp.at(i).at(kk).at(flg));
  cout<<ans<<endl;

  return 0;
}
