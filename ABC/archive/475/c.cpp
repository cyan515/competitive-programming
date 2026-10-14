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
  ll n,s,l;cin>>n>>s>>l;
  vector<ll>a(n-1);cin>>a;
  vector<ll>pref(n,0);
  rep(i,n-1)pref.at(i+1)+=pref.at(i)+a.at(i);
  s--;
  ll ans=0;
  rep(le,s+1)reps(ri,s,n){
    ll c=LINF;
    ll lc=pref.at(s)-pref.at(le);
    ll rc=pref.at(ri)-pref.at(s);
    c=min(c,lc*2+rc);
    c=min(c,lc+rc*2);
    if(c>l)continue;
    ans=max(ans,ri-le+1);
  }
  cout<<ans<<endl;

  return 0;
}
