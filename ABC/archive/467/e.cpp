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
  vector<ll>a(n),b(n-1);cin>>a>>b;
  vector<ll>need(n,0);
  ll cur=0;
  reps(i,1,n){
    ll c=(a.at(i-1)+need.at(i-1)+a.at(i))%m;
    need.at(i)=(b.at(i-1)-c+m)%m;
    cur+=need.at(i);
  }
  map<ll,ll>es;
  rep(i,n){
    if(i%2){
      es[need.at(i)+1]+=m;
    }else{
      es[m-need.at(i)]-=m;
    }
  }
  {
    auto [k,v]=*es.begin();
    es[m+k]=v;
  }
  ll ans=cur;
  ll t=0;
  for(auto [k,v]:es){
    cur+=(k-1-t)*(n%2);
    t=k-1;
    chmin(ans,cur);
    cur+=(k-t)*(n%2);
    cur+=v;
    t=k;
    chmin(ans,cur);
  }
  cout<<ans<<endl;

  return 0;
}
