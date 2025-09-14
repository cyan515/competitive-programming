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
template <class T> using pqueue = std::priority_queue<T,std::vector<T>,std::greater<T>>;

int main() {
  ll n,k;cin>>n>>k;
  vector<ll> a(n),b(n),c(n);
  rep(i,n) cin>>a.at(i)>>b.at(i)>>c.at(i);
  // time, in/out(1/0), index
  // priority_queue<tuple<ll,int,int>,vector<tuple<ll,int,int>>,greater<>> q;
  // time, index
  pqueue<pair<ll,int>> q;
  vector<ll> ans(n,0);
  ll cur_cnt = 0;
  ll cur_time = 0;
  rep(i,n) {
    while(cur_cnt+c.at(i)>k) {
      auto [t,idx] = q.top();q.pop();
      cur_time = t;
      cur_cnt -= c.at(idx);
    }
    ans.at(i) = max(a.at(i),cur_time);
    q.push(pair(ans.at(i)+b.at(i),i));
    cur_cnt += c.at(i);
  }
  rep(i,n) cout<<ans.at(i)<<endl;

  return 0;
}
