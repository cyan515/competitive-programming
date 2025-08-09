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
  string s;cin>>s;
  int n = s.size();
  double ans = 0.0;
  rep(l,n) reps(r,l+1,n+1) {
    string t = s.substr(l,r-l);
    if(t.front()!='t'||t.back()!='t') continue;
    if(t.size()<3) continue;
    int x = 0;
    reps(i,l,r) if(s.at(i)=='t') x++;
    ans = max(ans,double(x-2)/(t.size()-2));
  }
  cout << fixed << setprecision(20) << ans << endl;

  return 0;
}
