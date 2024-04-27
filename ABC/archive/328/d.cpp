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

int main() {
  string s;cin>>s;
  int n = s.length();
  vector<char> st(0);
  rep(i,n) {
    st.push_back(s.at(i));
    if(st.size()>=3) {
      int x = st.size();
      if(st.at(x-1)=='C'&&st.at(x-2)=='B'&&st.at(x-3)=='A') {
        rep(_,3) st.pop_back();
      }
    }
  }
  rep(i,st.size()) {
    cout << st.at(i);
  }
  cout << endl;

  exit(0);
}
