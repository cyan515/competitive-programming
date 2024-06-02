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
  int n,m,k;cin>>n>>m>>k;
  vector<int> c(m);
  vector a(m,vector<int>());
  vector<char> r(m);
  rep(i,m) {
    cin >> c.at(i);
    a.at(i).resize(c.at(i));cin>>a.at(i);
    rep(j,a.at(i).size()) a.at(i).at(j)--;
    cin>>r.at(i);
  }
  int ans = 0;
  rep(bit,1<<n) {
    bool ok = true;
    rep(i,m) {
      int cnt = 0;
      rep(j,c.at(i)) if(bit&(1<<a.at(i).at(j))) cnt++;
      if(r.at(i)=='o') ok &= cnt>=k;
      else ok &= cnt<k;
    }
    if(ok) ans++;
  }
  cout << ans << endl;

  return 0;
}
