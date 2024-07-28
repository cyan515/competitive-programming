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

int main() {
  int n,m;cin>>n>>m;
  vector<tuple<ll,int,int>> a(m);
  rep(i,m) {
    ll l,r,c;cin>>l>>r>>c;
    a.at(i) = tuple(c,l,r);
  }
  sort(all(a));
  set<int> st;
  rep(i,n-1) st.insert(i+1);
  ll ans = 0;
  rep(i,m) {
    auto [c,l,r] = a.at(i);
    auto it = st.lower_bound(l);
    ans += c;
    vector<int> vec;
    while(it!=st.end()&&*it<r) {
      ans += c;
      vec.push_back(*it);
      it++;
    }
    for(auto ele : vec) {
      st.erase(ele);
    }
  }
  if(st.empty()) cout << ans << endl;
  else cout << -1 << endl;

  return 0;
}
