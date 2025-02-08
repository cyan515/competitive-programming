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
  int n = s.size();
  rep(i,n) {
    if(s.at(i)=='N') s.at(i) = 'S';
    else if(s.at(i)=='S') s.at(i) = 'N';
    else if(s.at(i)=='E') s.at(i) = 'W';
    else if(s.at(i)=='W') s.at(i) = 'E';
  }
  cout << s << endl;

  return 0;
}
