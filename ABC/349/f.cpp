#include <bits/stdc++.h>
using namespace std;
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
  int n = 3;
  vector a(n,vector<ll>(n));
  rep(i,n) rep(j,n) cin>>a.at(i).at(j);
  vector b(n,vector<int>(n,0));
  auto is_win = [&]() -> int {
    bool ok = false;
    rep(i,n) {
      bool tmp = true;
      rep(j,n) tmp &= b.at(i).at(j) == 1;
      ok |= tmp;
    }
    rep(j,n) {
      bool tmp = true;
      rep(i,n) tmp &= b.at(i).at(j) == 1;
      ok |= tmp;
    }
    ok |= b.at(0).at(0)==1&&b.at(1).at(1)==1&&b.at(2).at(2)==1;
    ok |= b.at(2).at(0)==1&&b.at(1).at(1)==1&&b.at(0).at(2)==1;
    if(ok) return 1;
    
    bool ng = false;
    rep(i,n) {
      bool tmp = true;
      rep(j,n) tmp &= b.at(i).at(j) == -1;
      ng |= tmp;
    }
    rep(j,n) {
      bool tmp = true;
      rep(i,n) tmp &= b.at(i).at(j) == -1;
      ng |= tmp;
    }
    ng |= b.at(0).at(0)==-1&&b.at(1).at(1)==-1&&b.at(2).at(2)==-1;
    ng |= b.at(2).at(0)==-1&&b.at(1).at(1)==-1&&b.at(0).at(2)==-1;
    if(ng) return -1;
    
    bool done = true;
    rep(i,n) rep(j,n) done &= b.at(i).at(j)!=0;
    if(done) {
      ll x = 0;
      ll y = 0;
      rep(i,n) rep(j,n) {
        if(b.at(i).at(j)==1) x+=a.at(i).at(j);
        else y+=a.at(i).at(j);
      }
      if(x-y>0) return 1;
      else return -1;
    }
    return 0;
  };
  map<pair<int,vector<vector<int>>>,int> memo;
  auto f = [&](int t,auto f) -> int {
    auto it = memo.find(pair(t,b));
    if(it!=memo.end()) return (*it).second;
    int state = is_win();
    if(state!=0) {
      return state;
    }
    int ret;
    if(t==1) {
      ret = -1;
      rep(i,n) rep(j,n) {
        if(b.at(i).at(j)!=0) continue;
        b.at(i).at(j) = t;
        chmax(ret,f(-t,f));
        b.at(i).at(j) = 0;
      }
    } else {
      ret = 1;
      rep(i,n) rep(j,n) {
        if(b.at(i).at(j)!=0) continue;
        b.at(i).at(j) = t;
        chmin(ret,f(-t,f));
        b.at(i).at(j) = 0;
      }
    }
    return memo[pair(t,b)] = ret;
  };
  int ans = f(1,f);
  if(ans>0) cout << "Takahashi" << endl;
  else if(ans<0) cout << "Aoki" << endl;
  
  return 0;
}
