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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n;cin>>n;
  int mg;cin>>mg;
  vector g(n,set<int>());
  rep(i,mg) {
    int u,v;cin>>u>>v;u--;v--;
    g.at(u).insert(v);
    g.at(v).insert(u);
  }
  int mh;cin>>mh;
  vector h(n,set<int>());
  rep(i,mh) {
    int a,b;cin>>a>>b;a--;b--;
    h.at(a).insert(b);
    h.at(b).insert(a);
  }
  vector a(n-1,vector<ll>(n));
  rep(i,n-1) reps(j,i+1,n) {
    cin >> a.at(i).at(j);
  }
  ll ans = LINF;
  vector<int> p(n);
  rep(i,n) p.at(i) = i;
  do {
    vector<int> rp(n);
    rep(i,n) {
      rp.at(p.at(i)) = i;
    }
    ll cnt = 0;
    rep(i,n) {
      auto x = g.at(i);
      auto y = h.at(p.at(i));
      for(auto& ele : x) {
        if(y.count(p.at(ele))) y.erase(p.at(ele));
        else y.insert(p.at(ele));
      }
      for(auto& ele : y) {
        // cnt += a.at(min(rp.at(ele),(int)i)).at(max(rp.at(ele),(int)i));
        cnt += a.at(min(ele,p.at(i))).at(max(ele,p.at(i)));
      }
    }
    ans = min(ans,cnt/2);
  } while(next_permutation(all(p)));
  cout << ans << endl;

  return 0;
}
