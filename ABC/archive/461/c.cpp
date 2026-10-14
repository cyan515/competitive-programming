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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  ll n,k,m;cin>>n>>k>>m;
  vector<ll>c(n),v(n);
  rep(i,n)cin>>c.at(i)>>v.at(i);
  vector x(n+1,vector<ll>());
  rep(i,n)x.at(c.at(i)).push_back(v.at(i));
  rep(i,n)sort(rall(x.at(i)));
  sort(rall(x));
  ll ans=0;
  rep(i,m){
    ans+=x.at(i).front();
  }
  vector<ll>vec;
  rep(i,n+1){
    rep(j,x.at(i).size()){
      if(i<m&&j==0)continue;
      vec.push_back(x.at(i).at(j));
    }
  }
  sort(rall(vec));
  rep(i,k-m){
    ans+=vec.at(i);
  }
  cout<<ans<<endl;

  return 0;
}
