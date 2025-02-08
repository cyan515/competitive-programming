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
  int n;cin>>n;
  vector<ll> k(n);
  vector a(n,vector<ll>());
  rep(i,n) {
    cin>>k.at(i);
    a.at(i).resize(k.at(i));
    cin>>a.at(i);
  }
  rep(i,n) sort(all(a.at(i)));
  vector cnt(n,map<ll,ll>());
  rep(i,n) {
    for(auto ele : a.at(i)) {
      cnt.at(i)[ele]++;
    }
  }
  long double ans = 0;
  rep(i,n) {
    reps(j,i+1,n) {
      long double calc = 0;
      for(auto ele : a.at(i)) {
        auto it = cnt.at(j).find(ele);
        if(it==cnt.at(j).end()) continue;
        long double x = (long double)1/(long double)k.at(i);
        long double y = (long double)(*it).second/(long double)k.at(j);
        calc += x*y;
      }
      chmax(ans,calc);
    }
  }
  cout << fixed << setprecision(20) << ans << endl;

  return 0;
}
