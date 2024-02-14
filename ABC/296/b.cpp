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
  int x;cin>>x;

  vector<int> a(n);
  set<int> st;
  for(int i=0;i<n;i++) cin>>a.at(i);
  for(int i=0;i<n;i++) st.insert(a.at(i));

  bool f = false;
  for(int i=0;i<n;i++) {
    if(st.find(a.at(i)+x) != st.end()) f = true;
  }

  if(f) cout << "Yes";
  else cout << "No";
  cout << endl;

  exit(0);
}
