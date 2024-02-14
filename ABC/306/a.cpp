#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using rev_priority_queue = priority_queue<int, vector<int>, greater<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 998244353;

int main() {
  int n;cin>>n;
  string s;cin>>s;
  for(int i=0;i<n;i++) cout << s.at(i) << s.at(i);
  cout << endl;

  exit(0);
}
