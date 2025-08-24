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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n;cin>>n;
  vector<int> r(n),c(n);
  rep(i,n) cin>>r.at(i)>>c.at(i);
  int mir = INF;
  int mar = -INF;
  int mic = INF;
  int mac = -INF;
  rep(i,n) {
    chmin(mir,r.at(i));
    chmax(mar,r.at(i));
    chmin(mic,c.at(i));
    chmax(mac,c.at(i));
  }
  int ma = max(mar-mir+1,mac-mic+1);
  cout << ma / 2 << endl;

  return 0;
}
