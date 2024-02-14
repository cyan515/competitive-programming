#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 998244353;

int main() {
  int n;cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin>>a.at(i);
  int q;cin>>q;
  vector<int> sl(n,0);
  for(int i=1;i<n;i++) {
    if(i%2==0) {
      sl.at(i) = a.at(i)-a.at(i-1);
    }
    sl.at(i) += sl.at(i-1);
  }
  while(q--) {
    int l,r;cin>>l>>r;
    int hosei = 0;
    int li = lower_bound(a.begin(),a.end(),l)-a.begin()-1;
    li = max(li,0);
    if(li%2==1) hosei += l-a.at(li);
    int ri = lower_bound(a.begin(),a.end(),r)-a.begin();
    if(ri%2==0) hosei += a.at(ri)-r;
    cout << sl.at(ri) - sl.at(li) - hosei << endl;
  }

  exit(0);
}
