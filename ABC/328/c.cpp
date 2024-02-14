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
  int n;cin>>n;int q;cin>>q;
  string s;cin>>s;
  vector<int> sum(n,0);
  rep(i,n-1) {
    if(s.at(i)==s.at(i+1)) sum.at(i+1)++;
  }
  rep(i,n-1) {
    sum.at(i+1) += sum.at(i);
  }
  while(q--) {
    int l,r;cin>>l>>r;l--;r--;
    cout << sum.at(r)-sum.at(l) << endl;
  }

  exit(0);
}
