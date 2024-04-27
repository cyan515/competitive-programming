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
  int a,b;cin>>a>>b;
  int x = a+b;
  for(int i=0;i<n;i++) {
    int c;cin>>c;
    if(x==c)  {
      cout << i+1 << endl;
      exit(0);
    }
  }

  exit(0);
}
