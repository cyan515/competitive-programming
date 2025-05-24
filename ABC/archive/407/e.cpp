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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};
int op(int a,int b) {
  return min(a,b);
}
int e() {
  return INF;
}
int mapping(int f, int s) {
  return f+s;
}
int comp(int f,int g) {
  return f+g;
}
int id() {
  return 0;
}
int main() {
  int T;cin>>T;
  while(T--) {
    int n;cin>>n;
    n *= 2;
    vector<ll> a(n);cin>>a;
    ll ans = 0;
    priority_queue<ll> q;
    int cur = 0;
    rep(i,n) {
      q.push(a.at(i));
      cur--;
      while(cur<0) {
        cur += 2;
        ll val = q.top();q.pop();
        ans += val;
      }
    }
    cout << ans << endl;
  }

  return 0;
}
