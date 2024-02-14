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
  vector<int> op(2*n);
  rep(i,n) {
    int a,b;cin>>a>>b;a--;b--;
    op.at(a) = b;
    op.at(b) = a;
  }
  stack<int> stk;
  set<int> st;
  bool flg = true;
  rep(i,2*n) {
    if(st.count(i)) {
      auto v = stk.top();
      stk.pop();
      flg &= v==i;
    } else {
      st.insert(op.at(i));
      stk.push(op.at(i));
    }
  }
  if(flg) cout << "No" << endl;
  else cout << "Yes" << endl;

  exit(0);
}
