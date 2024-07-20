#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
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
  int n,k;cin>>n>>k;
  string s;cin>>s;
  sort(all(s));
  vector<string> st;
  do {
    st.push_back(s);
  } while(next_permutation(all(s)));
  int ans = 0;
  for(auto& x : st) {
    int l = x.size();
    bool ok = true;
    rep(i,l) {
      if(i+k-1>=l) continue;
      bool flg = true;
      rep(j,k/2) {
        flg &= x.at(i+j)==x.at(i+k-j-1);
      }
      ok &= !flg;
    }
    if(ok) ans++;
  }
  cout << ans << endl;

  return 0;
}
