#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using rpqi = priority_queue<int, vector<int>, greater<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n;cin>>n;
  vector p(n,set<int>());
  rep(i,n) {
    int c;cin>>c;
    rep(j,c) {
      int tmp;cin>>tmp;tmp--;
      p.at(i).insert(tmp);
    }
  }
  vector<int> ans;
  vector<bool> read(n,false);
  auto dfs = [&](auto f,int v) -> void {
    if(read.at(v)) return;
    for(int ele : p.at(v)) {
      f(f,ele);
    }
    ans.push_back(v);
    read.at(v) = true;
    return;
  };
  dfs(dfs,0);
  rep(i,ans.size()-1) cout << ans.at(i)+1 << " ";
  cout << endl;

  exit(0);
}
