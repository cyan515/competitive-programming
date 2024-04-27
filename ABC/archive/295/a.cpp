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
  vector<string> w(n);
  bool flg = false;
  for(int i=0;i<n;i++) {
    string s;cin>>s;
    if(s=="and"
    || s=="not"
    || s=="that"
    || s=="the"
    || s=="you") flg = true;
  };
  if(flg) cout << "Yes" << endl;
  else cout << "No" << endl;


  exit(0);
}
