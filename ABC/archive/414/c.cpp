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

// 10進数表現の整数を受け取って BASE 進数に変換して返す
string convert_base(const long long n, const int base) {
  string ret = "";
  long long cur = n;
  if (cur == 0LL) {
    ret = "0";
  } else {
    while (cur > 0) {
      char c = '0' + (cur % base);
      ret += c;
      cur /= base;
    }
    reverse(ret.begin(), ret.end());
  }
  return ret;
}

bool is_pal(string& s) {
  int n = s.size();
  bool ret = true;
  rep(i,n/2) {
    ret &= s.at(i)==s.at(s.size()-1-i);
  }
  return ret;
}

int main() {
  int a;cin>>a;
  ll n;cin>>n;
  ll ans = 0;
  if(n<=1000000) {
    reps(i,1,n+1) {
      string x = to_string(i);
      if(is_pal(x)) {
        string y = convert_base(i,a);
        if(is_pal(y)) ans += i;
      }
    }
  } else {
    reps(i,1,1000001) {
      string x = to_string(i);
      string y = x;
      reverse(all(y));
      string z = x+y;
      ll zz = stoll(z);
      if(zz<=n && is_pal(z)) {
        string s = convert_base(zz,a);
        if(is_pal(s)) ans += zz;
      }
      x.pop_back();
      z = x+y;
      zz = stoll(z);
      if(zz<=n && is_pal(z)) {
        string s = convert_base(zz,a);
        if(is_pal(s)) ans += zz;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
