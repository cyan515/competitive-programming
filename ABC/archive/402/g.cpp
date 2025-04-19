#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    vector<int> S(N), C(N), P(N);
    for (int i = 0; i < N; ++i) {
        cin >> S[i] >> C[i] >> P[i];
    }

    vector<double> dp(X + 1, 0.0); // dp[x] := コストxでの最大期待値

    for (int i = 0; i < N; ++i) {
        vector<double> f(X + 1, 0.0);
        double p = P[i] / 100.0;

        // 部分ナップサック: f[c] に「この問題のみで得られる最大期待値」を貯める
        for (int c = 0; c <= X; ++c) {
            // この問題にさらに1回提出する場合
            if (c + C[i] <= X) {
                double succeed = f[c] + (1.0 - f[c]) * p;
                f[c + C[i]] = max(f[c + C[i]], succeed);
            }
        }

        // メインDPにマージ
        for (int x = X; x >= 0; --x) {
            for (int c = 0; c <= x; ++c) {
                dp[x] = max(dp[x], dp[x - c] + f[c] * S[i]);
            }
        }
    }

    // 答えは dp[X] の最大値
    cout << fixed << setprecision(12) << *max_element(dp.begin(), dp.end()) << endl;

    return 0;
}
