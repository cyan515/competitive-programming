#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
#include <atcoder/segtree>
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

using S = int;
S op(S a,S b) {
  return min(a,b);
}
S e() {
  return INF;
}

int main() {
  int Q;cin>>Q;
  int cur = 0;
  atcoder::fenwick_tree<int> ft(Q+10);
  atcoder::segtree<S,op,e> seg(Q+10);
  while(Q--) {
    int op;cin>>op;
    if(op==1) {
      char c;cin>>c;
      if(c=='(') ft.add(cur,-ft.sum(cur,cur+1)+1);
      else ft.add(cur,-ft.sum(cur,cur+1)-1);
      cur++;
      seg.set(cur,ft.sum(0,cur));
    } else {
      ft.add(cur,-ft.sum(cur,cur+1));
      cur--;
      seg.set(cur,ft.sum(0,cur));
    }
    if(ft.sum(0,cur)==0 
    && seg.prod(0,cur)>=0
  ) cout << Yes << endl;
    else cout << No << endl;
  }

  return 0;
}
