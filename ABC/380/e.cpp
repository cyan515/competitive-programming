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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n;cin>>n;
  dsu uf(n);
  vector<int> col(n);
  vector<int> cnt(n,1);
  vector<int> left(n),right(n);
  rep(i,n) left.at(i) = i,right.at(i) = i;
  rep(i,n) col.at(i) = i;
  int Q;cin>>Q;
  while(Q--) {
    int t;cin>>t;
    if(t==1) {
      int x,c;cin>>x>>c;x--;c--;
      int l = left.at(uf.leader(x));
      int r = right.at(uf.leader(x));
      int nl = l;
      int nr = r;
      cnt.at(c) += r-l+1;
      cnt.at(col.at(uf.leader(x))) -= r-l+1;
      l--;
      r++;
      if(l>=0) {
        if(col.at(uf.leader(l))==c) {
          nl = left.at(uf.leader(l));
          uf.merge(l,l+1);
        }
      }
      if(r<n) {
        if(col.at(uf.leader(r))==c) {
          nr = right.at(uf.leader(r));
          uf.merge(r,r-1);
        }
      }
      left.at(uf.leader(x)) = nl;
      right.at(uf.leader(x)) = nr;
      col.at(uf.leader(x)) = c;
    } else {
      int c;cin>>c;c--;
      cout << cnt.at(c) << endl;
    }
  }

  return 0;
}
