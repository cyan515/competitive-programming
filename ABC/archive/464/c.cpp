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
  ll n,m;cin>>n>>m;
  vector<ll>a(n),d(n),b(n);
  rep(i,n)cin>>a.at(i)>>d.at(i)>>b.at(i);
  map<int,ll>mp;
  vector ev(m,vector<int>());
  int ans=0;
  rep(i,n){
    mp[a.at(i)]++;
    ev.at(d.at(i)-1).push_back(i);
  }
  ans=mp.size();
  rep(j,m){
    for(auto ele:ev.at(j)){
      if(a.at(ele)==b.at(ele))continue;
      mp[a.at(ele)]--;
      mp[b.at(ele)]++;
      if(mp[a.at(ele)]==0){
        ans--;
        mp.erase(mp.find(a.at(ele)));
      }
      if(mp[b.at(ele)]==1){
        ans++;
      }
    }
    cout<<ans<<endl;
  }

  return 0;
}
