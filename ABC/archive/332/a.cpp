#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  ll n,s,k;cin>>n>>s>>k;
  ll sum = 0;
  rep(_,n) {
    ll p,q;cin>>p>>q;
    sum += p*q;
  }
  if(sum<s) sum+=k;
  cout << sum << endl;

  exit(0);
}
