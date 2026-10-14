#include <bits/stdc++.h>
#include <atcoder/modint>
using mint=atcoder::modint998244353;
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
  string s;cin>>s;
  int n=s.size();
  vector<int>dsts(n,0);
  vector<int>mds(n,0);
  rep(i,n){
    dsts.at(i)=dsts.at(i)|(1<<(s.at(i)-'0'));
    if(i)dsts.at(i)=dsts.at(i)|dsts.at(i-1);
    mds.at(i)+=mds.at(i)+s.at(i)-'0';
    if(i)mds.at(i)+=mds.at(i-1);
    mds.at(i)%=3;
  }
  mint ans=0;
  // full, is leading zero, using digit, mod 3
  vector dp(2,vector(2,vector(1<<10,vector(3,vector<mint>(n+1,0)))));
  dp.at(1).at(1).at(0).at(0).at(0)=1;
  rep(i,n)rep(lzero,2)rep(dst,1<<10)rep(nxd,10)rep(md,3){
    int nlzero=0;
    if(lzero==1&&nxd==0)nlzero=1;
    int ndst=dst;
    if(nlzero!=1)ndst|=(1<<nxd);
    dp.at(0).at(nlzero).at(ndst).at((md+nxd)%3).at(i+1)
      +=dp.at(0).at(lzero).at(dst).at(md).at(i);
    if(s.at(i)-'0'>=nxd
      // &&dst==dsts.at(i)
      // &&md==mds.at(i)
    ){
      if(s.at(i)-'0'==nxd)dp.at(1).at(nlzero).at(ndst).at((md+nxd)%3).at(i+1)
        +=dp.at(1).at(lzero).at(dst).at(md).at(i);
      else dp.at(0).at(nlzero).at(ndst).at((md+nxd)%3).at(i+1)
        +=dp.at(1).at(lzero).at(dst).at(md).at(i);
    }
  }
  rep(i,2)rep(dst,1<<10)rep(md,3){
    bool a=md==0;
    bool b=(dst&(1<<3))!=0;
    bool c=__builtin_popcount(dst)==3;
    if((a&&!b&&!c) || (!a&&b&&!c) || (!a&&!b&&c)) ans+=dp.at(i).at(0).at(dst).at(md).at(n);
  }
  cout<<ans.val()<<endl;

  return 0;
}
