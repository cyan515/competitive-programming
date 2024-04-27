#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

void solve() {
  ll n;cin>>n;
  vector<vector<int>> ans;
  ll m = 0;
  rep(i,n) {
    m += (i+1)*(i*2+1);
  }
  rep(i,n) {
    vector<int> op1;
    op1.push_back(1);
    op1.push_back(i+1);
    for(int j=n;j>0;j--) op1.push_back(j);
    vector<int> op2;
    op2.push_back(2);
    op2.push_back(i+1);
    for(int j=n;j>0;j--) op2.push_back(j);
    ans.push_back(op1);
    ans.push_back(op2);
  }
  cout << m << " " << ans.size() << "\n";
  rep(i,ans.size()) {
    rep(j,ans.at(i).size()) {
      cout << ans.at(i).at(j);
      if(j==ans.at(i).size()-1) cout << "\n";
      else cout << " ";
    }
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int t;cin>>t;
  while(t--) solve();

  return 0;
}
