#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 998244353;

int f(char c) {
  if(c=='A') {
    return 0;
  } else if(c=='B') {
    return 3;
  } else if(c=='C') {
    return 4;
  } else if(c=='D') {
    return 8;
  } else if(c=='E') {
    return 9;
  } else if(c=='F') {
    return 14;
  } else if(c=='G') {
    return 23;
  }
} 

int main() {
  char p,q;cin>>p>>q;
  cout << abs(f(p)-f(q)) << endl;

  exit(0);
}
