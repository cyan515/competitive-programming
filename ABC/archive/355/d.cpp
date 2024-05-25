#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace atcoder;
using namespace std;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 3001001001001001001;
const int MOD = 998244353;
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define all(a) (a).begin(), (a).end()
template<typename T> bool chmin(T& a, T b){if(a > b){a = b; return true;} return false;}
template<typename T> bool chmax(T& a, T b){if(a < b){a = b; return true;} return false;}
template<typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}
void YN(bool b){cout<<(b?"Yes":"No")<<endl;}

int main() {
   ll n;cin>>n;
   vector<pair<ll, ll>> lr(n);
   rep(i,n) {
       cin >> lr.at(i).first >> lr.at(i).second;
   }
   auto comp = [](pair<ll,ll> a,pair<ll,ll> b) -> bool {
    return a.second > b.second;
   };
   sort(all(lr),comp);
   vector<ll> l(n),r(n);
   rep(i,n) l.at(i) = lr.at(i).first,r.at(i) = lr.at(i).second;
   vector<ll> L = l;
   rep(i,n) L.push_back(r.at(i));
   sort(all(L));
   L.erase(unique(all(L)),L.end());
   fenwick_tree<ll> ft(L.size());
   ll ans = 0;
   rep(i,n) {
    ll x = lower_bound(all(L),r.at(i))-L.begin();
    ans += ft.sum(0,x+1);
    ll y = lower_bound(all(L),l.at(i))-L.begin();
    ft.add(y,1);
   }
   cout << ans << endl;
   
   return 0;
}
