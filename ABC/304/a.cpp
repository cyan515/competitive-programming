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
  vector<string> s(n);
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>s.at(i)>>a.at(i);
  int idx;
  int mi = INF;
  for(int i=0;i<n;i++) {
    if(mi>a.at(i)) mi=a.at(i), idx=i;
  }
  for(int i=0;i<n;i++) {
    cout << s.at((i+idx)%n) << endl;
  }

  exit(0);
}
