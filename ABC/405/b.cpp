#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
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
  int m;cin>>m;
  vector<int> a(n);cin>>a;
  rep(i,n) a.at(i)--;
  rep(i,n) {
    vector<bool> ex(m,false);
    for(auto ele : a) {
      ex.at(ele) = true;
    }
    bool ok = false;
    for(auto ele : ex) ok |= !ele;
    if(ok) {
      cout << i << endl;
      return 0;
    }
    a.pop_back();
  }
  cout << n << endl;

  return 0;
}
