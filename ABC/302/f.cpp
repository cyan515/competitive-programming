#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 1000000007;

int main() {
  int n,m;cin>>n>>m;
  dsu D(n);
  vector<set<int>> st(m,set<int>());
  for(int i=0;i<n;i++) {
    int a;cin>>a;
    for(int j=0;j<a;j++) {
      int s;cin>>s;s--;
      st.at(s).insert(i);
    }
  }

  exit(0);
}
