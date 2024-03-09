#include<bits/stdc++.h>
#include<atcoder/all>
using namespace atcoder;
using mint=modint998244353;
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define rep(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define rrep(i,a,b) for(ll i=(ll)(a-1);i>=(ll)(b);i--)
#define MOD 998244353
//#define MOD 1000000007
#define INF 1e18
#define Pair pair<ll,ll>
//#define PI numbers::pi
//#define E numbers::e
template <typename T> bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
ll dx[4]={0,1,0,-1};
ll dy[4]={1,0,-1,0};
/*
using S=ll;
using F=ll;
const S INF=8e18;
S op(S a,S b){return min(a,b);}
S e(){return INF;}
S mapping(F f, S x){return (f+x)%2;}
F composition(F f, F g){return (f+g)%2;}
F id(){return 0;}
*/

int main(){
    ll n; cin >> n;
    vector<ll> a(n),b(n+2,0);
    rep(i,0,n) cin >> a[i];
    rep(i,0,n) b[i+1]=a[i];
    map<ll,Pair> mp;
    rep(i,1,n) mp[b[i]]={b[i-1],b[i+1]};
    mp[0]={b[n],b[1]};
    ll q; cin >> q;
    while(q--){
        ll t; cin >> t;
        if(t==1){
            ll x,y; cin >> x >> y;
            ll z=mp.at(x).second;
            mp[y]={x,z};
            mp.at(z)={y,mp.at(z).second};
            mp.at(x)={mp.at(x).first,y};
        }
        else{
            ll x; cin >> x;
            ll y=mp.at(x).first,z=mp.at(x).second;
            mp.at(y)={mp.at(y).first,z};
            mp.at(z)={y,mp.at(z).second};
            mp.erase(x);
        }
    }
    ll now=0;
    while(true){
        if(mp[now].second==0) break;
        cout << mp[now].second << ' ';
        now=mp[now].second;
    }
    cout << endl;
}