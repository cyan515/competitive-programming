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
  ll n;cin>>n;
  string s;cin>>s;
  ll ans=0;
  map<int,ll>x,y,z;
  map<pair<int,int>,ll>xy,yz,zx;
  map<tuple<int,int,int>,ll>xyz;
  vector<ll>a(n+1,0),b(n+1,0),c(n+1,0);
  rep(i,n){
    if(s.at(i)=='A')a.at(i+1)++;
    else if(s.at(i)=='B')b.at(i+1)++;
    else c.at(i+1)++;
  }
  rep(i,n)a.at(i+1)+=a.at(i),b.at(i+1)+=b.at(i),c.at(i+1)+=c.at(i);
  rep(i,n+1){
    ll cx=a.at(i)-b.at(i);
    ll cy=a.at(i)-c.at(i);
    ll cz=b.at(i)-c.at(i);
    ans+=x[cx]+++y[cy]+++z[cz]++-xy[pair(cx,cy)]++-yz[pair(cy,cz)]++-zx[pair(cz,cx)]+++xyz[tuple(cx,cy,cz)]++;
    // x[cx]++;
    // y[cy]++;
    // z[cz]++;
    // xy[pair(cx,cy)]++;
    // yz[pair(cy,cz)]++;
    // zx[pair(cz,cx)]++;
    // xyz[tuple(cx,cy,cz)]++;
  }
  cout<<n*(n+1)/2-ans<<endl;

  return 0;
}
