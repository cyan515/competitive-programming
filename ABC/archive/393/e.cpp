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
vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},};
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
struct Eratosthenes {
  // テーブル
  vector<bool> isprime;
  
  // 整数 i を割り切る最小の素数
  vector<int> minfactor;

  // コンストラクタで篩を回す
  Eratosthenes(int N) : isprime(N+1, true),
                        minfactor(N+1, -1) {
      // 1 は予めふるい落としておく
      isprime[1] = false;
      minfactor[1] = 1;

      // 篩
      for (int p = 2; p <= N; ++p) {
          // すでに合成数であるものはスキップする
          if (!isprime[p]) continue;

          // p についての情報更新
          minfactor[p] = p;
          
          // p 以外の p の倍数から素数ラベルを剥奪
          for (int q = p * 2; q <= N; q += p) {
              // q は合成数なのでふるい落とす
              isprime[q] = false;
              
              // q は p で割り切れる旨を更新
              if (minfactor[q] == -1) minfactor[q] = p;
          }
      }
  }

  // 高速素因数分解
  // pair (素因子, 指数) の vector を返す
  vector<pair<int,int>> factorize(int n) {
      vector<pair<int,int>> res;
      while (n > 1) {
          int p = minfactor[n];
          int exp = 0;

          // n で割り切れる限り割る
          while (minfactor[n] == p) {
              n /= p;
              ++exp;
          }
          res.emplace_back(p, exp);
      }
      return res;
  }  

  // 高速約数列挙
  vector<int> divisors(int n) {
      vector<int> res({1});

      // n を素因数分解 (メンバ関数使用)
      auto pf = factorize(n);

      // 約数列挙
      for (auto p : pf) {
          int s = (int)res.size();
          for (int i = 0; i < s; ++i) {
              int v = 1;
              for (int j = 0; j < p.second; ++j) {
                  v *= p.first;
                  res.push_back(res[i] * v);
              }
          }
      }
      return res;
  }
};
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n,k;cin>>n>>k;
  vector<int> a(n);cin>>a;
  int m = 1000100;
  Eratosthenes es(m);
  vector fac(m,vector<int>());
  rep(i,n) {
    if(fac.at(a.at(i)).size()) continue;
    fac.at(a.at(i)) = es.divisors(a.at(i));
  }
  vector<int> cnt(m,0);
  rep(i,n) rep(j,fac.at(a.at(i)).size()) {
    cnt.at(fac.at(a.at(i)).at(j))++;
  }
  rep(i,n) {
    int ans = 1;
    rep(j,fac.at(a.at(i)).size()) {
      if(cnt.at(fac.at(a.at(i)).at(j))>=k) chmax(ans,fac.at(a.at(i)).at(j));
    }
    cout << ans << "\n";
  }
  cout << endl;

  return 0;
}
