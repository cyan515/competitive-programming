# pragma GCC target("avx2")
# pragma GCC optimize("O3")
# pragma GCC optimize("unroll-loops")
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
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  ll h,w,k;cin>>h>>w>>k;
  vector<string>s(h);cin>>s;
  vector a(h+1,vector<int>(w+1,0));
  rep(i,h)rep(j,w){
    if(s.at(i).at(j)=='1')a.at(i+1).at(j+1)++;
  }
  rep(i,h+1)rep(j,w){
    a.at(i).at(j+1)+=a.at(i).at(j);
  }
  rep(j,w+1)rep(i,h){
    a.at(i+1).at(j)+=a.at(i).at(j);
  }
  ll ans=0;
  rep(i,h)rep(j,w){
    reps(ii,i+1,h+1){
      int le,ri;
      {
        int ok=j;
        int ng=w+1;
        while(abs(ok-ng)>1){
          int mid=(ok+ng)/2;
          ll x=a.at(ii).at(mid)-a.at(ii).at(j)-a.at(i).at(mid)+a.at(i).at(j);
          if(x<k)ok=mid;
          else ng=mid;
        }
        le=ok;
      }
      {
        int ok=j;
        int ng=w+1;
        while(abs(ok-ng)>1){
          int mid=(ok+ng)/2;
          ll x=a.at(ii).at(mid)-a.at(ii).at(j)-a.at(i).at(mid)+a.at(i).at(j);
          if(x<=k)ok=mid;
          else ng=mid;
        }
        ri=ok;
      }
      ans+=ri-le;
    }
  }
  cout<<ans<<endl;

  return 0;
}
