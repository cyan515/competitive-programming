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
  int n,l,r;cin>>n>>l>>r;
  vector<int> a(n);
  rep(i,n) a.at(i) = i+1;
  l--;
  reverse(a.begin()+l,a.begin()+r);
  rep(i,n) {
    if(i)cout<<" ";
    cout << a.at(i);
  }
  cout << endl;

  return 0;
}
