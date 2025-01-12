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
  int k;cin>>k;
  string s,t;cin>>s>>t;
  int n = s.size();
  int m = t.size();
  int head = 0;
  int tail = 0;
  {
    int idx = 0;
    while(idx<n&&idx<m&&s.at(idx)==t.at(idx)) idx++;
    head = idx;
  }
  {
    int idx = 0;
    reverse(all(s));
    reverse(all(t));
    while(idx<n&&idx<m&&s.at(idx)==t.at(idx)) idx++;
    tail = idx;
    reverse(all(s));
    reverse(all(t));
  }
  if(n==m) {
    int cnt = 0;
    rep(i,n) {
      cnt += s.at(i)!=t.at(i);
    }
    if(cnt>1) cout << No << endl;
    else cout << Yes << endl;
  } else if(n-1==m) {
    if(head+tail+1>=n) cout << Yes << endl;
    else cout << No << endl;
  } else if(n==m-1) {
    if(head+tail>=n) cout << Yes << endl;
    else cout << No << endl;
  } else {
    cout << No << endl;
  }

  return 0;
}
