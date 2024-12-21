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
  vector<int> v(3);cin>>v;
  if(v.at(0)==v.at(1)&&v.at(1)==v.at(2)) {
    cout << Yes << endl;
    return 0;
  }
  rep(bit,1<<3) {
    int x = 0;
    int y = 0;
    rep(i,3) {
      if((bit&(1<<i))>0) x += v.at(i);
      else y += v.at(i);
    }
    if(x==y) {
      cout << Yes << endl;
      return 0;
    }
  }
  cout << No << endl;

  return 0;
}
