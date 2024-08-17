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
  int a,b,c;cin>>a>>b>>c;
  if(c<b) c += 24;
  if(b <= a && a < c) cout << No << endl;
  else if(b <= a+24 && a+24 < c) cout << No << endl;
  else cout << Yes << endl;

  return 0;
}
