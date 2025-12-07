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

// https://atcoder.jp/contests/code-festival-2015-qualb/submissions/67567213
int main() {
  ll n;cin>>n;
  int Q;cin>>Q;
  set<pair<ll,ll>> st;
  st.insert(pair(-LINF,-LINF));
  st.insert(pair(LINF,LINF));
  ll ans = n;
  while(Q--) {
    ll l,r;cin>>l>>r;r++;
    pair<ll,ll> p = pair(l,LINF);
    auto it = st.upper_bound(p);
    ll nl = l;
    ll nr = r;
    ll delta = 0;
    if(it!=st.begin()) {
      it--;
      auto [le,ri] = *it;
      if(le<=l&&r<=ri) {
        cout<<ans<<endl;
        continue;
      }
      if(ri<l) it++;
      else {
        nl = le;
        delta = -(ri-le);
        it = st.erase(it);
      }
    }
    auto [le,ri] = *it;
    while(le<=nr) {
      nr = max(nr,ri);
      auto [xle,xri] = *it;
      delta -= xri-xle;
      it = st.erase(it);
      auto [nxle,nxri] = *it;
      le = nxle;
      ri = nxri;
    }
    delta += nr-nl;
    st.insert(pair(nl,nr));
    ans -= delta;
    
    cout << ans << endl;
  }

  return 0;
}
