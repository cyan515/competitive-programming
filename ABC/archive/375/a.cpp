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
  string s;cin>>s;
  int ans = 0;
  reps(i,1,n-1) {
    if(s.at(i)=='.'&&s.at(i-1)=='#'&&s.at(i+1)=='#') ans++;
  }
  cout << ans << endl;

  return 0;
}
