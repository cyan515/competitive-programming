#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
void YN(bool b){cout<<(b?"Yes":"No")<<endl;}

int main() {
  int n;cin>>n;
  vector<string> s(n);
  vector<ll> c(n);
  rep(i,n) cin>>s.at(i)>> c.at(i);
  ll sum = 0;
  rep(i,n) sum+=c.at(i);
  sort(all(s));
  cout << s.at(sum%n) << endl;

  return 0;
}
