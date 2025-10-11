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

int main() {
  int n,m;cin>>n>>m;
  int ans = INF;
  vector<int> us(m),vs(m);
  rep(i,m) cin>>us.at(i)>>vs.at(i);
  rep(i,m) us.at(i)--,vs.at(i)--;
  rep(bit,1<<n) {
    vector<int> col(n);
    rep(i,n) {
      if((bit&(1<<i))==0) col.at(i) = 0;
      else col.at(i) = 1;
    }
    int cnt = 0;
    rep(i,m) {
      if(col.at(us.at(i))==col.at(vs.at(i))) cnt++;
    }
    ans = min(ans,cnt);
  }
  cout << ans << endl;

  return 0;
}
