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

int main() {
  ll a,b,c, d,e,f, 
     g,h,i, j,k,l;
  cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l;
     
  int x1_min = min(a, d), x1_max = max(a, d);
  int y1_min = min(b, e), y1_max = max(b, e);
  int z1_min = min(c, f), z1_max = max(c, f);

  int x2_min = min(g, j), x2_max = max(g, j);
  int y2_min = min(h, k), y2_max = max(h, k);
  int z2_min = min(i, l), z2_max = max(i, l);

  bool x_overlap = (x1_min < x2_max) && (x1_max > x2_min);
  bool y_overlap = (y1_min < y2_max) && (y1_max > y2_min);
  bool z_overlap = (z1_min < z2_max) && (z1_max > z2_min);
  if(x_overlap&&y_overlap&&z_overlap) cout << Yes << endl;
  else cout << No << endl;

  return 0;
}
