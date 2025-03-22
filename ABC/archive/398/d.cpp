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

int main() {
  int n;cin>>n;
  int r,c;cin>>r>>c;
  int x = r;
  int y = c;
  string s;cin>>s;
  vector<bool> ans(n);
  set<pair<int,int>> st;
  st.insert(pair(0,0));
  rep(i,n) {
    int dx = 0;
    int dy = 0;
    if(s.at(i)=='N') {
      dx = 1;
    } else if(s.at(i)=='W') {
      dy = 1;
    } else if(s.at(i)=='S') {
      dx = -1;
    } else if(s.at(i)=='E') {
      dy = -1;
    }
    x += dx;
    y += dy;
    ans.at(i) = st.count(pair(x,y));
    st.insert(pair(x-r,y-c));
  }
  rep(i,n) {
    if(ans.at(i)) cout << "1";
    else cout << "0";
  }
  cout << endl;

  return 0;
}
