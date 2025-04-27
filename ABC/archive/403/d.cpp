#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
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
  ll n,d;cin>>n>>d;
  vector<ll> a(n);cin>>a;
  if(d==0) {
    map<int,int> mp;
    rep(i,n) mp[a.at(i)]++;
    int ans = 0;
    for(auto [k,v] : mp) {
      ans += v-1;
    }
    cout << ans << endl;
    return 0;
  }
  vector x(d,vector<pair<int,int>>());
  {
    map<int,int> mp;
    rep(i,n) {
      mp[a.at(i)]++;
    }
    for(auto [k,v] : mp) {
      x.at(k%d).push_back(pair(k/d,v));
    }
  }
  int ans = 0;
  rep(i,d) sort(all(x.at(i)));
  for(auto vec : x) {
    int l = 0;
    int r = 1;
    while(l<vec.size()) {
      while(r<vec.size()&&vec.at(r-1).first+1==vec.at(r).first) r++;
      int nn = r-l;
      vector dp(nn+1,vector<int>(2,INF));
      rep(i,2) dp.at(0).at(i) = 0;
      rep(i,nn) {
        chmin(dp.at(i+1).at(0),dp.at(i).at(1));
        chmin(dp.at(i+1).at(1),dp.at(i).at(1)+vec.at(l+i).second);
        chmin(dp.at(i+1).at(1),dp.at(i).at(0)+vec.at(l+i).second);
      }
      ans += min(dp.at(nn).at(0),dp.at(nn).at(1));
      l = r;
      r++;
    }
  }
  cout << ans << endl;

  return 0;
}
