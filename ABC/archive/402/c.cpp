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
  int n,m;cin>>n>>m;
  vector<int> k(m);
  vector a(m,vector<int>());
  // 各食材がどの料理に入っているか
  vector aa(n,vector<int>());
  rep(i,m) {
    cin>>k.at(i);
    a.at(i).resize(k.at(i));cin>>a.at(i);
    rep(j,k.at(i)) a.at(i).at(j)--;
    rep(j,k.at(i)) {
      aa.at(a.at(i).at(j)).push_back(i);
    }
  }
  int ans = 0;
  vector<int> b(n);cin>>b;
  rep(i,n) b.at(i)--;
  rep(i,n) {
    for(auto ele : aa.at(b.at(i))) {
      k.at(ele)--;
      if(k.at(ele)==0) {
        ans++;
      }
    }
    cout << ans << endl;
  }

  return 0;
}
