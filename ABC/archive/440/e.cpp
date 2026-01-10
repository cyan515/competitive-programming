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
  ll n,k,x;cin>>n>>k>>x;
  vector<ll> a(n);cin>>a;
  sort(all(a));
  priority_queue<pair<ll,vector<int>>> q;
  {
    vector<int> b(n,0);
    b.back() = k;
    q.push(pair(k*a.back(),b));
  }
  int xx = x;
  vector<ll> ans;
  set<vector<int>> seen;
  while(xx--) {
    auto [s,sel] = q.top();q.pop();
    ans.push_back(s);
    if(q.size()>x) continue;
    reps(i,1,n) {
      if(sel.at(i)==0) continue;
      auto nsel = sel;
      nsel.at(i-1)++;
      nsel.at(i)--;
      if(seen.count(nsel)) continue;
      seen.insert(nsel);
      ll ns = s;
      ns += a.at(i-1);
      ns -= a.at(i);
      q.push(pair(ns,nsel));
    }
  }
  sort(rall(ans));
  rep(i,x) cout<<ans.at(i)<<endl;

  return 0;
}
