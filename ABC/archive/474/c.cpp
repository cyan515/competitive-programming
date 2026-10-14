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
  ll n,Q;cin>>n>>Q;
  vector<ll>p(n);cin>>p;
  map<ll,ll>mp;
  rep(i,n){
    mp[p.at(i)]=i;
  }
  ll cnt=n;
  while(Q--){
    ll a;cin>>a;
    mp[a]=cnt;
    cnt++;
  }
  vector<ll>ans(n);
  rep(i,n)ans.at(i)=i+1;
  sort(all(ans),[&](int i,int j)->bool{
    return mp[i]<mp[j];
  });
  rep(i,n){
    if(i)cout<<" ";
    cout<<ans.at(i);
  }
  cout<<endl;

  return 0;
}
