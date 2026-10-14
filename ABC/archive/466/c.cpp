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
  ll n;cin>>n;
  ll ans=0;
  int r=0;
  rep(l,n){
    if(l==r)r++;
    while(r<n){
      if(l==r){
        r++;continue;
      }
      cout<<"? "<<l+1<<" "<<r+1<<endl;
      string ret;cin>>ret;
      if(ret==No)break;
      r++;
    }
    ll x=r-l;
    ans+=x-1;
  }
  cout<<"! "<<ans<<endl;

  return 0;
}
