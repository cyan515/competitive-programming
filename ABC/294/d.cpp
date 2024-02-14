#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 1000000007;

int main() {
  int n,q;cin>>n>>q;
  vector<int> ans(0);
  int calling = 1;
  set<int> called;
  while(q--) {
    int c;cin>>c;
    if(c==1) {
      called.insert(calling);
      calling++;
    } else if(c==2) {
      int x;cin>>x;
      called.erase(x);
    } else {
      cout << *called.begin() << endl;
    }
  }

  exit(0);
}
