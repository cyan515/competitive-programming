#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 998244353;

vector<int> ans;

// DFS
vector<bool> seen;
void dfs(const vvi& G, int V, bool is1) {
  seen.at(V) = true;

  bool flg = false;

  if(V!=0&&G.at(V).size()==1) flg = true;

  for (int next : G.at(V)) {
    if (seen.at(next)) continue;
    if(is1&&flg) {
      ans.push_back(G.at(next).size()+1);
      dfs(G, next, false);
    }
    else dfs(G, next, flg);
  }
}

int main() {
  int n;cin>>n;
  seen.resize(n);
  vvi t(n, vector<int>(0));
  for(int i=0;i<n-1;i++) {
    int u,v;cin>>u>>v;u--;v--;
    if(v<u) swap(u,v);
    t.at(u).push_back(v);
  }

  if(t.at(0).size()==0) dfs(t,0,true);
  else dfs(t,0,true);

  sort(ans.begin(),ans.end());
  for(int i=0;i<ans.size();i++) {
    cout << ans.at(i);
    if(i==ans.size()-1) cout << endl;
    else cout << " ";
  }

  exit(0);
}
