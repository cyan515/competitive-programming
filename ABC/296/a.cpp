#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 1000000007;

int main() {
  int n;cin >> n;
  string s;cin>>s;
  bool f = true;
  for(int i=1;i<n;i++) {
    if(s.at(i)==s.at(i-1)) f = false;
  }
  if(f) cout << "Yes";
  else cout << "No";
  cout << endl;

  exit(0);
}
