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
    ll n,m;cin>>n>>m;
    vector<ll> a(n),b(n);cin>>a>>b;
    multiset<ll> st;
    rep(i,n) st.insert(a.at(i));
    ll ans = 0;
    rep(i,n) ans += a.at(i)+b.at(i);
    rep(i,n) {
      auto it = st.lower_bound(m-b.at(i));
      if(it!=st.end()) {
        ans -= m;
        st.erase(it);
      }
    }
    cout << ans << endl;
  }

  return 0;
}
