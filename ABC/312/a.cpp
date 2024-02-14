#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using vvi = vector<vector<int>>;
using rpqi = priority_queue<int, vector<int>, greater<int>>;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)

int main() {
  string s;cin>>s;
  if(s=="ACE"
    || s=="BDF"
    || s=="CEG"
    || s=="DFA"
    || s=="EGB"
    || s=="FAC"
    || s=="GBD") cout << "Yes" << endl;
    else cout << "No" << endl;

  exit(0);
}
