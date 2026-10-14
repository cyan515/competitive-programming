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
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int T;cin>>T;
  while(T--) {
    ll n;cin>>n;
    vector<ll> r(n);cin>>r;
    auto rr = r;
    // rep(i,n) r.at(i)--;
    // vector<ll> dp(n,LINF);
    // rep(i,n+1) {
    //   if(r.at(i)>=i) dp.at(i) = r.at(i) - i;
    // }
    // rep(i,n-1) {
    //   vector<ll> ndp(n,LINF);
    //   swap(dp,ndp);
    // }
    // ll ans = *min_element(all(dp));
    // cout << ans << endl;
    
    vector<bool> done(n,false);
    ll ans = 0;
    // row, index
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<>> q,del;
    rep(i,n) q.push(pair(r.at(i),i));
    while(q.size()) {
      auto pa = q.top();q.pop();
      if(del.size()&&del.top()==pa) {
        del.pop();
        continue;
      }
      auto [row,idx] = pa;
      if(done.at(idx)) {
        continue;
      }
      done.at(idx) = true;
      if(idx!=0 && !done.at(idx-1) && abs(rr.at(idx)-rr.at(idx-1))>1) {
        del.push(pair(rr.at(idx-1),idx-1));
        rr.at(idx-1) = rr.at(idx) + 1;
        q.push(pair(rr.at(idx-1),idx-1));
      }
      if(idx!=n-1 && !done.at(idx+1) && abs(rr.at(idx)-rr.at(idx+1))>1) {
        del.push(pair(rr.at(idx+1),idx+1));
        rr.at(idx+1) = rr.at(idx) + 1;
        q.push(pair(rr.at(idx+1),idx+1));
      }
    }
    rep(i,n) ans += abs(r.at(i)-rr.at(i));
    cout << ans << endl;
  }

  return 0;
}
