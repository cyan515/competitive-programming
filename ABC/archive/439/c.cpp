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
  ll n;cin>>n;
  set<int> st,tt;
  vector<bool> a(n+1,false),b(n+1,false);
  for(ll x = 1;x*x<=n;x++) {
    for(ll y = x+1;x*x+y*y<=n;y++) {
      int z = x*x+y*y;
      if(z>n) break;
      if(a.at(z)) b.at(z) = true;
      else a.at(z) = true;
      // if(st.contains(x*x+y*y)) {
      //   tt.insert(x*x+y*y);
      // } else {
      //   st.insert(x*x+y*y);
      // }
    }
  }
  // for(auto ele : tt) {
  //   st.erase(ele);
  // }
  // vector<int> ans(all(st));
  vector<int> ans;
  rep(i,n+1) if(b.at(i)) a.at(i) = false;
  rep(i,n+1) if(a.at(i)) ans.push_back(i);
  cout << ans.size() << endl;
  rep(i,ans.size()) {
    if(i)cout<<" ";
    cout<<ans.at(i);
  }
  cout << endl;

  return 0;
}
