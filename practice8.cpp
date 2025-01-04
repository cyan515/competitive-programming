#include <bits/stdc++.h>
#include <atcoder/scc>
using namespace atcoder;
// using mint = modint998244353;
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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};
// https://atcoder.jp/contests/abc013/tasks/abc013_4
vector<int> doubling(const vector<int>& graph, const long long k) {
  int n = graph.size();
  vector<vector<int>> doubling(60, vector<int>(n));
  
  for (int v = 0; v < n; v++) {
    doubling.at(0).at(v) = graph.at(v);
  }
  
  for (int i = 1; i < 60; ++i) for (int v = 0; v < n; v++) {
    doubling.at(i).at(v) = doubling.at(i-1).at(doubling.at(i-1).at(v));
  }
  
  vector<int> result(n);
  for (int v = 0; v < n; v++) {
    int current = v;
    for (int i = 0; i < 60; i++) {
      if (k & (1LL << i)) {
        current = doubling.at(i).at(current);
      }
    }
    result.at(v) = current;
  }
  
  return result;
}

int main() {
  int n,m,d;cin>>n>>m>>d;
  vector<int> a(m);cin>>a;
  rep(i,m) a.at(i)--;
  vector<int> p(n);
  rep(i,n) p.at(i) = i;
  rep(i,m) {
    swap(p.at(a.at(i)),p.at(a.at(i)+1));
  }
  vector<int> q(n);
  rep(i,n) q.at(p.at(i)) = i;
  auto ans = doubling(q,d);
  rep(i,n) cout << ans.at(i)+1 << endl;
  
  return 0;
}
