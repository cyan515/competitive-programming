#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int n;cin>>n;
  vector<int> a(n);cin>>a;
  map<int,int> nxt;
  nxt[0] = a.at(0);
  nxt[a.back()] = -1;
  map<int,int> bef;
  bef[a.at(0)] = 0;
  bef[-1] = a.back();
  rep(i,n-1) {
    nxt[a.at(i)] = a.at(i+1);
    bef[a.at(i+1)] = a.at(i);
  }
  int Q;cin>>Q;
  while(Q--) {
    int t;cin>>t;
    if(t==1) {
      int x,y;cin>>x>>y;
      int nx = nxt.at(x);
      bef.at(nx) = y;
      nxt.at(x) = y;
      bef[y] = x;
      nxt[y] = nx;
    } else {
      int x;cin>>x;
      int be = bef.at(x);
      int nx = nxt.at(x);
      bef[nx] = be;
      nxt[be] = nx;
      bef.erase(bef.find(x));
      nxt.erase(nxt.find(x));
    }
  }
  int p = 0;
  vector<int> ans;
  while(nxt.find(p)!=nxt.end()) {
    p = nxt[p];
    if(p==-1) break;
    ans.push_back(p);
  }
  rep(i,ans.size()) {
    cout << ans.at(i);
    if(i==ans.size()-1) cout << endl;
    else cout << " ";
  }

  return 0;
}
