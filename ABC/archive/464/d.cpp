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
  int T;cin>>T;
  while(T--){
    ll n;cin>>n;
    string s;cin>>s;
    vector<ll>x(n),y(n,0);cin>>x;
    reps(i,1,n)cin>>y.at(i);
    // sunny=0, rainy=1
    vector dp(n+1,vector<ll>(2,-LINF));
    dp.at(0).at(0)=0;
    dp.at(0).at(1)=0;
    rep(i,n){
      if(s.at(i)=='S'){
        chmax(dp.at(i+1).at(0),dp.at(i).at(0));
        chmax(dp.at(i+1).at(0),dp.at(i).at(1)+y.at(i));
        chmax(dp.at(i+1).at(1),dp.at(i).at(0)-x.at(i));
        chmax(dp.at(i+1).at(1),dp.at(i).at(1)-x.at(i));
      }else{
        chmax(dp.at(i+1).at(0),dp.at(i).at(0)-x.at(i));
        chmax(dp.at(i+1).at(0),dp.at(i).at(1)+y.at(i)-x.at(i));
        chmax(dp.at(i+1).at(1),dp.at(i).at(0));
        chmax(dp.at(i+1).at(1),dp.at(i).at(1));
      }
    }
    ll ans=0;
    rep(j,2)chmax(ans,dp.at(n).at(j));
    cout<<ans<<endl;
  }

  return 0;
}
