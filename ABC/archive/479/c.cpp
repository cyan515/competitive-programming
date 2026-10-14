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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n,w;cin>>n>>w;
  vector<ll>a(n),b(n);
  rep(i,n)cin>>a.at(i)>>b.at(i);
  ll ans=0;
  rep(bit,1<<n){
    ll cnt=0;
    ll x=0;
    rep(i,n){
      if((bit&(1<<i))!=0)cnt+=b.at(i),x+=a.at(i);
    }
    if(cnt>w)continue;
    ans=max(ans,x);
  }
  cout<<ans<<endl;

  return 0;
}
