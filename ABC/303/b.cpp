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
  set<pair<int,int>> st;
  vector<vector<int>> v(m, vector<int>(n));
  for(int i=0;i<m;i++) {
    for(int j=0;j<n;j++) cin>>v.at(i).at(j);
  }

  for(int i=0;i<m;i++) {
    for(int j=0;j<n-1;j++) {
      if(v.at(i).at(j)<v.at(i).at(j+1)) st.insert(make_pair(v.at(i).at(j),v.at(i).at(j+1)));
      else st.insert(make_pair(v.at(i).at(j+1),v.at(i).at(j)));
    }
  }

  int ans = n*(n-1)/2;
  ans -= st.size();
  cout << ans << endl;

  exit(0);
}
