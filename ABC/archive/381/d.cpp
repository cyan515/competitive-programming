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
  vector<int> a(n);cin>>a;
  int ans = 0;
  int l = 0;
  int r = 0;
  vector<int> cnt(n+1,0);
  while(l<n&&r<n) {
    if((r-l)%2==1&&cnt.at(a.at(r))==1) {
      cnt.at(a.at(r))++;
      r++;
    }
    while(r<n-1&&cnt.at(a.at(r))==0&&a.at(r)==a.at(r+1)) {
      cnt.at(a.at(r)) += 2;
      r += 2;
    }
    chmax(ans,r-l);
    if(l<r) cnt.at(a.at(l))--;
    l++;
    chmax(r,l);
  }
  cout << ans << endl;

  return 0;
}
