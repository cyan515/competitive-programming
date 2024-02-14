#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  string s;cin>>s;
  queue<char> q;
  rep(i,s.size()) {
    if(s.at(s.size()-1-i)=='.') break;
    q.push(s.at(s.size()-1-i));
  }
  string ans = "";
  while(q.size()) {
    ans += q.front();q.pop();
  }
  reverse(all(ans));
  cout << ans << endl;

  exit(0);
}
