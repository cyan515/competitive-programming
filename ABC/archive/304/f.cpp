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
  string s;cin>>s;
  set<int> fset;
  for(int i=1;i*i<=n;i++) {
    if(n%i==0) {
      fset.insert(i);
      fset.insert(n/i);
    }
  }
  vector<int> f;
  for(int ele : fset) f.push_back(ele);
  sort(f.begin(),f.end());
  for(int m : f) {
    
  }

  exit(0);
}
