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
  int n,m;cin>>n>>m;
  string s,t;cin>>s>>t;
  set<char> ss,tt;
  for(auto c : s) ss.insert(c);
  for(auto c : t) tt.insert(c);
  int Q;cin>>Q;
  while(Q--) {
    string x;cin>>x;
    bool a = true;
    bool b = true;
    for(auto c : x) {
      a &= !!ss.count(c);
      b &= !!tt.count(c);
    }
    if(a^b) {
      if(a) cout << "Takahashi" << endl;
      else cout << "Aoki" << endl;
    } else {
      cout << "Unknown" << endl;
    }
  }

  return 0;
}
