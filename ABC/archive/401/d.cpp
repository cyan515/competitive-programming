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
  ll n,k;cin>>n>>k;
  string s;cin>>s;
  rep(i,n) {
    if(i!=0&&s.at(i-1)=='o') s.at(i) = '.';
    if(i!=n-1&&s.at(i+1)=='o') s.at(i) = '.';
    if(s.at(i)=='o') k--;
  }
  auto r = run_length(s);
  int cnt = 0;
  for(auto [c,x] : r) {
    if(c!='?') continue;
    cnt += (x+1)/2;
  }
  if(k==cnt) {
    int idx = 0;
    for(auto [c,x] : r) {
      if(c=='?'&&x%2==1) {
        rep(i,x) {
          s.at(idx+i) = i%2==0?'o':'.';
        }
      }
      idx += x;
    }
  }
  if(k==0) {
    rep(i,n) {
      if(s.at(i)=='?') s.at(i) = '.';
    }
  }
  cout << s << endl;

  return 0;
}
