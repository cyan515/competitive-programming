#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
const string Yes = "Yes";
const string No = "No";
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

void f(vector<int>& data) {
  sort(data.begin(),data.end());
  data.erase(unique(data.begin(),data.end()),data.end());
}
  
int main() {
  int n;cin>>n;
  vector<int> a(n);cin>>a;
  f(a);
  cout << a.size() << endl;
  rep(i,a.size()) {
    if(i) cout << " ";
    cout << a.at(i);
  }
  cout << endl;

  return 0;
}
