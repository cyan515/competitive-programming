#include <bits/stdc++.h>
// #include <atcoder/all>
// using namespace atcoder;
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
  int n,m,q;cin>>n>>m>>q;
  vector<int> a(m),b(m);
  vector<ll> c(m);
  rep(i,m) cin>>a.at(i)>>b.at(i)>>c.at(i);
  rep(i,m) a.at(i)--,b.at(i)--;
  vector<int> t(q),x(q),y(q);
  rep(i,q) {
    int tt;cin>>tt;
    if(tt==1) {
      int xx;cin>>xx;xx--;
      t.at(i) = tt;
      x.at(i) = xx;
      y.at(i) = -1;
    } else {
      int xx,yy;cin>>xx>>yy;xx--;yy--;
      t.at(i) = tt;
      x.at(i) = xx;
      y.at(i) = yy;
    }
  }
  vector dists(n,vector<ll>(n,LINF));
  {
    set<int> banned;
    rep(i,q) {
      if(t.at(i)==1) banned.insert(x.at(i));
    }
    rep(i,n) dists.at(i).at(i) = 0;
    rep(i,m) {
      if(banned.count(i)) continue;
      dists.at(a.at(i)).at(b.at(i)) = c.at(i);
      dists.at(b.at(i)).at(a.at(i)) = c.at(i);
    }
    rep(k,n) rep(i,n) rep(j,n) {
      chmin(dists.at(i).at(j),dists.at(i).at(k)+dists.at(k).at(j));
    }
  }
  stack<ll> ans;
  rep(ii,q) {
    int i = q-1-ii;
    if(t.at(i)==1) {
      if(dists.at(a.at(x.at(i))).at(b.at(x.at(i)))>c.at(x.at(i)) || dists.at(b.at(x.at(i))).at(a.at(x.at(i)))>c.at(x.at(i))) {
        chmin(dists.at(a.at(x.at(i))).at(b.at(x.at(i))),c.at(x.at(i)));
        chmin(dists.at(b.at(x.at(i))).at(a.at(x.at(i))),c.at(x.at(i)));
        rep(from,n) rep(to,n) {
          chmin(dists.at(from).at(to),dists.at(from).at(a.at(x.at(i)))+c.at(x.at(i))+dists.at(b.at(x.at(i))).at(to));
          chmin(dists.at(from).at(to),dists.at(from).at(b.at(x.at(i)))+c.at(x.at(i))+dists.at(a.at(x.at(i))).at(to));
        }
      }
    } else {
      ll d = dists.at(x.at(i)).at(y.at(i));
      if(d==LINF) d=-1;
      ans.push(d);
    }
  }
  while(ans.size()) {
    cout << ans.top() << endl;
    ans.pop();
  }

  return 0;
}
