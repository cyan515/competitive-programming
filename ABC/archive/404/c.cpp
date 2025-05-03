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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n,m;cin>>n>>m;
  vector g(n,vector<int>());
  dsu uf(n);
  vector<int> deg(n,0);
  rep(i,m) {
    int a,b;cin>>a>>b;a--;b--;
    g.at(a).push_back(b);
    g.at(b).push_back(a);
    uf.merge(a,b);
    deg.at(a)++;
    deg.at(b)++;
  }
  if(uf.groups().size()>1) {
    cout << No << endl;
    return 0;
  }
  bool ok = true;
  rep(i,n) ok &= deg.at(i) == 2;
  cout << (ok?Yes:No) << endl;

  return 0;
}
