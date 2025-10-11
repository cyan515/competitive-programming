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
  string x,y;cin>>x>>y;
  char a = x.front();
  char b = y.front();
  int s,t;
  auto f = [&](char c) -> int {
    if(c=='O') return 0;
    else if(c=='S') return 1;
    else return 2;
  };
  s = f(a);
  t = f(b);
  cout<<(s>=t?Yes:No) << endl;

  return 0;
}
