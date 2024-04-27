#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}

int main() {
  string s;cin>>s;
  int n = s.size();
  vector<int> cnt(26,0);
  rep(i,n) cnt.at(s.at(i)-'a')++;
  int ma = -1;
  int ans;
  rep(i,26) if(chmax(ma,cnt.at(i))) ans = i;
  char c = 'a'+ans;
  cout << c << endl;

  exit(0);
}
