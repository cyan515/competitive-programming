#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using rpqi = priority_queue<int, vector<int>, greater<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

ll mex(int a, int b, int c) {
  ll ret = 0;
  if(a==0||b==0||c==0) ret = 1;
  if(ret==1&&(a==1||b==1||c==1)) ret = 2;
  if(ret==2&&(a==2||b==2||c==2)) ret = 3;
  return ret;
}

int main() {
  int n;cin>>n;
  vector<ll> a(n);
  rep(i,n) cin>>a.at(i);
  string s;cin>>s;
  ll sum = 0;
  vector m(n,vector<ll>(3));
  vector x(n,vector<ll>(3));
  rep(i,n) if(s.at(i)=='M') m.at(i).at(a.at(i))++;
  reps(i,1,n) rep(j,3) m.at(i).at(j) += m.at(i-1).at(j);
  rep(i,n) if(s.at(n-1-i)=='X') x.at(n-1-i).at(a.at(n-1-i))++;
  reps(i,1,n) rep(j,3) x.at(n-1-i).at(j) += x.at(n-i).at(j);
  rep(i,n) {
    if(s.at(i)!='E') continue;
    rep(j,3) rep(k,3) {
      ll mcnt = m.at(i).at(j);
      ll xcnt = x.at(i).at(k);
      ll v = mex(j,k,a.at(i));
      sum += v*mcnt*xcnt;
    }
  }
  cout << sum << endl;

  exit(0);
}
