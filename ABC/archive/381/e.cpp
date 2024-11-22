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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n,Q;cin>>n>>Q;
  string s;cin>>s;
  vector<int> slash(n+1,0);
  vector<int> o,t;
  o.push_back(-1);
  rep(i,n) {
    if(s.at(i)=='/') slash.at(i+1)++;
    if(s.at(i)=='1') o.push_back(i);
    if(s.at(i)=='2') t.push_back(i);
  }
  rep(i,n) slash.at(i+1) += slash.at(i);
  while(Q--) {
    int l,r;cin>>l>>r;l--;
    if(slash.at(r)-slash.at(l)==0) {
      cout << 0 << endl;
      continue;
    }
    auto oi = lower_bound(all(o),l) - o.begin();oi--;
    auto ti = lower_bound(all(t),r) - t.begin();
    int ok = 0;
    int ng = n;
    while(abs(ok-ng)>1) {
      int mid = (ok+ng)/2;
      if(oi+mid>=o.size()) {
        ng = mid;
        continue;
      }
      int left = o.at(oi+mid);
      if(ti-mid<0) {
        ng = mid;
        continue;
      }
      int right = t.at(ti-mid);
      if(slash.at(right)-slash.at(left)<=0) ng = mid;
      else ok = mid;
    }
    cout << 1+ok*2 << endl;
  }

  return 0;
}
