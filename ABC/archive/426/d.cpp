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
    ll n;cin>>n;
    string st;cin>>st;
    ll ans = LINF;
    auto f = [&](string& s) -> ll {
      auto rl = run_length(s);
      ll one = 0;
      ll zero = 0;
      ll ma = 0;
      for(auto [c,len] : rl) {
        if(c=='1') {
          one += len;
          continue;
        }
        chmax(ma,(ll)len);
        zero += len;
      }
      return (zero-ma)*2+one;
    };
    auto x = f(st);
    chmin(ans,x);
    rep(i,n) {
      if(st.at(i)=='0') st.at(i) = '1';
      else st.at(i) = '0';
    }
    x = f(st);
    chmin(ans,x);
    cout << ans << endl;
  }

  return 0;
}
