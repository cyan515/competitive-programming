#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 1000000007;

int main() {
  int n;cin>>n;
  int t;cin>>t;
  int ma = -INF;
  int ans = -1;
  vector<int> c(n);
  vector<int> r(n);
  for(int i=0;i<n;i++) cin>>c.at(i);
  for(int i=0;i<n;i++) cin>>r.at(i);
  for(int i=0;i<n;i++) {
    if(c.at(i)==t) {
      ma = max(ma,r.at(i));
      if(ma==r.at(i)) ans = i+1;
    }
  }
  if(ma == -INF) t = c.at(0);
  for(int i=0;i<n;i++) {
    if(c.at(i)==t) { 
      ma = max(ma,r.at(i));
      if(ma==r.at(i)) ans = i+1;
    }
  }
  cout << ans << endl;

  exit(0);
}
