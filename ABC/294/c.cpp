#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 1000000007;

int main() {
  int n,m;cin>>n>>m;
  vector<int> a(n);
  vector<int> aans(n);
  vector<int> b(m);
  vector<int> bans(m);
  // value, from, key
  vector<pair<int,pair<int,int>>> c(0);
  for(int i=0;i<n;i++) cin>>a.at(i);
  for(int i=0;i<m;i++) cin>>b.at(i);
  for(int i=0;i<n;i++) {
    pair<int,pair<int,int>> x;
    x = make_pair(a.at(i),make_pair(0,i));
    c.push_back(x);
  }
  for(int i=0;i<m;i++) {
    pair<int,pair<int,int>> x;
    x = make_pair(b.at(i),make_pair(1,i));
    c.push_back(x);
  }
  sort(c.begin(), c.end());

  for(int i=0;i<c.size();i++) {
    if(c.at(i).second.first==0) {
      aans.at(c.at(i).second.second) = i+1;
    } else {
      bans.at(c.at(i).second.second) = i+1;
    }
  }

  for(int i=0;i<n;i++) {
    cout << aans.at(i);
    if(i==n-1) cout << endl;
    else cout << " ";
  }
  for(int i=0;i<m;i++) {
    cout << bans.at(i);
    if(i==m-1) cout << endl;
    else cout << " ";
  }
  

  exit(0);
}
