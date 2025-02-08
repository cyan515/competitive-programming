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
  int n = 3;
  vector<int> a(n);cin>>a;
  sort(all(a));
  do {
    int x = a.at(0);
    int y = a.at(1);
    int z = a.at(2);
    if(x*y==z) {
      cout << Yes << endl;
      return 0;
    }
  } while(next_permutation(all(a)));
  cout << No << endl;

  return 0;
}
