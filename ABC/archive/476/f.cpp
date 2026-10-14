#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
const string Yes = "Yes";
const string No = "No";
#define reps(i, a, n) for (int i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  // int n,m;cin>>n>>m;
  // vector<int>a(n),b(n);cin>>a>>b;
  // vector x(n,vector<ll>(n)),y(n,vector<ll>(n));
  // vector c(n,vector<int>(n));
  // rep(i,n)rep(j,n)x.at(i).at(j)=a.at(i)*b.at(j)%m,c.at(i).at(j)=x.at(i).at(j);
  // rep(i,n)rep(j,n)y.at(j).at(i)=x.at(i).at(j);
  // rep(i,n)reps(j,1,n)x.at(i).at(j)+=x.at(i).at(j-1);
  // rep(j,n)reps(i,1,n)y.at(j).at(i)+=y.at(j).at(i-1);
  // ll ans=0;
  // rep(i,n)rep(j,n){
  //   ll cnt=i*n+j;
  //   reps(k,1,n){
  //     ll tmp=0;
  //     int up=max(-1,i-k);
  //     int dn=min(n,int(i+k));
  //     int le=max(-1,int(j-k));
  //     int ri=min(n,j+k);
  //     if(up!=-1){
  //       tmp+=(ll)x.at(up).at(min(n-1,ri));
  //       if(le>=1)tmp-=x.at(up).at(le-1);
  //     }
  //     if(dn!=n){
  //       tmp+=(ll)x.at(dn).at(min(n-1,ri));
  //       if(le>=1)tmp-=x.at(dn).at(le-1);
  //     }
  //     if(le!=-1){
  //       tmp+=(ll)y.at(le).at(min(n-1,dn));
  //       if(up>=1)tmp-=y.at(le).at(up-1);
  //     }
  //     if(ri!=n){
  //       tmp+=(ll)y.at(ri).at(min(n-1,dn));
  //       if(up>=1)tmp-=y.at(ri).at(up-1);
  //     }
  //     if(0<=le&&le<n){
  //       if(0<=up&&up<n)tmp-=c.at(up).at(le);
  //       if(0<=dn&&dn<n)tmp-=c.at(dn).at(le);
  //     }
  //     if(0<=ri&&ri<n){
  //       if(0<=up&&up<n)tmp-=c.at(up).at(ri);
  //       if(0<=dn&&dn<n)tmp-=c.at(dn).at(ri);
  //     }
  //     cnt+=tmp*k;
  //   }
  //   ans^=cnt;
  // }
  // cout<<ans<<endl;

  return 0;
}
