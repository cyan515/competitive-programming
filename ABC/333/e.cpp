#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  int n;cin>>n;
  vector<pair<int,int>> e(n);
  rep(i,n) cin>>e.at(i).first>>e.at(i).second,e.at(i).second--;
  vector<int> mons(n);
  rep(i,n) {
    if(e.at(i).first==1) continue;
    mons[e.at(i).second]++;
  }
  vector<int> mons_cnt(n,0);
  vector<int> port_cnt(n,0);
  vector<bool> take(n,false);
  for(int i=n-1;i>=0;i--) {
    if(e.at(i).first==1) {
      if(mons_cnt.at(e.at(i).second)>port_cnt.at(e.at(i).second)) {
        take.at(i)=true;
        port_cnt.at(e.at(i).second)++;
      }
    } else {
      mons_cnt.at(e.at(i).second)++;
    }
  }
  
  int ng = -1;
  int ok = INF;
  while(abs(ok-ng)>1) {
    int mid = (ok+ng)/2;
    vector<int> port(n,0);
    vector<int> ab(n,0);
    int cnt = 0;
    bool flg = true;
    rep(i,n) {
      if(e.at(i).first==1){
        if(cnt<mid && mons[e.at(i).second]-ab[e.at(i).second] > port[e.at(i).second] && take.at(i)) port[e.at(i).second]++,cnt++;
      } else {
        if(port[e.at(i).second]==0) {
          flg = false;
        } else {
          port[e.at(i).second]--;
          ab[e.at(i).second]++;
          cnt--;
        }
      } 
    }
    if(flg) ok = mid;
    else ng = mid;
  }
  if(ok==INF) {
    cout << -1 << endl;
  } else {
    cout << ok << endl;
    vector<int> ans;
    int cnt = 0;
    vector<int> port(n,0);
    vector<int> ab(n,0);
    rep(i,n) {
      if(e.at(i).first==1) {
        if(cnt<ok && mons[e.at(i).second]-ab[e.at(i).second] > port[e.at(i).second] && take.at(i)) port[e.at(i).second]++,ans.push_back(1),cnt++;
        else ans.push_back(0);
      } else {
        port[e.at(i).second]--;
        ab[e.at(i).second]++;
        cnt--;
      } 
    }
    rep(i,ans.size()) {
      cout << ans.at(i);
      if(i==ans.size()-1) cout << endl;
      else cout << " ";
    }
  }

  exit(0);
}
