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
  ll n,v;cin>>n>>v;
  vector<ll>w(n);cin>>w;
  ll ans=0;
  rep(i,n)reps(j,i+1,n)reps(k,j+1,n){
    ll cost=i+1+j+1+k+1;
    if(cost>v)continue;
    ll cnt=w.at(i)+w.at(j)+w.at(k);
    ans=max(ans,cnt);
  }
  cout<<ans<<endl;

  return 0;
}
