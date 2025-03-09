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
  vector<char> vec;
  int n = s.size();
  rep(i,n) {
    vec.push_back(s.at(i));
    int cnt = 0;
    while(vec.size()>=2&&vec.at(vec.size()-2)=='W'&&vec.at(vec.size()-1)=='A') {
      vec.pop_back();vec.pop_back();
      vec.push_back('A');
      cnt++;
    }
    while(cnt--) vec.push_back('C');
  }
  rep(i,n) cout << vec.at(i);
  cout << endl;

  return 0;
}
