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
  ll w,h;cin>>w>>h;
  int n;cin>>n;
  vector<pair<int,int>> sb(n);
  for(int i=0;i<n;i++) cin>>sb.at(i).first>>sb.at(i).second;
  ll A;cin>>A;
  vector<int> a(A);
  for(int i=0;i<A;i++) cin>>a.at(i);
  ll B;cin>>B;
  vector<int> b(B);
  for(int i=0;i<B;i++) cin>>b.at(i);
  map<pair<int,int>,int> mp;
  for(int i=0;i<n;i++) {
    int x = sb.at(i).first;
    int y = sb.at(i).second;
    int xg = lower_bound(a.begin(), a.end() ,x) - a.begin();
    int yg = lower_bound(b.begin(), b.end(), y) - b.begin();
    pair<int,int> point = make_pair(xg,yg);
    mp[point]++;
  }
  int mi = INF;
  if(mp.size()<(A+1)*(B+1)) mi=0;
  int ma = -1;
  for(auto ele : mp) {
    mi = min(mi,ele.second);
    ma = max(ma,ele.second);
  }
  cout << mi << " " << ma << endl;

  exit(0);
}
