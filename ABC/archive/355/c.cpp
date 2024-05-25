#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
void YN(bool b){cout<<(b?"Yes":"No")<<endl;}

int main() {
  ll n,t;cin>>n>>t;
  vector<ll> a(t);cin>>a;
  vector<int> icnt(n,0),jcnt(n,0),ccnt(2,0);
  rep(i,t) a.at(i)--;
  rep(i,t) {
    icnt.at(a.at(i)/n)++;
    jcnt.at(a.at(i)%n)++;
    if(a.at(i)%(n+1)==0) ccnt.at(0)++;
    if(a.at(i)!=0&&a.at(i)%(n-1)==0&&a.at(i)<=(n-1)*n) ccnt.at(1)++;
    if(icnt.at(a.at(i)/n)==n||jcnt.at(a.at(i)%n)==n||ccnt.at(0)==n||ccnt.at(1)==n) {
      cout << i+1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;

  return 0;
}
