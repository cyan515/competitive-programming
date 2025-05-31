#include <bits/stdc++.h>
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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
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
  int T;cin>>T;
  while(T--) {
    int n;cin>>n;
    string s;cin>>s;
    auto rl = run_length(s);
    int m = rl.size();
    vector dp(m+1,vector<int>(3,INF));
    dp.at(0).at(0) = 0;
    rep(i,m) {
      int zero = rl.at(i).first=='0'?rl.at(i).second:0;
      int one = rl.at(i).first=='1'?rl.at(i).second:0;
      chmin(dp.at(i+1).at(0),dp.at(i).at(0)+one);
      chmin(dp.at(i+1).at(1),dp.at(i).at(1)+zero);
      chmin(dp.at(i+1).at(1),dp.at(i).at(0)+zero);
      chmin(dp.at(i+1).at(2),dp.at(i).at(1)+one);
      chmin(dp.at(i+1).at(2),dp.at(i).at(2)+one);
      chmin(dp.at(i+1).at(2),dp.at(i).at(0)+one);
    }
    int ans = INF;
    rep(i,3) chmin(ans,dp.at(m).at(i));
    cout << ans << endl;
  }

  return 0;
}
