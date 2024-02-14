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
  vector<int> f(n);
  vector<int> s(n);
  rep(i,n) cin>>f.at(i)>>s.at(i),f.at(i)--;
  vector aji(n,vector<int>());
  rep(i,n) {
    aji.at(f.at(i)).push_back(s.at(i));
  }
  rep(i,n) sort(all(aji.at(i))),reverse(all(aji.at(i)));
  vector<int> ma;
  rep(i,n) if(aji.at(i).size()) ma.push_back(aji.at(i).at(0));
  sort(all(ma));reverse(all(ma));
  int ans = 0;
  if(ma.size()>=2) ans = ma.at(0) + ma.at(1);
  rep(i,n) {
    if(aji.at(i).size()>=2) {
      int tmp = aji.at(i).at(0) + aji.at(i).at(1)/2;
      ans = max(ans,tmp);
    }
  }
  cout << ans << endl;

  exit(0);
}
