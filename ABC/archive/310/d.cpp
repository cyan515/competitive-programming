#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using rpqi = priority_queue<int, vector<int>, greater<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

vector<set<int>> team;
vector<set<int>> ab;
int n,t,m;
set<set<set<int>>> cnt;

void dfs(int v) {
  if(v==n) {
    bool flg = true;
    rep(i,t) if(team.at(i).empty()) flg = false;
    if(!flg) return;
    set<set<int>> tmp;
    rep(i,t) tmp.insert(team.at(i));
    cnt.insert(tmp);
    return;
  }

  int ret = 0;
  rep(i,t) {
    bool flg = true;
    for(int ele : team.at(i)) {
      if(ab.at(v).count(ele)) flg = false;
    }
    if(!flg) continue;
    team.at(i).insert(v);
    dfs(v+1);
    team.at(i).erase(v);
    if(team.at(i).empty()) break;
  }
  return;
}

int main() {
  cin>>n>>t>>m;
  team.resize(t);
  ab.resize(n);
  rep(i,m) {
    int a,b;cin>>a>>b;a--;b--;
    ab.at(a).insert(b);
    ab.at(b).insert(a);
  }
  dfs(0);
  cout << cnt.size() << endl;

  exit(0);
}
