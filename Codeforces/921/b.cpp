#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int T;
  // cin>>T;
  T=1000;
  while(T--) {
    int x,n;
    // cin>>x>>n;
    x = rand()%100000000;
    n = rand()%x;
    int m = x/n;
    int r = x%n;
    int k = 0;
    while((r+n*k)%(m-k)) k++;
    cout << m-k << endl;
  }

  exit(0);
}
