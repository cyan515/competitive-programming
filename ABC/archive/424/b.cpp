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
  int n,m,k;cin>>n>>m>>k;
  vector<int> ans;
  vector cur(n,vector<bool>(m,false));
  while(k--) {
    int a,b;cin>>a>>b;a--;b--;
    bool ok = true;
    rep(i,m) ok &= cur.at(a).at(i);
    if(ok) continue;
    cur.at(a).at(b) = true;
    ok = true;
    rep(i,m) ok &= cur.at(a).at(i);
    if(ok) ans.push_back(a);
  }
  rep(i,ans.size()) {
    if(i) cout<<" ";
    cout<<ans.at(i)+1;
  }
  cout<<endl;

  return 0;
}
