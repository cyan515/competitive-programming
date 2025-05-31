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
  int s;cin>>s;
  vector<int> a(n);cin>>a;
  int cur = 0;
  bool ok = true;
  rep(i,n) {
    ok &= a.at(i)-cur<=s;
    cur = a.at(i);
  }
  cout << (ok?Yes:No) << endl;

  return 0;
}
