#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using rpqi = priority_queue<int, vector<int>, greater<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

int main() {
  int n;cin>>n;
  int m;cin>>m;
  vector<int> a(n);
  vector<int> b(m);
  rep(i,n) cin>>a.at(i);
  rep(i,m) cin>>b.at(i);
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  int ng = 0;
  int ok = INF;
  while(abs(ok-ng)>1) {
    int mid = (ok+ng)/2;
    bool flg = false;
    int se = upper_bound(a.begin(),a.end(),mid)-a.begin();
    int bu = b.end()-lower_bound(b.begin(),b.end(),mid);
    if(se>=bu) flg = true;
    if(flg) ok=mid;
    else ng=mid;
  }
  cout << ok << endl;

  exit(0);
}
