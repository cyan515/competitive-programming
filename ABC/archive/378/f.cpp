#include <bits/stdc++.h>
#include <atcoder/dsu>
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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n;cin>>n;
  vector g(n,vector<int>());
  vector<int> deg(n,0);
  vector<int> us(n-1),vs(n-1);
  rep(i,n-1) {
    int u,v;cin>>u>>v;u--;v--;
    us.at(i) = u;
    vs.at(i) = v;
    g.at(u).push_back(v);
    g.at(v).push_back(u);
    deg.at(u)++;
    deg.at(v)++;
  }
  vector<bool> two(n,false);
  rep(i,n) if(deg.at(i)==2) two.at(i)=true;
  dsu uf(n);
  rep(i,n-1) {
    if(deg.at(us.at(i))==3&&deg.at(vs.at(i))==3) uf.merge(us.at(i),vs.at(i));
  }
  ll ans = 0;
  for(auto vec : uf.groups()) {
    if(deg.at(vec.front())!=3) continue;
    ll cnt = 0;
    set<int> st;
    for(auto v : vec) {
      for(auto ele : g.at(v)) {
        if(deg.at(ele)==2) st.insert(ele);
      }
    }
    cnt = st.size();
    ans += cnt*(cnt-1)/2;
  }
  cout << ans << endl;

  return 0;
}
