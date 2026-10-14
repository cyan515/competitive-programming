#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using mint=atcoder::modint998244353;
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
  int T;cin>>T;
  while(T--){
    ll n,m;cin>>n>>m;
    ll len=to_string(n).size();
    map<int,ll>ycnt;
    {
      ll x=1;
      reps(i,1,len+1){
        ll le=x;
        ll ri=min(n,x*10-1);
        ycnt[i]=(ri-le+1)%MOD;
        x*=10;
      }
      if(len==19)ycnt[19]=1;
    }
    map<int,ll>z;
    {
      ll x=10%m;
      rep(i,len){
        z[i+1]=(x-1+m)%m;
        x*=10;
        x%=m;
      }
    }
    mint ans=0;
    reps(i,1,len+1){
      ll g=gcd(z[i],m);
      ll mm=m/g;
      ans+=mint(n/mm)*mint(ycnt[i]);
    }
    cout<<ans.val()<<endl;
    
    // {
    //   ll ans=0;
    //   reps(x,1,n+1)reps(y,1,n+1){
    //     ll a=stoll(to_string(x)+to_string(y));
    //     ll b=x+y;
    //     a%=m;
    //     b%=m;
    //     if(a==b){
    //       // cout<<x<<" "<<y<<endl;
    //       ans++;
    //     }
    //   }
    //   cout<<ans<<endl;
    // }
  }

  return 0;
}
