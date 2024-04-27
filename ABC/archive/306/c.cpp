#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 998244353;

int main() {
  int n;cin>>n;
  vector<int> a(n*3);
  for(int i=0;i<n*3;i++) cin>>a.at(i);
  vector<pair<int,int>> ans(n,make_pair(-1,-1));
  for(int i=0;i<n*3;i++) {
    if(ans.at(a.at(i)-1).first==-1) ans.at(a.at(i)-1) = make_pair(-2, a.at(i));
    else if(ans.at(a.at(i)-1).first==-2) ans.at(a.at(i)-1) = make_pair(i+1, a.at(i));
  }
  sort(ans.begin(),ans.end());
  for(int i=0;i<n;i++) cout << ans.at(i).second << " ";
  cout << endl;

  exit(0);
}
