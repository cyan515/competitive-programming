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
  map<int,vector<int>> mp;
  rep(i,n) mp[a.at(i)].push_back(i);
  int ans = INF;
  for(auto [k,vec] : mp) {
    if(vec.size()==1) continue;
    int m = vec.size();
    rep(i,m-1) {
      ans = min(ans,vec.at(i+1)-vec.at(i)+1);
    }
  }
  if(ans == INF) ans = -1;
  cout << ans << endl;

  return 0;
}
