#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
const string Yes = "Yes";
const string No = "No";
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int a,b;cin>>a>>b;
  pair<int,int> p=pair(a,b);
  set<pair<int,int>>st={{1,7},{3,3},{5,5},{7,7},{9,9}};
  cout<<(st.count(p)?Yes:No)<<endl;

  return 0;
}
