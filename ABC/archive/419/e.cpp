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
  int n,m,l;cin>>n>>m>>l;
  vector<ll> a(n);cin>>a;
  // auto dfs = [&](auto self,int v) -> void {
  //   if(v==10) {
  //     rep(i,n) {
  //       int sum = 0;
  //       bool ov = false;
  //       reps(j,i,i+l) {
  //         if(j>=n) {
  //           ov = true;
  //           break;
  //         }
  //         sum += a.at(j);
  //       }
  //       if(ov) continue;
  //       if(sum%m) return;
  //     }
  //     rep(i,n) cout << a.at(i) << " ";
  //     cout << endl;
  //     return;
  //   }
  //   rep(i,n) {
  //     a.at(i)++;
  //     self(self,v+1);
  //     a.at(i)--;
  //   }
  // };
  // dfs(dfs,0);

  return 0;
}
