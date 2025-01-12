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
  vector<int> a(4);cin>>a;
  sort(all(a));
  bool flg = false;
  flg |= a.at(0)==a.at(1)&&a.at(1)==a.at(2);
  flg |= a.at(1)==a.at(2)&&a.at(2)==a.at(3);
  flg |= a.at(0)==a.at(1)&&a.at(2)==a.at(3);
  flg &= a.front()!=a.back();
  if(flg) cout << Yes << endl;
  else cout << No << endl;

  return 0;
}
