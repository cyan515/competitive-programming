#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint =  modint1000000007;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int n,m;cin>>n>>m;
  double e;cin>>e;
  vector<int> d(m);
  rep(i,m) {
    int a;cin>>a;
    d.at(i) = a;
    rep(j,a) {
      int b,c;cin>>b>>c;
    }
  }
  set<pair<int,int>> ans;
  int cnt = 0;
  rep(i,n) {
    cout << "q 1 " << 0 << " " << i << endl;
    int res;cin>>res;
    cnt += res;
    if(res) {
      ans.emplace(0,i);
    }
  }
  
  
  return 0;
}
