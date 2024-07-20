#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
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

int main() {
  ll n;cin>>n;
  vector<ll> factors;
  {
    map<ll,int> mp;
    ll m = n;
    for(ll i=2;i*i<=m;i++) {
      while(m%i==0) {
        m /= i;
        mp[i]++;
      }
    }
    if(m>1) mp[m]++;
    for(auto& [k,v] : mp) {
      rep(i,v) factors.push_back(k);
    }
  }
  int cnt = factors.size();
  rep(div,cnt) {
    vector<ll> x(div,1);
    rep(i,div) x.at(i) *= factors.at(i);
    auto f = [&](auto f,int idx) -> string {
      if(idx==cnt) {
        map<ll,int> mp;
        string ret = "";
        rep(i,div) mp[x.at(i)]++;
        deque<ll> q;
        rep(i,div) {
          string s = to_string(x.at(i));
          string t = s;
          reverse(all(s));
          if(s==t) {
            mp[x.at(i)]--;
            if(mp[x.at(i)]==0) {
              mp.erase(mp.find(x.at(i)));
            }
            q.push_back(x.at(i));
          } else {
            ll y = stoll(s);
            auto it = mp.find(y);
            if(it==mp.end()) {
              return "";
            } else {
              mp[y]--;
              if(mp[y]==0) mp.erase(it);
            }
            q.push_front(x.at(i));
            q.push_back(y);
          }
        }
        if(mp.empty()) {
          while(q.size()) {
            ret += to_string(q.front());
            q.pop_front();
            if(q.size()) ret += "*";
          }
          return ret;
        } else {
          return "";
        }
      }
      rep(i,div) {
        x.at(i) *= factors.at(idx);
        string ret = f(f,idx+1);
        if(ret!="") return ret;
        x.at(i) /= factors.at(idx);
      }
      return "";
    };
    string ans = f(f,div);
    if(ans!="") {
      cout << ans << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  
  return 0;
}
