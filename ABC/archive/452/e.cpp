#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
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
  ll n,m;cin>>n>>m;
  vector<ll>a(n),b(m);cin>>a>>b;
  mint ans=0;
  {
    mint s=0;
    rep(i,m)s+=b.at(i);
    rep(i,n)ans+=mint(a.at(i))*mint(i+1)*s;
  }
  {
    atcoder::fenwick_tree<mint>ft(n);
    rep(i,n)ft.add(i,a.at(i));
    rep(j,m){
      mint x=0;
      int bef=j;
      int cur=0;
      for(ll k=1;k*(j+1)<=n;k++) {
        int le=k*(j+1)-1;
        int ri=min(n,(k+1)*(j+1)-1);
        mint s=ft.sum(le,ri);
        x+=s*k;
      }
      x*=mint(b.at(j))*(j+1);
      ans-=x;
    }
  }
  cout<<ans.val()<<endl;

  return 0;
}
