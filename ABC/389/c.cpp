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
  int Q;cin>>Q;
  int offset = 0;
  int back = 0;
  fenwick_tree<ll> row(Q+10);
  while(Q--) {
    int t;cin>>t;
    if(t==1) {
      int l;cin>>l;
      row.add(back++,l);
    } else if(t==2) {
      offset++;
    } else {
      int k;cin>>k;k--;
      cout << row.sum(offset,offset+k) << endl;
    }
  }

  return 0;
}