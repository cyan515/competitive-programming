#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

void solve() {
  int k,q;cin>>k>>q;
  vector<int> a(k);cin>>a;
  vector<int> n(q);cin>>n;
  rep(i,q) {
    int nn = n.at(i);
    if(nn<a.at(0)) {
      cout << nn;
    } else {
      cout << a.at(0)-1;
    }
    if(i==q-1) cout << endl;
    else cout << " ";
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t;cin>>t;
  while(t--) solve();

  return 0;
}
