#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
const int INF = 1001001001;
const ll LINF = 1001001001001001001;
const int MOD = 1000000007;

// a * b がオーバーフローするならtrueを返す
template <class T> bool overflow_if_mul(T a, T b) {
    return (std::numeric_limits<T>::max() / a) < b;
}

vector<bool> Eratosthenes(int N) {
    vector<bool> isprime(N+1, true);

    isprime[0] = isprime[1] = false;

    for (int p = 2; p <= N; ++p) {
        if (!isprime[p]) continue;

        for (int q = p * 2; q <= N; q += p) {
            isprime[q] = false;
        }
    }

    return isprime;
}

int main() {

    clock_t start = clock();

  ll n;cin>>n;
  vector<bool> isPrime = Eratosthenes(1000000);
  vector<ll> prime;

  for(ll i=2;i<1000000;i++) {
    if(isPrime.at(i)) prime.push_back(i);
  } 

  ll primeCount = prime.size();
  ll ans = 0;
  for(ll i=0;i<100;i++) {
    ll a = prime.at(i);
    for(ll j=i+1;j<primeCount;j++) {
      ll b = prime.at(j);
      
      int ok = j;
      int ng = primeCount;
      while(ng-ok>1) {
        int mid = (ok+ng)/2;
        ll c = prime.at(mid);
        if(a*a*b*c*c > n
        // || overflow_if_mul(a,a)
        // || overflow_if_mul(a*a,b)
        // || overflow_if_mul(a*a*b,c)
        || overflow_if_mul(a*a*b*c,c)
        ) {
          ng = mid;
        } else ok = mid;
      }
      ans += ok-j;
    }
  }
  cout << ans << endl;
  cout << prime.at(100) << endl;

  
    clock_t end = clock();
    
    const double time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0;
    // printf("time %lf[ms]\n", time);

  exit(0);
}

