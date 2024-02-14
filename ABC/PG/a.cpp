#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using ll = long long;
const int INF = 1001001001;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cout << fixed << setprecision(20);
  long double a,b,c,d;cin>>a>>b>>c>>d;
  auto f = [&](long double x) -> long double {
    return a*x*x*x+b*x*x+c*x+d;
  };
  long double l,r;cin>>l>>r;
  int flg = f(l)>0?-1:1;
  if(f(l)==0) {
    cout << l << endl;
    return 0;
  } else if(f(r)==0) {
    cout << r << endl;
    return 0;
  }
  rep(_,100000) {
    long double mid = (l+r)/2;
    if(f(mid)*flg<0) l=mid;
    else r=mid;
  }
  cout << (l+r)/2 << endl;

  exit(0);
}
