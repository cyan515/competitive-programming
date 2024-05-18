#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
void YN(bool b){cout<<(b?"Yes":"No")<<endl;}

int main() {
  ll add = 1;
  int ans = 0;
  ll h;cin>>h;
  ll x = 0;
  while(x<=h) {
    x+=add;
    add *= 2;
    ans++;
  }
  cout << ans << endl;

  return 0;
}
