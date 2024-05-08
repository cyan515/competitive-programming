#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
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

int main() {
  int n;cin>>n;
  int Q;cin>>Q;
  vector<int> c(n);cin>>c;
  vector<set<int>> x(n);
  rep(i,n) x.at(i).insert(c.at(i));
  while(Q--) {
    int a,b;cin>>a>>b;a--;b--;
    if(x.at(a).size()>x.at(b).size()) {
      x.at(a).merge(x.at(b));
      swap(x.at(a),x.at(b));
      x.at(a).clear();
    } else {
      x.at(b).merge(x.at(a));
      x.at(a).clear();
    }
    cout << x.at(b).size() << endl;
  }

  return 0;
}
