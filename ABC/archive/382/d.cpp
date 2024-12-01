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
  int n,m;cin>>n>>m;
  vector<int> vec;
  vector<vector<int>> ans;
  auto f = [&](auto f,int dep) -> void {
    if(dep==n) {
      ans.push_back(vec);
      return;
    }
    int r = n-dep-1;
    if(vec.empty()) {
      reps(i,1,m+1) {
        if(i+r*10>m) break;
        vec.push_back(i);
        f(f,dep+1);
        vec.pop_back();
      }
    } else {
      int x = vec.back();
      reps(i,0,m+1) {
        if(x+10+i+r*10>m) break;
        vec.push_back(x+10+i);
        f(f,dep+1);
        vec.pop_back();
      }
    }
  };
  f(f,0);
  cout << ans.size() << endl;
  rep(i,ans.size()) {
    rep(j,ans.at(i).size()) {
      if(j) cout << " ";
      cout << ans.at(i).at(j);
    }
    cout << endl;
  }

  return 0;
}
