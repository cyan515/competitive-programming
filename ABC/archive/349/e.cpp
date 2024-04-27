#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int n = 3;
  vector a(n,vector<ll>(n));
  rep(i,n) rep(j,n) cin>>a.at(i).at(j);
  vector b(n,vector<int>(n,0));
  auto is_win = [&](int turn) -> int {
    bool done = true;
    rep(i,n) rep(j,n) done &= b.at(i).at(j)!=0;
    if(done) {
      ll x = 0;
      ll y = 0;
      rep(i,n) rep(j,n) {
        if(b.at(i).at(j)==turn) x+=a.at(i).at(j);
        else y+=a.at(i).at(j);
      }
      if(x-y>0) return 1;
      else return -1;
    } else {
      bool ok = false;
      rep(i,n) {
        bool tmp = true;
        rep(j,n) tmp &= b.at(i).at(j) == turn;
        ok |= tmp;
      }
      rep(j,n) {
        bool tmp = true;
        rep(i,n) tmp &= b.at(i).at(j) == turn;
        ok |= tmp;
      }
      ok |= b.at(0).at(0)==turn&&b.at(1).at(1)==turn&&b.at(2).at(2)==turn;
      ok |= b.at(2).at(0)==turn&&b.at(1).at(1)==turn&&b.at(0).at(2)==turn;
      if(ok) return 1;
      else return 0;
    }
  };
  map<pair<int,vector<vector<int>>>,bool> memo;
  auto dfs = [&](auto dfs,int turn) -> bool {
    auto it = memo.find(pair(turn,b));
    int state = is_win(-turn);
    if(state==1) {
      return true;
    } else if(state==-1) {
      return false;
    }
    if(it!=memo.end()) {
      return (*it).second;
    }
    bool win = false;
    rep(i,n) rep(j,n) {
      if(b.at(i).at(j)!=0) continue;
      b.at(i).at(j) = turn;
      win |= dfs(dfs,-turn);
      b.at(i).at(j) = 0;
    }
    return memo[pair(turn,b)] = win;
  };
  bool ok = dfs(dfs,1);
  if(ok) cout << "Takahashi" << endl;
  else cout << "Aoki" << endl;

  return 0;
}
