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
  set<int> st;
  int ans = 0;
  for(int i=0;i<n;i++) {
    int a;cin>>a;
    if(st.find(a) != st.end()) {
      st.erase(a);
      ans++;
    } else {
      st.insert(a);
    }
  }

  cout << ans << endl;


  exit(0);
}
