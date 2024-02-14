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
  int s = to_string(n).length();
  if(s<=3) cout << n << endl;
  else if(s<=4) cout << n/10 << "0" << endl;
  else if(s<=5) cout << n/100 << "00" << endl;
  else if(s<=6) cout << n/1000 << "000" << endl;
  else if(s<=7) cout << n/10000 << "0000" << endl;
  else if(s<=8) cout << n/100000 << "00000" << endl;
  else if(s<=9) cout << n/1000000 << "000000" << endl;


  exit(0);
}
