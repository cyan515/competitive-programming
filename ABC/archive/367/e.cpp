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
template <typename T> istream &operator>>(istream &is, vector<T> &v) {for (T &in : v)is >> in;return is;}

vector<int> solve_functional_graph(int n, const vector<int>& graph, ll k) {
    vector<vector<int>> doubling(60, vector<int>(n));

    for (int v = 0; v < n; ++v) {
        doubling[0][v] = graph[v];
    }

    for (int i = 1; i < 60; ++i) {
        for (int v = 0; v < n; ++v) {
            doubling[i][v] = doubling[i-1][doubling[i-1][v]];
        }
    }

    vector<int> result(n);
    for (int v = 0; v < n; ++v) {
        int current = v;
        for (int i = 0; i < 60; ++i) {
            if (k & (1LL << i)) {
                current = doubling[i][current];
            }
        }
        result[v] = current;
    }

    return result;
}

int main() {
  ll n,k;cin>>n>>k;
  vector<int> x(n),a(n);cin>>x>>a;
  rep(i,n) x.at(i)--;
  auto f = solve_functional_graph(n,x,k);
  rep(i,n) {
    if(i) cout << " ";
    cout << a.at(f.at(i));
  }
  cout << endl;

  return 0;
}
