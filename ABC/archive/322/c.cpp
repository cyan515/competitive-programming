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
  cin.tie(0) -> sync_with_stdio(0);
  int n;cin>>n;
  int m;cin>>m;
  vector<int> f(n,n);
  rep(i,m) {
    int a;cin>>a;a--;
    f.at(a)=a;
  }
  for(int i=n-2;i>=0;i--) {
    f.at(i) = min(f.at(i),f.at(i+1));
  }
  rep(i,n) {
    cout << f.at(i)-i << endl;
  }

  exit(0);
}
