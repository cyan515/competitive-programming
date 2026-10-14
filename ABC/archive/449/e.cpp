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
  ll n,m;cin>>n>>m;
  vector<ll>a(n);cin>>a;
  ll ma=0;
  {
    map<ll,ll>cnt;
    for(auto e:a)cnt[e]++;
    for(auto [k,v]:cnt){
      chmax(ma,v);
    }
  }
  vector<ll>b;
  {
    map<ll,ll>cnt;
    rep(i,n){
      b.push_back(a.at(i)+cnt[a.at(i)]++*m);
    }
  }
  sort(all(b));
  int Q;cin>>Q;
  while(Q--){
    ll x;cin>>x;
    if(x>ma*m){
      if(x%(ma*m)%m==0)cout<<m<<endl;
      else cout<<x%(ma*m)%m<<endl;
    }else if(x<=n){
      cout<<a.at(x-1)<<endl;
    }else{
      x-=n;
      ll ok=1e13;
      ll ng=0;
      while(abs(ok-ng)>1){
        ll mid=(ok+ng)/2;
        auto it=upper_bound(all(b),mid)-b.begin();
        if(mid-it>=x)ok=mid;
        else ng=mid;
      }
      ll ans=ok%m;
      if(ans==0)ans=m;
      cout<<ans<<endl;
    }
  }

  return 0;
}
