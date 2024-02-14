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

int main() {
  int n;cin>>n;int m;cin>>m;
  vector<int> p(n);
  vector<int> c(n);
  vector f(n,set<int>());
  rep(i,n) {
    cin >> p.at(i) >> c.at(i);
    rep(j,c.at(i)) {
      int fun;cin>>fun;
      f.at(i).insert(fun);
    }
  }
  bool ans = false;
  rep(i,n) rep(j,n) {
    bool flg = true;
    for(int ele : f.at(i)) {
      if(f.at(j).count(ele)==0) flg = false;
    }
    flg &= p.at(i)>=p.at(j);
    flg &= (p.at(i)>p.at(j) || f.at(i).size() < f.at(j).size());
    ans |= flg;
  }

  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  exit(0);
}
