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

int main() {
  ll n;cin>>n;
  vector<ll> t(n);cin>>t;
  vector<int> ord(n);
  rep(i,n) ord.at(i)=i;
  sort(all(ord),[&](int i,int j) -> bool {
    return t.at(i)<t.at(j);
  });
  rep(i,3) {
    if(i)cout<<" ";
    cout<<ord.at(i)+1;
  }
  cout << endl;

  return 0;
}
