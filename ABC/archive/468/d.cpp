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
  string s;cin>>s;
  ll n=s.size();
  ll ans=0;
  rep(i,n){
    ll cnt=0;
    rep(j,n){
      if(i+j>=n||i-j<0)break;
      cnt+=!!(s.at(i+j)!=s.at(i-j));
      if(cnt>=2)break;
      ans++;
    }
    cnt=0;
    rep(j,n){
      if(i+j>=n||i-1-j<0)break;
      cnt+=!!(s.at(i+j)!=s.at(i-1-j));
      if(cnt>=2)break;
      ans++;
    }
  }
  cout<<ans<<endl;

  return 0;
}
