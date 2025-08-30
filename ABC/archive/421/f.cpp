#include <bits/stdc++.h>
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
  vector<int> plc(n+10,-1);
  vector<int> ops(n);
  vector<pair<int,int>> qs(n);
  {
    int HEAD = n+3;
    int TAIL = n+5;
    vector<ll> nx(n+10,-1);
    nx.at(0) = TAIL;
    vector<ll> bf(n+10,-1);
    bf.at(0) = HEAD;
    rep(i,n) {
      cin>>ops.at(i);
      if(ops.at(i)==1) {
        cin>>qs.at(i).first;
        qs.at(i).second = -1;
        int x = qs.at(i).first;
        int v = i+1;
        int nxx = nx.at(x);
        nx.at(x) = v;
        nx.at(v) = nxx;
        bf.at(v) = x;
        bf.at(nxx) = v;
      } else {
        cin>>qs.at(i).first>>qs.at(i).second;
      }
    }
    int cur = 0;
    int idx = 0;
    while(cur!=TAIL) {
      plc.at(cur) = idx++;
      cur = nx.at(cur);
    }
  }
  int HEAD = n+3;
  int TAIL = n+5;
  vector<ll> nx(n+10,-1);
  nx.at(0) = TAIL;
  vector<ll> bf(n+10,-1);
  bf.at(0) = HEAD;
  rep(i,n) {
    int op = ops.at(i);
    int v = i+1;
    if(op==1) {
      int x = qs.at(i).first;
      int nxx = nx.at(x);
      nx.at(x) = v;
      nx.at(v) = nxx;
      bf.at(v) = x;
      bf.at(nxx) = v;
    } else {
      auto [x,y] = qs.at(i);
      if(plc.at(x)>plc.at(y)) swap(x,y);
      ll sum = -x;
      int cur = x;
      while(cur!=y) {
        sum += cur;
        cur = nx.at(cur);
      }
      cout << sum << endl;
      nx.at(x) = y;
      bf.at(y) = x;
    }
  }

  return 0;
}
