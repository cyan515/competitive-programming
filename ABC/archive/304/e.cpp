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
  int m;cin>>m;
  dsu D(n);
  for(int i=0;i<m;i++) {
    int u,v;cin>>u>>v;u--;v--;
    D.merge(u,v);
  }
  int k;cin>>k;
  set<pair<int,int>> st;
  for(int i=0;i<k;i++) {
    int x,y;cin>>x>>y;x--;y--;
    x = D.leader(x);
    y = D.leader(y);
    if(y<x) swap(x,y);
    st.insert(make_pair(x,y));
  }
  int Q;cin>>Q;
  while(Q--) {
    int p,q;cin>>p>>q;p--;q--;
    p = D.leader(p);
    q = D.leader(q);
    if(q<p) swap(p,q);
    pair<int,int> pr = make_pair(p,q);
    if(st.find(pr)==st.end()) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

  exit(0);
}
