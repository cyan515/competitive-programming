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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  vector<int> a(6);cin>>a;
  // キープ状態、ふった回数、出目状態 の 期待値の最大値
  vector dp(1<<5,vector(3,map<array<int,5>,long double>()));
  rep(i,3) {
    array<int,5> arr = {0,0,0,0,0};
    auto dfs = [&](auto self,int v) -> void {
      if(v==5) {
        long double ma = 0.0;
        for(auto ele : a) {
          int cnt = 0;
          for(auto elee : arr) if(ele == elee) cnt++;
          chmax(ma,(long double)cnt*ele);
        }
        dp.at((1<<5)-1).at(i)[arr] = ma;
        return;
      }
      rep(ii,6) {
        arr.at(v) = a.at(ii);
        self(self,v+1);
        arr.at(v) = 0;
      }
    };
  }
  for(int i=(1<<5)-1;i>=0;i--) {
    
  }
  cout << fixed << setprecision(20) << dp.at(0).at(0).at({0,0,0,0,0});

  return 0;
}
