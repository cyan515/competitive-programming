#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  string s,t;cin>>s>>t;
  int n=s.size();
  int m = t.size();
  int i = 0,j = 0;
  vector<int> ans;
  while(i<n) {
    if(s.at(i)==t.at(j)) {
      ans.push_back(j+1);
      i++;
    }
    j++;
  }
  rep(i,ans.size()) {
    if(i) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;

  return 0;
}
