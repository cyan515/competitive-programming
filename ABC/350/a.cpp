#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  string s;cin>>s;
  reps(i,1,350) {
    if(i==316) continue;
    string t = "ABC";
    string u = to_string(i);
    while(u.size()<3) u = "0"+u;
    t += u;
    if(s==t) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;

  return 0;
}
