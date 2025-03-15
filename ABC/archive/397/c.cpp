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

int main() {
  int n;cin>>n;
  vector<int> a(n);cin>>a;
  map<int,int> x,y;
  int s = 0;
  int t = 0;
  rep(i,n) {
    auto it = y.find(a.at(i));
    if(it==y.end()) t++;
    y[a.at(i)]++;
  }
  int ans = 0;
  rep(i,n-1) {
    auto it = x.find(a.at(i));
    if(it==x.end()) s++;
    x[a.at(i)]++;
    auto itt = y.find(a.at(i));
    if((*itt).second==1) {
      t--;
      y.erase(itt);
    } else {
      y[a.at(i)]--;
    }
    ans = max(ans,s+t);
  }
  cout << ans << endl;

  return 0;
}
