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
  ll n,t;cin>>n>>t;
  vector<ll> a(n);cin>>a;
  // time, type
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;
  rep(i,n) q.push(pair(a.at(i),0));
  q.push(pair(t,0));
  ll cur = 0;
  ll ans = 0;
  bool open = true;
  while(q.size()) {
    auto [time,op] = q.top();q.pop();
    if(op==0) {
      // close
      if(open) {
        q.push(pair(time+100,1));
        open = false;
        ans += time-cur;
        cur = time;
      }
    } else {
      // open
      if(!open) {
        open = true;
        cur = time;
      }
    }
    if(time==t) break;
  }
  cout << ans << endl;

  return 0;
}
