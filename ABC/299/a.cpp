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
  string s;cin>>s;
  bool flg = false;
  bool ans = false;
  for(int i=0;i<n;i++) {
    if(s.at(i)=='|') flg = !flg;
    if(flg&&s.at(i)=='*') ans=true; 
  }
  if(ans) cout << "in";
  else cout << "out";
  cout << endl;

  exit(0);
}
