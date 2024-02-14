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
  vector<int> ans(0);
  for(int i=0;i<n;i++) {
    int a;cin>>a;
    if(a%2==0) ans.push_back(a);
  }
  for(int i=0;i<ans.size();i++) {
    cout << ans.at(i);
    if(i==ans.size()-1) cout << endl;
    else cout  << " ";
  }

  exit(0);
}
