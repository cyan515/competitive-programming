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
vector<pair<char, int>> run_length(const string& str) {
  int n = (int)str.size();
  vector<pair<char, int>> ret;
  for (int l = 0; l < n;) {
    int r = l + 1;
    for (; r < n && str[l] == str[r]; r++) {};
    ret.push_back({str[l], r - l});
    l = r;
  }
  return ret;
}

int main() {
  int n;cin>>n;string s;cin>>s;
  if(s.size()%2==0) {
    cout << No << endl;
    return 0;
  }
  if(s=="/") {
    cout << Yes << endl;
    return 0;
  }
  auto t = run_length(s);
  bool ok = true;
  ok &= t.size()==3 &&  t.at(0).first == '1' && t.at(2).first == '2' && t.at(0).second == t.at(2).second;
  if(ok) cout << Yes << endl;
  else cout << No << endl;

  return 0;
}
