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
  int r,g,b;cin>>r>>g>>b;
  string s;cin>>s;
  char c = s.front();
  if(c=='R') {
    cout << min(g,b) << endl;
  } else if(c=='G') {
    cout << min(r,b);
  } else {
    cout << min(r,g) << endl;
  }

  return 0;
}
