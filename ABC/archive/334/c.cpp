#include <bits/stdc++.h>
#define rep(i,a,n) for(int i = a;i < n; i++) 
#define yes (cout << "Yes" << endl)
#define YES (cout << "YES" << endl)
#define no (cout << "No" << endl)
#define NO (cout << "NO" << endl)
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define all(a)  (a).begin(),(a).end()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vd = vector<double>;
using vl = vector<long long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<long long>>;
using Graph = vector<vector<int>>;
const int mod = 998244353;
const int MOD = 1000000007;
const double pi = 3.141592653589793238;
const string abc = "abcdefghijklmnopqrstuvwxyzabcdefg";
const string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFG";
ll dight_sum(ll t) {
    ll ans = 0;
    while(t >= 10) {
        ans += t % 10;
        t /= 10;
    }
    ans += t;
    return ans;
}

vector<bool> seen;
vector<ll> vv;
void dfs(const Graph &G, ll v) {
    seen[v] = true; // v を訪問済にする
    vv.pb(v);
    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout << setprecision(20) << endl;
    /////////////////
    ////////////////
    ////////////////
    /////////////
    ll n,m;
    cin >> n >> m;
    vl v;
    rep(i,0,m) {
        ll k;
        cin >> k;
        v.pb(k);
    }
    if(v.size() == 1) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
        ll mi = 1e15;
    if(v.size() % 2 == 0) {
        for(ll i = 0; i <= v.size() -2; i += 2) {
            ans += v[i + 1] - v[i];
        }
        cout << ans << endl;
    }
    else {
        ll p = 0;
        ll q = 0;
        for(ll k = 1; k <= m - 2; k += 2) {
            q += v[k + 1] - v[k];
        }
        for(ll i = 0; i <= m - 1; i += 2) {
            //i を削除する
            mi = min(mi,p + q);
            if(i == 0) {

            }
            else {
                p += v[i - 1] - v[i - 2];
                q -= v[i] - v[i - 1];
            }
            //cout << p << q << endl;
        }
        cout << mi << endl;
    }
}
