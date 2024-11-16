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
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

vector<pair<char, int>> run_length(const string& str) {
  int n = (int)str.size();
  vector<pair<char, int>> ret;
  for (int l = 0; l < n;) {
    int r = l + 1;
    for (; r < n && str[l] == str[r]; r++) {};
    ret.push_back({str[l], r - l});
    l = r;
  }
  return ret;
}

int main() {
  int n,k;cin>>n>>k;
  string s;cin>>s;
  auto r = run_length(s);
  int m = r.size();
  int cur = 0;
  rep(i,m) {
    if(r.at(i).first=='1') cur++;
    if(cur==k) swap(r.at(i),r.at(i-1));
  }
  rep(i,m) {
    rep(j,r.at(i).second) cout << r.at(i).first;
  }
  cout << endl;

  return 0;
}
