#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 1000000007;

int main() {
  ll n,m,d;cin>>n>>m>>d;
  vector<ll> a(n);
  vector<ll> b(m);
  for(int i=0;i<n;i++) cin>>a.at(i);
  for(int i=0;i<m;i++) cin>>b.at(i);

  sort(a.begin(),a.end());
  sort(b.begin(),b.end());


  ll ma = -LINF;
  for(int i=0;i<n;i++) {
    ll av = a.at(i);
    ll limit = av+d;

    ll ok = -1;
    ll ng = m;
    while(ng-ok>1) {
      int mid = (ok+ng)/2;
      if(b.at(mid)<=limit) ok=mid;
      else ng=mid;
    }
    ok = min(ok,m-1);
    if(ok==-1) continue;
    if(abs(b.at(ok)-av)>d) continue;
    ma = max(ma, b.at(ok) + av);
  }

  if(ma == -LINF) ma = -1;
  cout << ma << endl;

  exit(0);
}
