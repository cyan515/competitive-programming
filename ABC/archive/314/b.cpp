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

int main() {
  int n;cin>>n;
  vector a(n,set<int>());
  rep(i,n) {
    int c;cin>>c;
    rep(j,c) {
      int b;cin>>b;
      a.at(i).insert(b);
    }
  }
  int x;cin>>x;
  int mi = INF;
  rep(i,n) {
    if(a.at(i).count(x)) mi = min(mi,(int)a.at(i).size());
  }
  vector<int> ans;
  rep(i,n) {
    if(a.at(i).count(x) && a.at(i).size()==mi) ans.push_back(i+1);
  }
  cout << ans.size() << endl;
  rep(i,ans.size()) cout << ans.at(i) << " ";
  cout << endl;

  exit(0);
}
