#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int n;cin>>n;
  int x,y,z;cin>>x>>y>>z;
  if(x>y) swap(x,y);
  if(x<z&&z<y) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
