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
  int T;cin>>T;
  while(T--) {
    int n;cin>>n;
    vector<int> a(2*n);cin>>a;
    vector<bool> seen(n,false);
    rep(i,2*n) {
      if(seen.at(a.at(i)-1)) a.at(i) += n;
      else seen.at(a.at(i)-1) = true;
    }
    vector<bool> ok(2*n,true);
    rep(i,2*n) {
      if(i!=0) {
        int x = min(a.at(i-1),a.at(i));
        int y = max(a.at(i-1),a.at(i));
        if(x+n==y) ok.at(i) = false;
      }
      if(i!=2*n-1) {
        int x = min(a.at(i),a.at(i+1));
        int y = max(a.at(i),a.at(i+1));
        if(x+n==y) ok.at(i) = false;
      }
    }
    set<pair<int,int>> st;
    rep(i,2*n-1) {
      if(!ok.at(i)) continue;
      if(!ok.at(i+1)) continue;
      int x = min(a.at(i),a.at(i+1));
      int y = max(a.at(i),a.at(i+1));
      st.insert(pair(x,y));
    }
    int ans = 0;
    auto f = [&](int val) -> int {
      if(val>n) return val - n;
      else return val + n;
    };
    for(auto [x,y] : st) {
      int xx = f(x);
      int yy = f(y);
      if(xx>yy) swap(xx,yy);
      if(st.count(pair(xx,yy))) ans++;
    }
    cout << ans/2 << endl;
  }

  return 0;
}
