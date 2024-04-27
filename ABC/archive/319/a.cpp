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
#define all(a) (a).begin(), (a).end()

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  map<string,int> mp;
  mp["tourist"] = 3858;
  mp["ksun48"] = 3679;
  mp["Benq"] = 3658;
  mp["Um_nik"] = 3648;
  mp["apiad"] = 3638;
  mp["Stonefeang"] = 3630;
  mp["ecnerwala"] = 3613;
  mp["mnbvmar"] = 3555;
  mp["newbiedmy"] = 3516;
  mp["semiexp"] = 3481;
  string s;cin>>s;
  cout << mp.at(s) << endl;

  exit(0);
}
