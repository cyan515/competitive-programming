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
  ll x,y,z;cin>>x>>y>>z;
  rep(i,10000000) {
    if(x==y*z) {
      cout << Yes << endl;
      return 0;
    }
    x++;y++;
  }
  cout << No << endl;

  return 0;
}
