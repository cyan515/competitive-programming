#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 998244353;

int n,m,k;
vvi g;
vector<bool> seen;
// 座標　体力
vector<pair<int,int>> keibi;
map<int,int> mp;

void bfs() {
  // 体力　座標
  priority_queue<pair<int,int>> q;
  for(int i=0;i<k;i++) {
    q.push(make_pair(mp.at(keibi.at(i).first),keibi.at(i).first));
    seen.at(keibi.at(i).first) = true;
  }
  while(q.size()) {
    pair<int,int> now = q.top();
    q.pop();
    if(now.first==0) continue;
    for(int ele : g.at(now.second)) {
      if(seen.at(ele)) continue;
      if(mp.find(ele)!=mp.end()) {
        mp.at(ele) = max(mp.at(ele),now.first-1);
        q.push(make_pair(mp.at(ele),ele));
      } else {
        mp[ele] = now.first-1;
        q.push(make_pair(now.first-1,ele));
      }
      seen.at(ele) = true;
    }
  }
}

int main() {
  cin>>n;
  cin>>m;
  cin>>k;
  g.resize(n);
  seen.resize(n);
  for(int i=0;i<m;i++) {
    int a,b;cin>>a>>b;
    a--;b--;
    g.at(a).push_back(b);
    g.at(b).push_back(a);
  }
  keibi.resize(k);
  for(int i=0;i<k;i++) {
    int p,h;cin>>p>>h;p--;
    keibi.at(i).first = h;
    keibi.at(i).second = p;
    mp[p]=h;
  }
  sort(keibi.begin(),keibi.end());
  reverse(keibi.begin(),keibi.end());
  for(int i=0;i<k;i++) swap(keibi.at(i).first, keibi.at(i).second);

  bfs();

  int cnt = 0;
  vector<int> ans;
  for(int i=0;i<n;i++) if(seen.at(i)) cnt++,ans.push_back(i+1);
  cout << cnt << endl;
  for(int i=0;i<cnt;i++) {
    cout << ans.at(i);
    if(i==cnt-1) cout << endl;
    else cout << " ";
  }
  
  exit(0);
}
