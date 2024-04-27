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
  string s;cin>>s;
  vector<char> v(26);
  rep(i,26) v.at(i) = 'a'+i;
  int Q;cin>>Q;
  while(Q--) {
    char c,d;cin>>c>>d;
    rep(i,26) {
      if(v.at(i)==c) v.at(i) = d;
    }
  }
  rep(i,n) {
    s.at(i) = v.at(s.at(i)-'a');
  }
  cout << s << endl;

  return 0;
}
