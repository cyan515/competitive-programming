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
  for(int i=0;;i++) {
    if((n+i)%5==0) {
      cout << n+i << endl;
      exit(0);
    } else if((n-i)%5==0) {
      cout << n-i << endl;
      exit(0);
    }
  }

  exit(0);
}
