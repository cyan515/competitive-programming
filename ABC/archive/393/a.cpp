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
  string s,t;cin>>s>>t;
  char c = s.front();
  char d = t.front();
  if(c=='s'&&d=='s') cout << 1 << endl;
  else if(c=='s'&&d!='s') cout << 2 << endl;
  else if(c!='s'&&d=='s') cout << 3 << endl;
  else cout << 4 << endl;

  return 0;
}
