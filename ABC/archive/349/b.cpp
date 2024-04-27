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
  string s;cin>>s;
  int n = s.size();
  vector<int> cnt(26,0);
  rep(i,n) cnt.at(s.at(i)-'a')++;
  vector<int> a(n+1,0);
  rep(i,26) a.at(cnt.at(i))++;
  bool ok = true;
  reps(i,1,n+1) ok &= a.at(i)==0 || a.at(i)==2;
  if(ok) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
