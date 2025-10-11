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
  int T;cin>>T;
  while(T--) {
    ll n,m,k;cin>>n>>m>>k;
    string s;cin>>s;
    vector<int> us(m),vs(m);
    rep(i,m) cin>>us.at(i)>>vs.at(i);
    rep(i,m) us.at(i)--,vs.at(i)--;
    vector g(n,vector<int>());
    rep(i,m) {
      g.at(us.at(i)).push_back(vs.at(i));
    }
    vector memo(n,vector(2,vector<int>(2*k+1,0)));
    auto f = [&](auto self,int v,int t,int rest) -> int {
      if(memo.at(v).at(t).at(rest)!=0) {
        return memo.at(v).at(t).at(rest);
      }
      if(rest==0) {
        if(s.at(v)=='A') return 1;
        else return -1;
      }
      int ret = 0;
      vector<int> vec;
      for(auto nv : g.at(v)) {
        vec.push_back(self(self,nv,t^1,rest-1));
      }
      if(t==0) {
        bool ok = false;
        for(auto ele : vec) {
          ok |= ele == 1;
        }
        if(ok) ret = 1;
        else ret = -1;
      } else {
        bool ok = false;
        for(auto ele : vec) {
          ok |= ele == -1;
        }
        if(ok) ret = -1;
        else ret = 1;
      }
      return memo.at(v).at(t).at(rest) = ret;
    };
    int ans = f(f,0,0,2*k);
    if(ans==1) cout << "Alice" << endl;
    else cout << "Bob" << endl;
  }

  return 0;
}
