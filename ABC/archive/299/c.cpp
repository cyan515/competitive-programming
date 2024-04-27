#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 1000000007;

int cnt(string s, int n) {
  bool flg = false;
  int ret = -INF;
  int counting = 0;
  for(int i=0;i<n;i++) {
    if(s.at(i)=='-') flg =true;
    if(!flg) continue;
    if(s.at(i)=='-') {
      ret = max(ret,counting);
      counting = 0;
    } else {
      counting++;
    }
  }
  ret = max(ret,counting);
  return ret;
}

int main() {
  int n;cin>>n;
  string s;cin>>s;
  int ans = -INF;
  ans = max(ans,cnt(s,n));
  reverse(s.begin(),s.end());
  ans = max(ans,cnt(s,n));

  if(ans==0) ans = -1;
  cout << ans << endl;

  exit(0);
}
