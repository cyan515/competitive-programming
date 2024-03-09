#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
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
  int n,m,k,s,t,x;cin>>n>>m>>k>>s>>t>>x;s--;t--;x--;
  vector g(n,vector<int>());
  rep(_,m) {
    int u,v;cin>>u>>v;u--;v--;
    g.at(u).push_back(v);
    g.at(v).push_back(u);
  }
  vector<mint> odd(n,0);
  vector<mint> evn(n,0);
  evn.at(s) = 1;
  rep(_,k) {
    vector<mint> nodd(n,0);
    vector<mint> nevn(n,0);
    rep(i,n) {
      for(auto ele : g.at(i)) {
        if(ele==x) {
          nodd.at(ele) += evn.at(i);
          nevn.at(ele) += odd.at(i);
        } else {
          nodd.at(ele) += odd.at(i);
          nevn.at(ele) += evn.at(i);
        }
      }
    }
    swap(odd,nodd);
    swap(evn,nevn);
  }
  cout << evn.at(t).val() << endl;
  
  return 0;
}
