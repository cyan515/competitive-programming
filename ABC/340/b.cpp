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
  vector<int> a(0);
  int Q;cin>>Q;
  while(Q--) {
    int t;cin>>t;
    if(t==1) {
      int x;cin>>x;
      a.push_back(x);
    } else {
      int k;cin>>k;
      cout << a.at(a.size()-k) << endl;
    }
  }

  exit(0);
}
