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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n;cin>>n;
  string s,t;cin>>s>>t;
  int abc = 26;
  vector<int> a(abc,-1);
  auto node = [&](char c) -> int {
    return c - 'a';
  };
  scc_graph scc(abc);
  rep(i,n) {
    if(a.at(node(s.at(i)))!=-1 && a.at(node(s.at(i)))!=node(t.at(i))) {
      cout << -1 << endl;
      return 0;
    }
    if(a.at(node(s.at(i)))==-1) {
      scc.add_edge(node(s.at(i)),node(t.at(i)));
    }
    a.at(node(s.at(i))) = node(t.at(i));
  }
  int ans = 0;
  bool iso = false;
  for(auto vec : scc.scc()) {
    iso |= vec.size()==1;
  }
  for(auto vec : scc.scc()) {
    if(vec.size()==1) continue;
    bool ok = false;
    for(auto ele : vec) {
      rep(i,abc) {
        if(ele==i) continue;
        if(a.at(i)==a.at(ele)) {
          a.at(ele) = i;
          ok = true;
          break;
        }
      }
    }
    if(ok) continue;
    int ele = vec.front();
    rep(i,abc) {
      if(a.at(i)==-1) {
        ans++;
        ok = true;
        break;
      }
    }
    if(!ok) {
      cout << -1 << endl;
      return 0;
    }
  }
  rep(i,abc) {
    if(a.at(i)!=-1&&a.at(i)!=i) ans++;
  }
  cout << ans << endl;

  return 0;
}
