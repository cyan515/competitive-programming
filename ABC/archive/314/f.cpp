#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
const int MAX_N = 1005;

int N, M;
int P[MAX_N];
int S[MAX_N][MAX_N];
int C[MAX_N]; // ルーレットのコスト

double dp[MAX_N][MAX_N];

double solve(int i, int m) {
    if (m >= M) return 0.0;
    if (i > N) return INF;
    if (dp[i][m] != -1.0) return dp[i][m];

    double ans = INF;
    for (int j = 1; j <= P[i]; ++j) {
        ans = min(ans, (double)C[i] + solve(i, m + S[i][j]));
    }

    return dp[i][m] = ans;
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> C[i] >> P[i];
        for (int j = 1; j <= P[i]; ++j) {
            cin >> S[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    double answer = solve(1, 0);
    cout << fixed << setprecision(10) << answer << endl;

    return 0;
}
