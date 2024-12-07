#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
const string Yes = "Yes";
const string No = "No";
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int n;cin>>n;
  vector<int> t(n),v(n);
  rep(i,n) cin>>t.at(i)>>v.at(i);
  vector<int> d(t.back()+1,0);
  rep(i,n) d.at(t.at(i)) = v.at(i);
  int cur = 0;
  reps(i,1,t.back()+1) {
    cur--;
    cur = max(cur,0);
    cur += d.at(i);
  }
  cout << cur << endl;

  return 0;
}
