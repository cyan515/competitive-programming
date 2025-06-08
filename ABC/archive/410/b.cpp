#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
const string Yes = "Yes";
const string No = "No";
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  int n;cin>>n;
  int Q;cin>>Q;
  vector<int> a(n,0);
  while(Q--) {
    int x;cin>>x;x--;
    if(x==-1) {
      int mi = INF;
      int idx;
      rep(i,n) {
        if(mi>a.at(i)) {
          idx = i;
          mi = a.at(i);
        }
      }
      a.at(idx)++;
      cout << idx + 1 << endl;
    } else {
      a.at(x)++;
      cout << x+1;
    }
    if(Q) cout << " ";
  }
  cout << endl;

  return 0;
}
