#include <bits/stdc++.h>
#include <atcoder/dsu>
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
  int Q;cin>>Q;
  ll x,y;cin>>x>>y;
  // 左下 右上 長方形 閉区間
  vector<tuple<ll,ll,ll,ll>> s;
  s.push_back(tuple(0,0,x-1,y-1));
  while(Q--) {
    char c;ll a,b;cin>>c>>a>>b;
    vector<tuple<ll,ll,ll,ll>> nx;
    int n = s.size();
    if(c=='X') {
      rep(i,n) {
        auto [x0,y0,x1,y1] = s.at(i);
        if(x1<a) nx.push_back(tuple(x0,y0-b,x1,y1-b));
        else if(a<=x0) nx.push_back(tuple(x0,y0+b,x1,y1+b));
        else {
          nx.push_back(tuple(x0,y0-b,a-1,y1-b));
          nx.push_back(tuple(a,y0+b,x1,y1+b));
        }
      }
    } else {
      rep(i,n) {
        auto [x0,y0,x1,y1] = s.at(i);
        if(y1<a) nx.push_back(tuple(x0-b,y0,x1-b,y1));
        else if(a<=y0) nx.push_back(tuple(x0+b,y0,x1+b,y1));
        else {
          nx.push_back(tuple(x0-b,y0,x1-b,a-1));
          nx.push_back(tuple(x0+b,a,x1+b,y1));
        }
      }
    }
    swap(s,nx);
  }
  sort(all(s));
  int n = s.size();
  atcoder::dsu uf(n);
  vector<ll> ans(n,0);
  rep(i,n) {
    auto [x0,y0,x1,y1] = s.at(i);
    ans.at(i) = (x1-x0+1) * (y1-y0+1);
  }
  rep(i,n) {
    auto [x0,y0,x1,y1] = s.at(i);
    reps(j,i+1,n) {
      auto [x2,y2,x3,y3] = s.at(j);
      if(x1+1 < x2) continue;
      if(x1+1==x2) {
        if(!(y1<y2 || y3<y0)) {
          if(!uf.same(i,j)) {
            int il = uf.leader(i);
            int jl = uf.leader(j);
            ll nsum = ans.at(il) + ans.at(jl);
            uf.merge(i,j);
            il = uf.leader(i);
            ans.at(il) = nsum;
          }
        }
      } else {
        if(y0-1==y3 || y1+1==y2) {
          if(!uf.same(i,j)) {
            int il = uf.leader(i);
            int jl = uf.leader(j);
            ll nsum = ans.at(il) + ans.at(jl);
            uf.merge(i,j);
            il = uf.leader(i);
            ans.at(il) = nsum;
          }
        }
      }
    }
  }
  auto gs = uf.groups();
  cout << gs.size() << endl;
  vector<ll> anss;
  for(auto g : gs) {
    int l = uf.leader(g.front());
    anss.push_back(ans.at(l));
  }
  sort(all(anss));
  rep(i,anss.size()) {
    if(i)cout<<" ";
    cout<<anss.at(i);
  }
  cout << endl;

  return 0;
}
