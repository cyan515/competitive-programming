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
  int n = 5;
  vector<int> a(n);cin>>a;
  vector<int> b = {1,2,3,4,5};
  rep(i,n-1) {
    swap(a.at(i),a.at(i+1));
    if(a==b) {
      cout << Yes << endl;
      return 0;
    }
    swap(a.at(i),a.at(i+1));
  }
  cout << No << endl;

  return 0;
}
