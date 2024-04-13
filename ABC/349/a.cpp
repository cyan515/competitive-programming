#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  int n;cin>>n;
  vector<int> a(n);
  rep(i,n) cin>>a.at(i);
  int sum = 0;
  rep(i,n) sum+=a.at(i);
  cout << -sum << endl;

  return 0;
}
