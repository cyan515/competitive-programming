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
  vector<int> a(n);
  vector<int> ans;
  for(int i=0;i<n;i++) cin>>a.at(i);
  for(int i=1;i<n;i++) {
    int l = a.at(i-1);
    int r = a.at(i);
    ans.push_back(l);
    if(abs(l-r)>1) {
      if(l<r) {
        for(int j=l+1;j<r;j++) ans.push_back(j);
      } else if(l>r) {
        for(int j=l-1;j>r;j--) ans.push_back(j);
      }
    }
  }
  ans.push_back(a.at(n-1));

  for(int i=0;i<ans.size();i++) {
    cout << ans.at(i);
    if(i==ans.size()-1) cout << endl;
    else cout << " ";
  }

  exit(0);
}
