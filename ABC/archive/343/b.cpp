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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int n;cin>>n;
  vector a(n,vector(n,0));
  rep(i,n) cin>>a.at(i);
  vector g(n,set<int>());
  rep(i,n) rep(j,n)  {
    if(a.at(i).at(j)!=1) continue;
    g.at(i).insert(j);
    g.at(j).insert(i);
  }
  rep(i,n) {
    for(auto ele : g.at(i)) cout << ele+1 << " ";
    cout << endl;
  }

  return 0;
}
