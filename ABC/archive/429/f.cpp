#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
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

using S = vector<vector<int>>;
S op(S a, S b) {
  
}
S e() {
  return {
    {0,0,0},
    {0,0,0},
    {0,0,0}
  };
}

int main() {
  int h = 3;
  int w;cin>>w;
  vector<string> s(h);cin>>s;
  segtree<S,op,e> seg(w);
  rep(j,w) {
    string t = "";
    rep(i,h) {
      t.push_back(s.at(i).at(j));
    }
    if(t=="...") {
      seg.set(j,
        {
          {0,1,2},
          {1,0,1},
          {2,1,0},
        }
      );
    } else if(t=="#..") {
      seg.set(j,
        {
          {INF,INF,INF},
          {INF,0,1},
          {INF,1,0},
        }
      );
    } else if(t==".#.") {
      seg.set(j,
        {
          {0,INF,INF},
          {INF,INF,INF},
          {INF,INF,0},
        }
      );
    } else if(t=="..#") {
      seg.set(j,
        {
          {0,1,INF},
          {1,0,INF},
          {INF,INF,INF},
        }
      );
    } else if(t=="##.") {
      seg.set(j,
        {
          {INF,INF,INF},
          {INF,INF,INF},
          {INF,INF,0},
        }
      );
    } else if(t=="#.#") {
      seg.set(j,
        {
          {INF,INF,INF},
          {INF,0,INF},
          {INF,INF,INF},
        }
      );
    } else if(t==".##") {
      seg.set(j,
        {
          {0,INF,INF},
          {INF,INF,INF},
          {INF,INF,INF},
        }
      );
    } else if(t=="###") {
      seg.set(j,
        {
          {INF,INF,INF},
          {INF,INF,INF},
          {INF,INF,INF},
        }
      );
    }
  }
  

  return 0;
}
