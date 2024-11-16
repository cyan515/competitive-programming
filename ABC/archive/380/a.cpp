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
  string s;cin>>s;
  map<char,int> mp;
  rep(i,6) mp[s.at(i)]++;
  bool ok = true;
  ok &= mp['1']==1;
  ok &= mp['2']==2;
  ok &= mp['3']==3;
  if(ok) cout << Yes << endl;
  else cout << No << endl;

  return 0;
}
