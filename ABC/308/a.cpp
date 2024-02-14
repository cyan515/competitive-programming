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
  vector<int> a(8);
  rep(i,8) cin>>a.at(i);
  bool flg = true;
  rep(i,7) if(a.at(i)>a.at(i+1)) flg = false;
  rep(i,8) if(a.at(i)<100 || 675<a.at(i)) flg = false;
  rep(i,8) if(a.at(i)%25!=0) flg = false;
  if(flg) cout << "Yes" << endl;
  else cout << "No" << endl; 

  exit(0);
}
