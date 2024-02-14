#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 1000000007;

int main() {
  int n;cin>>n;
  string s;cin>>s;
  int a = 0;
  int t = 0;
  string ans = "";
  for(int i=0;i<n;i++) {
    if(s.at(i)=='A') a++;
    else t++;
  }
  if(a==t) {
    for(int i=0;i<n;i++) {
      if(s.at(i)=='A') a--;
      else t--;
      if(a==0) {
        ans = "A";
        break;
      } else if(t==0) {
        ans = "T";
        break;
      }
    }
  } else if(a>t) ans = "A";
  else ans = "T";

  cout << ans << endl;

  exit(0);
}
