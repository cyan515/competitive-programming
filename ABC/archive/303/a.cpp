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
  string s,t;cin>>s>>t;

  for(int i=0;i<n;i++) {
    if(s.at(i)=='l') s.at(i)='1';
    if(t.at(i)=='l') t.at(i)='1';
    if(s.at(i)=='o') s.at(i)='0';
    if(t.at(i)=='o') t.at(i)='0';
  }

  if(s==t) cout << "Yes";
  else cout << "No";
  cout << endl;

  exit(0);
}
