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
class CumulativeSum3D {
public:
    CumulativeSum3D(int x, int y, int z) : X(x), Y(y), Z(z) {
        sum.assign(X + 1, vector<vector<long long>>(Y + 1, vector<long long>(Z + 1, 0)));
    }

    // 値を追加
    void add(int x, int y, int z, long long value) {
        sum[x + 1][y + 1][z + 1] += value;
    }

    // 累積和を構築
    void build() {
        for (int i = 1; i <= X; ++i) {
            for (int j = 1; j <= Y; ++j) {
                for (int k = 1; k <= Z; ++k) {
                    sum[i][j][k] += sum[i - 1][j][k] + sum[i][j - 1][k] + sum[i][j][k - 1]
                                 - sum[i - 1][j - 1][k] - sum[i - 1][j][k - 1] - sum[i][j - 1][k - 1]
                                 + sum[i - 1][j - 1][k - 1];
                }
            }
        }
    }

    // 領域 (x1, y1, z1) から (x2, y2, z2) までの部分和を計算
    long long query(int x1, int y1, int z1, int x2, int y2, int z2) {
        return sum[x2 + 1][y2 + 1][z2 + 1]
             - sum[x1][y2 + 1][z2 + 1]
             - sum[x2 + 1][y1][z2 + 1]
             - sum[x2 + 1][y2 + 1][z1]
             + sum[x1][y1][z2 + 1]
             + sum[x1][y2 + 1][z1]
             + sum[x2 + 1][y1][z1]
             - sum[x1][y1][z1];
    }

private:
    int X, Y, Z;
    vector<vector<vector<long long>>> sum;
};

vector<vector<vector<ll>>> compute3DPrefixSum(const vector<vector<vector<ll>>>& vec) {
    int x_size = vec.size();
    if (x_size == 0) return {};
    int y_size = vec[0].size();
    if (y_size == 0) return {};
    int z_size = vec[0][0].size();
    if (z_size == 0) return {};

    vector<vector<vector<ll>>> prefixSum(x_size, vector<vector<ll>>(y_size, vector<ll>(z_size, 0)));

    // 累積和を計算
    for (int x = 0; x < x_size; ++x) {
        for (int y = 0; y < y_size; ++y) {
            for (int z = 0; z < z_size; ++z) {
                prefixSum[x][y][z] = vec[x][y][z];

                if (x > 0) prefixSum[x][y][z] += prefixSum[x-1][y][z];
                if (y > 0) prefixSum[x][y][z] += prefixSum[x][y-1][z];
                if (z > 0) prefixSum[x][y][z] += prefixSum[x][y][z-1];

                if (x > 0 && y > 0) prefixSum[x][y][z] -= prefixSum[x-1][y-1][z];
                if (y > 0 && z > 0) prefixSum[x][y][z] -= prefixSum[x][y-1][z-1];
                if (z > 0 && x > 0) prefixSum[x][y][z] -= prefixSum[x-1][y][z-1];

                if (x > 0 && y > 0 && z > 0) prefixSum[x][y][z] += prefixSum[x-1][y-1][z-1];
            }
        }
    }

    return prefixSum;
}

int main() {
  ll n;cin>>n;
  vector a(n,vector(n,vector<ll>(n)));
  CumulativeSum3D pref(n,n,n);
  rep(i,n) rep(j,n) rep(k,n) {
    ll v;cin>>v;
    pref.add(i,j,k,v);
  }
  pref.build();
  int Q;cin>>Q;
  while(Q--) {
    int s,t,u,v,w,x;cin>>s>>t>>u>>v>>w>>x;s--;t--;u--;v--;w--;x--;
    cout << pref.query(s,u,w,t,v,x) << endl;
  }

  return 0;
}
