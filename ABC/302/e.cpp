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
  int q;cin>>q;
  vector<set<int>> g(n,set<int>());
  int cnt = n;
  while(q--) {
    int a;cin>>a;
    if(a==1) {
      int u,v;cin>>u>>v;u--;v--;
      if(g.at(u).empty()) cnt--;
      if(g.at(v).empty()) cnt--;
      g.at(u).insert(v);
      g.at(v).insert(u);
    } else {
      int v;cin>>v;v--;
      for(int ele : g.at(v)) {
        g.at(ele).erase(v);
        if(g.at(ele).empty()) cnt++;
      }
      if(!g.at(v).empty()) cnt++;
      g.at(v).clear();
    }
    cout << cnt << endl;
  }

  exit(0);
}
