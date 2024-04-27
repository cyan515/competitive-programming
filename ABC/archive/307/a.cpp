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

int main() {
  int n;cin>>n;
  vector<int> a(n*7);
  rep(i,n*7) {
    cin>>a.at(i);
    if(i%7!=0) a.at(i) += a.at(i-1);
  }
  for(int i=6;i<n*7;i+=7) cout << a.at(i) << " ";
  cout << endl;

  exit(0);
}
