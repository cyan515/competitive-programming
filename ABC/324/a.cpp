#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  bool ans = true;
  int n;cin>>n;
  vector<int> a(n);
  rep(i,n) cin>>a.at(i);
  rep(i,n-1) ans &= a.at(i)==a.at(i+1);
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  exit(0);
}
