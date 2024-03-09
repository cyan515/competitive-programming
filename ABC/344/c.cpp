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
  int m;cin>>m;
  vector<int> b(m);cin>>b;
  int l;cin>>l;
  vector<int> c(l);cin>>c;
  set<int> st;
  rep(i,n) rep(j,m) rep(k,l) {
    st.insert(a.at(i)+b.at(j)+c.at(k));
  }
  int Q;cin>>Q;
  while(Q--) {
    int x;cin>>x;
    if(st.count(x)) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

  return 0;
}
