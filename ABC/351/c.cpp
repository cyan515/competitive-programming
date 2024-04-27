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

int main() {
  int n;cin>>n;
  vector<ll> a(n);cin>>a;
  vector<ll> b;
  rep(i,n) {
    b.push_back(a.at(i));
    while(b.size()>=2&&b.back()==b.at(b.size()-2)) {
      b.pop_back();
      b.at(b.size()-1)++;
    }
  }
  cout << b.size() << endl;

  return 0;
}
