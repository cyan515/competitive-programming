#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 1000000007;

int main() {
  ll n,m;cin>>n>>m;
  ll mi = LINF;
  bool found = false;
  for(ll i=1;i<=n;i++) {
    ll a = (m+i-1L)/i;
    if(a<=n) {
      mi = min(mi,i*a);
      found = true;
    }
    if(i>a) break;
  }
  if(!found) mi = -1L;
  cout << mi << endl;

  exit(0);
}
