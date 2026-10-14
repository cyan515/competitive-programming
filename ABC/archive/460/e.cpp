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
    map<int,ll>ycnt;
    {
      ll x=9;
      rep(i,19){
        if(x>n){
          ycnt[i+1]=(n-x/10)%MOD;
          break;
        }
        ycnt[i+1]=x%MOD;
        x*=10;
      }
    }
    map<int,ll>z;
    {
      ll x=10;
      rep(i,19){
        z[i+1]=(x-1)%m;
        x*=10;
      }
    }
    mint ans=0;
    // reps(x,1,n+1)reps(y,1,n+1){
    //   ll a=stoll(to_string(x)+to_string(y));
    //   ll b=x+y;
    //   a%=m;
    //   b%=m;
    //   if(a==b){
    //     cout<<x<<" "<<y<<endl;
    //   }
    // }
    ll len=to_string(n).size();
    reps(i,1,len+1){
      ll g=gcd(z[i],m);
      ll mm=m/g;
      ans+=mint(n/mm)*mint(ycnt[i]);
    }
    cout<<ans.val()<<endl;
  }

  return 0;
}
