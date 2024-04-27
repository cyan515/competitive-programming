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
  int zero = 1;
  int one = n;
  while(one-zero>1) {
    int mid = (zero+one)/2;
    cout << "? " << mid << endl;
    int a;cin>>a;
    if(a==0) zero = mid;
    else one = mid;
  }
  cout << "! " << zero << endl;

  exit(0);
}
