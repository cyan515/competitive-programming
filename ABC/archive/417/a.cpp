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
  int n,a,b;cin>>n>>a>>b;
  string s;cin>>s;
  deque<char> q;
  rep(i,n) {
    q.push_back(s.at(i));
  }
  rep(i,a) q.pop_front();
  rep(i,b) q.pop_back();
  while(q.size()) {
    cout << q.front();
    q.pop_front();
  }
  cout << endl;

  return 0;
}
