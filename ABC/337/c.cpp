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
  vector<int> a(n);cin>>a;
  vector<int> b(n,-1);
  int h;
  rep(i,n) {
    if(a.at(i)==-1) h = i;
    else {
      b.at(a.at(i)-1) = i;
    }
  }
  rep(i,n) {
    cout << h+1;
    if(i==n-1) cout << endl;
    else cout << " ";
    h = b.at(h);
  }

  exit(0);
}
