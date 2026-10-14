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
  cin.tie(nullptr);
  ll n,m,k;cin>>n>>m>>k;
  ll x,y;cin>>x>>y;
  vector<ll>a(n),b(m);cin>>a>>b;
  sort(all(a));
  sort(all(b));
  ll bs=0;
  ll s=0;
  ll ans=0;
  vector<ll>pref(n+1,0);
  rep(i,n)pref.at(i+1)+=pref.at(i)+a.at(i);
  {
    auto it=upper_bound(all(pref),x+y*k);
    ans=it-pref.begin()-1;
  }
  rep(j,m){
    bs+=(b.at(j)+k-1)/k;
    s+=b.at(j);
    if(bs>y)break;
    ll rem=x+y*k-s;
    ll it=upper_bound(all(pref),rem)-pref.begin()-1;
    chmax(ans,j+1+it);
  }
  cout<<ans<<endl;

  return 0;
}
