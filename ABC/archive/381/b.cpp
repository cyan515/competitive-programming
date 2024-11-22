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
  string s;cin>>s;
  int n = s.size();
  if(n%2==1) {
    cout << No << endl;
    return 0;
  }
  map<char,int> cnt;
  rep(i,n) cnt[s.at(i)]++;
  rep(i,26) {
    int v = cnt['a'+i];
    if(v!=0&&v!=2) {
      cout << No << endl;
      return 0;
    }
  }
  bool ok = true;
  for(int i=0;i<n;i+=2) {
    ok &= s.at(i)==s.at(i+1);
  }
  if(ok) cout << Yes << endl;
  else  cout << No << endl;

  return 0;
}
