#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

int main() {
  int x,y,z;cin>>x>>y>>z;
  auto f = [](int a,int b,int c,int s,int t,int u) -> int {
    if(a>s || b>t || c>u) return 0;
    return (s-a)*(t-b)*(u-c);
  };
  int v = 7*7*7*3;
  int n = 10;
  reps(bx,-10,n) reps(by,-10,n) reps(bz,-10,n) reps(cx,-10,n) reps(cy,-10,n) reps(cz,-10,n)  {
    ll bxx = bx+7;
    ll byy = by+7;
    ll bzz = bz+7;
    ll cxx = cx+7;
    ll cyy = cy+7;
    ll czz = cz+7;
    int v3 = f(max({bx,cx,0LL}),max({by,cy,0LL}),max({bz,cz,0LL}),min({bxx,cxx,7LL}),min({byy,cyy,7LL}),min({bzz,czz,7LL}));
    int v2 = 0;
    v2 += f(bx,by,bz,7,7,7) + f(cx,cy,cz,7,7,7) + f(max(bx,cx),max(by,cy),max(bz,cz),min(bxx,cxx),min(byy,cyy),min(bzz,czz)) - v3*3;
    int v1 = v - v3*3 - v2*2;
    if(v1==x && v2==y && v3==z) {
      cout << "Yes" << endl;
      cout << 0 << " " << bx << " " << cx << " " << 0 << " " << by << " " << cy << " " << 0 << " " << bz << " " << cz << endl;
      return 0;
    }
  }
  cout << "No" << endl;

  return 0;
}
