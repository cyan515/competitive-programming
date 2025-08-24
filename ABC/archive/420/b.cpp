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
  int n,m;cin>>n>>m;
  vector<string> s(n);cin>>s;
  vector<int> p(n,0);
  rep(j,m) {
    int cnt = 0;
    rep(i,n) {
      if(s.at(i).at(j)=='1') cnt++;
    }
    char tgt;
    if(cnt>n/2) tgt = '0';
    else tgt = '1';
    rep(i,n) if(s.at(i).at(j)==tgt) p.at(i)++;
  }
  int ma = *max_element(all(p));
  vector<int> ans;
  rep(i,n) if(p.at(i)==ma) ans.push_back(i+1);
  rep(i,ans.size()) {
    if(i) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;

  return 0;
}
