#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;
using mint=modint998244353;
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
  ll n,x;cin>>n>>x;
  vector<ll>a(n);cin>>a;
  mint al=0;
  mint ans=0;
  if(n<=20){
    rep(bit,1<<n){
      ll s=0;
      rep(i,n){
        if((bit&(1<<i))!=0)s+=a.at(i);
      }
      if(s<x)continue;
      mint cnt=0;
      rep(i,n){
        if((bit&(1<<i))!=0)if(s-a.at(i)<x)cnt++;
      }
      ll d=__builtin_popcount(bit);
      d--;
      while(d>0){
        cnt*=d;
        d--;
      }
      al+=cnt;
      ans+=cnt*s;
    }
  }
  
  ans/=al;
  cout<<ans.val()<<endl;

  return 0;
}
