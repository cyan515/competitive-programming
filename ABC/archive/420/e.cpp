#include <bits/stdc++.h>
#include <atcoder/dsu>
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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n,Q;cin>>n>>Q;
  atcoder::dsu uf(n);
  vector<int> cnt(n,0);
  vector<int> col(n,0);
  while(Q--) {
    int op;cin>>op;
    int u,v;
    if(op==1) {
      cin>>u>>v;u--;v--;
      int ul = uf.leader(u);
      int vl = uf.leader(v);
      if(uf.same(ul,vl)) continue;
      uf.merge(u,v);
      int nl = uf.leader(u);
      cnt.at(nl) = cnt.at(ul)+cnt.at(vl);
    } else if(op==2) {
      cin>>u;u--;
      int leader = uf.leader(u);
      if(col.at(u)==1) {
        col.at(u) = 0;
        cnt.at(leader)--;
      } else {
        col.at(u) = 1;
        cnt.at(leader)++;
      }
    } else {
      cin>>u;u--;
      int leader = uf.leader(u);
      cout << (cnt.at(leader)>0?Yes:No) << endl;
    }
  }

  return 0;
}
