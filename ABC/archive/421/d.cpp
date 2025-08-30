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
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};

int main() {
  ll tx,ty,ax,ay;cin>>tx>>ty>>ax>>ay;
  ll n,m,l;cin>>n>>m>>l;
  vector<pair<char,ll>> tm(m),am(l);
  rep(i,m) cin>>tm.at(i).first>>tm.at(i).second;
  rep(i,l) cin>>am.at(i).first>>am.at(i).second;
  {
    vector<pair<char,ll>> tmm,amm;
    int ti = 0;
    int ai = 0;
    while(ti<m&&ai<l) {
      auto [td,tl] = tm.at(ti);
      auto [ad,al] = am.at(ai);
      if(tl==al) {
        tmm.push_back(tm.at(ti));
        amm.push_back(am.at(ai));
        ti++;
        ai++;
      } else if(tl<al) {
        tmm.push_back(tm.at(ti));
        amm.push_back(pair(ad,tl));
        am.at(ai).second -= tl;
        ti++;
      } else {
        tmm.push_back(pair(td,al));
        amm.push_back(am.at(ai));
        tm.at(ti).second -= al;
        ai++;
      }
    }
    swap(tm,tmm);
    swap(am,amm);
  }
  n = tm.size();
  ll ans = 0;
  auto f = [&](char d,ll len) -> pair<ll,ll> {
    if(d=='U') return pair(-len,0);
    else if(d=='D') return pair(len,0);
    else if(d=='L') return pair(0,-len);
    else return pair(0,len);
  };
  rep(i,n) {
    auto [td,tl] = tm.at(i);
    auto [ad,al] = am.at(i);
    auto dt = f(td,tl);
    auto da = f(ad,al);
    ll ntx = tx + dt.first;
    ll nty = ty + dt.second;
    ll nax = ax + da.first;
    ll nay = ay + da.second;
    if(set({td,ad})==set({'U','D'})) {
      if(nty==nay && abs(tx-ax)%2==0) {
        if(tx<ax&&nax<=ntx) ans++;
        if(ax<tx&&ntx<=nax) ans++;
      }
    }
    else if(set({td,ad})==set({'L','R'})) {
      if(ntx==nax && abs(ty-ay)%2==0) {
        if(ty<ay&&nay<=nty) ans++;
        if(ay<ty&&nty<=nay) ans++;
      }
    }
    // 同じ座標にいるときのことに注意する
    else if(td!=ad) {
      if(abs(tx-ax)==abs(ty-ay)) {
        bool invx = tx<ax&&nax<=ntx || ax<tx&&ntx<=nax;
        bool invy = ty<ay&&nay<=nty || ay<ty&&nty<=nay;
        if(invx&&invy) ans++;
      }
    } else {
      if(tx==ax&&ty==ay) ans += tl;
    }
    tx = ntx;
    ty = nty;
    ax = nax;
    ay = nay;
  }
  cout << ans << endl;

  return 0;
}
