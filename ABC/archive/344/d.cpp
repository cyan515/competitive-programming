#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  string t;cin>>t;
  int n;cin>>n;
  vector s(n,vector<string>());
  rep(i,n) {
    int a;cin>>a;
    rep(_,a) {
      string u;cin>>u;
      s.at(i).push_back(u);
    }
  }
  int m = t.size()+1;
  vector<int> dp(m,INF);
  dp.at(0) = 0;
  rep(i,n) {
    vector<int> ndp = dp;
    for(string ele : s.at(i)) {
      rep(j,m) {
        if(j+ele.size()>=m) break;
        if(dp.at(j)!=INF) {
          if(t.substr(j,ele.size())==ele) {
            chmin(ndp.at(j+ele.size()),dp.at(j)+1);
          }
        }
      }
    }
    swap(ndp,dp);
  }
  int ans = dp.at(m-1);
  if(ans==INF) ans = -1;
  cout << ans << endl;

  return 0;
}
