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
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  cout << fixed << setprecision(20);
  int T;cin>>T;
  while(T--) {
    long double sx1,sy1,gx1,gy1,sx2,sy2,gx2,gy2;
    cin>>sx1>>sy1>>gx1>>gy1>>sx2>>sy2>>gx2>>gy2;
    long double len1 = hypot(sx1-gx1,sy1-gy1);
    long double len2 = hypot(sx2-gx2,sy2-gy2);
    if(len1>len2) {
      swap(sx1,sx2);
      swap(sy1,sy2);
      swap(gx1,gx2);
      swap(gy1,gy2);
      swap(len1,len2);
    }
    long double dx1 = -(sx1-gx1)/len1;
    long double dy1 = -(sy1-gy1)/len1;
    long double dx2 = -(sx2-gx2)/len2;
    long double dy2 = -(sy2-gy2)/len2;
    long double t_lim = min(len1,len2);
    long double a = (dx1-dx2)*(dx1-dx2)+(dy1-dy2)*(dy1-dy2);
    long double b = 2*(dx1-dx2)*(sx1-sx2)+2*(dy1-dy2)*(sy1-sy2);
    long double c = (sx1-sx2)*(sx1-sx2)+(sy1-sy2)*(sy1-sy2);
    if(abs(a)<1e-9) {
      long double ans = LINF;
      chmin(ans,hypot(sx1-sx2,sy1-sy2));
      chmin(ans,hypot(gx1-gx2,gy1-gy2));
      {
        a = dx2*dx2+dy2*dy2;
        b = 2*dx2*(sx2-gx1) + 2*dy2*(sy2-gy1);
        c = (sx2-gx1)*(sx2-gx1)+(sy2-gy1)*(sy2-gy1);
        long double piv = -b/2.0/a;
        long double ans2;
        if(piv<t_lim) {
          ans2 = a*t_lim*t_lim+b*t_lim+c;
        } else if(piv<=len2) {
          ans2 = (4.0*a*c-b*b)/4.0/a;
        } else {
          ans2 = a*len2*len2+b*len2+c;
        }
        ans2 = abs(ans2);
        ans2 = sqrt(ans2);
        chmin(ans,ans2);
      }
      cout << ans << endl;
      continue;
    }
    long double piv = -b/2.0/a;
    long double ans;
    if(piv<0.0) {
      ans = c;
    } else if(piv<=t_lim) {
      ans = (4.0*a*c-b*b)/4.0/a;
    } else {
      ans = a*t_lim*t_lim+b*t_lim+c;
    }
    ans = abs(ans);
    ans = sqrt(ans);
    chmin(ans,hypot(sx1-sx2,sy1-sy2));
    chmin(ans,hypot(gx1-gx2,gy1-gy2));
    chmin(ans,hypot(sx1+t_lim*dx1-sx2-t_lim*dx2,sy1+t_lim*dy1-sy2-t_lim*dy2));
    {
      a = dx2*dx2+dy2*dy2;
      b = 2*dx2*(sx2-gx1) + 2*dy2*(sy2-gy1);
      c = (sx2-gx1)*(sx2-gx1)+(sy2-gy1)*(sy2-gy1);
      piv = -b/2.0/a;
      long double ans2;
      if(piv<t_lim) {
        ans2 = a*t_lim*t_lim+b*t_lim+c;
      } else if(piv<=len2) {
        ans2 = (4.0*a*c-b*b)/4.0/a;
      } else {
        ans2 = a*len2*len2+b*len2+c;
      }
      ans2 = abs(ans2);
      ans2 = sqrt(ans2);
      chmin(ans,ans2);
    }
    cout << ans << endl;
  }

  return 0;
}
