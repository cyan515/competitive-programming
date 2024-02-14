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
  int n;cin>>n;
  vector<int> d(n);
  rep(i,n) cin>>d.at(i);
  int ans = 0;
  reps(i,1,n+1) reps(j,1,d.at(i-1)+1) {
    string x = to_string(i) + to_string(j);
    set<char> st;
    rep(k,x.length()) st.insert(x.at(k));
    if(st.size()==1) ans++;
  }
  cout << ans << endl;

  exit(0);
}
