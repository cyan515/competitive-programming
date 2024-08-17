#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
const string Yes = "Yes";
const string No = "No";
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int n;cin>>n;
  vector<string> s(n);cin>>s;
  int m = 0;
  rep(i,n) m = max(m,(int)s.at(i).size());
  vector<int> ma(n,0);
  ma.at(0) = s.at(0).size();
  reps(i,1,n) ma.at(i) = max(ma.at(i-1),(int)s.at(i).size());
  vector<string> ans(m,"");
  rep(i,n) {
    rep(j,ma.at(n-1-i)) {
      if(s.at(n-1-i).size()>j) ans.at(j).push_back(s.at(n-1-i).at(j));
      else ans.at(j).push_back('*');
    }
    
  }
  rep(i,m) cout << ans.at(i) << endl;

  return 0;
}
