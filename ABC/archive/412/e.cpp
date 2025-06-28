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

// A ^ N を M で割ったあまり
template<class T> T pow_mod(T A, T N, T M) {
    T res = 1 % M;
    A %= M;
    while (N) {
        if (N & 1) res = (res * A) % M;
        A = (A * A) % M;
        N >>= 1;
    }
    return res;
}

// Miller-Rabin 素数判定
bool is_prime(long long N) {
    if (N <= 1) return false;
    if (N == 2) return true;
    if (N % 2 == 0) return false;
    vector<long long> A = {2, 325, 9375, 28178, 450775,
                           9780504, 1795265022};
    long long s = 0, d = N - 1;
    while (d % 2 == 0) {
        ++s;
        d >>= 1;
    }
    for (auto a : A) {
        if (a % N == 0) return true;
        long long t, x = pow_mod<__int128_t>(a, d, N);
        if (x != 1) {
            for (t = 0; t < s; ++t) {
                if (x == N - 1) break;
                x = __int128_t(x) * x % N;
            }
            if (t == s) return false;
        }
    }
    return true;
}

/**
 * @fn
 * n 以下の数が素数かどうかを判定して結果を長さ n+1 の vector で返す
 * 0, 1 は false
 * @brief エラトステネスのふるい
 */
vector<bool> eratosthenes(const int& n) {
  vector<bool> is_prime(n+1, true);
  is_prime[0] = is_prime[1] = false;
  for (int p = 2; p <= n; ++p) {
    if (!is_prime[p]) continue;
    for (int q = p * 2; q <= n; q += p) {
      is_prime[q] = false;
    }
  }
  return is_prime;
}

/**
 * @fn
 * n 以下の素数を列挙して結果を vector で返す
 * @brief 素数列挙
 */
vector<ll> get_primes(int n) {
  auto is_prime = eratosthenes(n);
  vector<ll> ret;
  for(int i=0;i<=n;i++) {
    if(is_prime.at(i)) ret.push_back(i);
  }
  return ret;
}

int main() {
  ll L,R;cin>>L>>R;
  auto ps = get_primes(10000000);
  int n = ps.size();
  rep(i,n) {
    ll x = ps.at(i);
    while(x<100000000000000LL) {
      long z;
      if (__builtin_mul_overflow(x, ps.at(i), &z)) {
        break;
      } else {
        x = z;
      }
      ps.push_back(x);
    }
  }
  sort(all(ps));
  int ans = 1;
  reps(i,L+1,R+1) {
    if(is_prime(i)) {
      ans++;
      continue;
    }
    auto it = lower_bound(all(ps),i);
    if(it==ps.end()) continue;
    if(*it==i) ans++;
  }
  cout << ans << endl;

  return 0;
}
