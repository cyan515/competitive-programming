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
  int n;cin>>n;
  vector<ll>a(n);cin>>a;
  rep(i,n)a.at(i)*=2;
  ll ans=0;
  rep(bit,1LL<<n){
    ll cnt=0;
    ll cur=1;
    rep(i,n){
      ll nx=cur;
      ll sig;
      if((bit&(1<<i))!=0)sig=1;
      else sig=-1;
      nx+=a.at(i)*sig;
      if(cur/abs(cur)!=nx/abs(nx))cnt++;
      cur=nx;
    }
    ans=max(ans,cnt);
  }
  cout<<ans<<endl;

  return 0;
}
