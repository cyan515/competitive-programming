#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
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
using S = int;
S op(S a,S b) {
  return max(a,b);
}
S e() {
  return -1;
}

int main() {
  int n,d,r;cin>>n>>d>>r;
  vector<int> h(n);cin>>h;
  vector<int> ord(n);
  rep(i,n) ord.at(i) = i;
  sort(all(ord), [&](int ii,int jj) -> bool {
    return h.at(ii)>h.at(jj);
  });
  segtree<S,op,e> seg(n);
  queue<pair<int,int>> q;
  for(auto i : ord) {
    while(q.size()&&h.at(i)+d<=h.at(q.front().first)) {
      auto [idx,x] = q.front();q.pop();
      seg.set(idx,x);
    }
    int l = 0;
    chmax(l,i-r);
    int rr = n;
    chmin(rr,i+r+1);
    int ma = seg.prod(l,rr)+1;
    q.push(pair(i,ma));
  }
  while(q.size()) {
    auto [idx,x] = q.front();q.pop();
    seg.set(idx,x);
  }
  cout << seg.all_prod() << endl;

  return 0;
}
