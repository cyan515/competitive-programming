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
  int d;cin>>d;
  dsu D(n);
  vector<pair<int,int>> p(n);
  for(int i=0;i<n;i++) cin>>p.at(i).first>>p.at(i).second;
  for(int i=0;i<n;i++) {
    for(int j=i+1;j<n;j++) {
      int x = p.at(i).first;
      int y = p.at(i).second;
      int s = p.at(j).first;
      int t = p.at(j).second;
      if((x-s)*(x-s)+(y-t)*(y-t)<=d*d) D.merge(i,j);
    }
  }

  for(int i=0;i<n;i++) {
    if(D.same(0,i)) cout << "Yes" << endl;
    else cout << "No" << endl;
  }

  exit(0);
}
