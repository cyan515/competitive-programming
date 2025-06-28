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
  int T;cin>>T;
  while(T--) {
    int n;cin>>n;
    int x;cin>>x;
    vector<int> s(n-2);cin>>s;
    int y;cin>>y;
    multiset<int> st;
    rep(i,n-2) st.insert(s.at(i));
    int cur = x;
    bool ok = true;
    int ans = 2;
    while(st.size()&&cur*2<y) {
      auto it = st.upper_bound(cur*2);
      if(it == st.begin()) {
        ok = false;
        break;
      }
      it--;
      cur = *it;
      st.erase(it);
      ans++;
    }
    if(ok&&cur*2>=y) {
      cout << ans << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}
