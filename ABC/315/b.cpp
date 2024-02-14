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
#define all(a) (a).begin(), (a).end()

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int n;cin>>n;
  vector<int> d(n);
  rep(i,n) cin>>d.at(i);
  int sum = 0;
  rep(i,n) sum += d.at(i);
  sum++;
  sum /= 2;
  int mon = 0;
  int day = 1;
  rep(i,sum-1) {
    if(day<d.at(mon)) day++;
    else mon++,day=1;
  }
  cout << mon+1 << " " << day << endl;

  exit(0);
}
