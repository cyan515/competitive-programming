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
  ll n,m;cin>>n>>m;
  vector<ll>a(m),b(m);
  rep(i,m)cin>>a.at(i)>>b.at(i);
  set<pair<int,int>>ab;
  rep(i,m)ab.insert(pair(a.at(i),b.at(i)));
  vector g(n,vector<int>());
  for(auto [s,t]:ab){
    g.at(s-1).push_back(t-1);
    g.at(t-1).push_back(s-1);
  }
  m=ab.size();
  vector<int>d(n,0);
  rep(i,n)d.at(i)=g.at(i).size();
  vector<int>d2=d;
  sort(all(d2));
  ll ans=0;
  rep(i,n){
    int x=m-d.at(i);
    ans+=upper_bound(all(d2),x)-lower_bound(all(d2),x);
    if(d.at(i)==x)ans--;
    for(auto j:g.at(i)){
      if(d.at(j)==x)ans--;
      if(d.at(j)==x+1)ans++;
    }
  }
  ans/=2;
  cout<<ans<<endl;

  return 0;
}
