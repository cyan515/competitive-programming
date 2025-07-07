#include <bits/stdc++.h>
#include <atcoder/math>
using namespace std;
using namespace atcoder;
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
  // vector<pair<int,int>> v;
  // rep(i,19) rep(j,19) {
  //   v.push_back(pair(i*pow_mod(2,j,INF),(i+1)*pow_mod(2,j,INF)));
  // }
  // sort(all(v));
  // for(auto [x,y] : v) cout << x << " " << y << endl;
  int T;cin>>T;
  while(T--) {
    int n;cin>>n;
    vector<ll> a(1<<n);cin>>a;
    auto dfs = [&](auto self,int l,int r) -> void {
      if(abs(l-r)<=1) return;
      int idx = -1;
      ll mi = LINF;
      reps(i,l,r) {
        if(chmin(mi,a.at(i))) idx = i;
      }
      int dl = abs(idx-l);
      int dr = abs(idx-(r-1));
      if(dl>dr) {
        reverse(a.begin()+l,a.begin()+r);
      }
      int mid = l+(r-l)/2;
      self(self,l,mid);
      self(self,mid,r);
    };
    dfs(dfs,0,1<<n);
    rep(i,1<<n) {
      if(i) cout << " ";
      cout << a.at(i);
    }
    cout << endl;
  }

  return 0;
}
