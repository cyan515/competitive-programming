#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  int n;cin>>n;
  string s;cin>>s;
  bool ans = false;
  rep(i,n-1) {
    if(s.at(i)=='a'&&s.at(i+1)=='b') ans = true;
    if(s.at(i)=='b'&&s.at(i+1)=='a') ans = true;
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;

  exit(0);
}
