#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using Graph = vector<vector<int>>;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 1000000007;

bool ans = false;
int n;

void dfs(vector<vector<int>>& g, int node, set<int> seen) {
  seen.insert(node);
  if(seen.size()==n) ans = true;
  for(int next : g.at(node)) {
    if(seen.find(next)!=seen.end()) continue;
    dfs(g,next,seen);
  }
  seen.erase(node);
}

int main() {
  cin>>n;
  int m;cin>>m;
  vector<string> s(n);
  for(int i=0;i<n;i++) cin>>s.at(i);
  vector<vector<int>> g(n, vector<int>());
  for(int i=0;i<n;i++) {
    for(int j=i+1;j<n;j++) {
      int cnt = 0;
      for(int k=0;k<m;k++) {
        if(s.at(i).at(k)!=s.at(j).at(k)) cnt++;
      }
      if(cnt==1) {
        g.at(i).push_back(j);
        g.at(j).push_back(i);
      }
    }
  }
  for(int i=0;i<n;i++) {
    set<int> seen;
    dfs(g, i, seen);
  }

  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  exit(0);
}
