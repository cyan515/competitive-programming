#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 1000000007;

int main() {
  int h,w;cin>>h>>w;
  int n = min(h,w);
  vector<string> c(h);
  for(int i=0;i<h;i++) cin>>c.at(i);
  vector<int> ans(n+1, 0);
  for(int i=0;i<h;i++) {
    for(int j=0;j<w;j++) {
      if(c.at(i).at(j)!='#') continue;
      for(int k=1;k<=n;k++) {
        if(i+k>=h || i-k<0 || j+k>=w || j-k<0
         || c.at(i+k).at(j+k)!='#'
         || c.at(i+k).at(j-k)!='#'
         || c.at(i-k).at(j+k)!='#'
         || c.at(i-k).at(j-k)!='#') {
          ans.at(k-1)++;
          break;
        }
      }
    }
  }

  for(int i=0;i<n;i++) {
    cout << ans.at(i+1);
    if(i==n-1) cout << endl;
    else cout << " ";
  }

  exit(0);
}
