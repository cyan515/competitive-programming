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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  ll n,k;cin>>n>>k;
  string s;cin>>s;
  int ma = 0;
  rep(i,n-k+1) {
    string t = s.substr(i,k);
    int cnt = 0;
    rep(j,n-k+1) cnt += !!(s.substr(j,k)==t);
    ma = max(ma,cnt);
  }
  set<string> ans;
  rep(i,n-k+1) {
    string t = s.substr(i,k);
    int cnt = 0;
    rep(j,n-k+1) cnt += !!(s.substr(j,k)==t);
    if(cnt==ma) ans.insert(t);
  }
  vector<string> anss;
  for(auto e : ans) {
    anss.push_back(e);
  }
  cout << ma << endl;
  rep(i,anss.size()) {
    if(i) cout << " ";
    cout << anss.at(i);
  }
  cout << endl;

  return 0;
}
