#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    // Sort the cards based on their front sides
    vector<pair<int, int>> cards(N);
    for (int i = 0; i < N; i++) {
        cards[i] = {A[i], i};
    }
    sort(cards.begin(), cards.end());

    // Check if Takahashi can always move
    bool takahashiWins = true;
    for (int i = 0; i < N - 1; i++) {
        if (cards[i].first == cards[i + 1].first) {
            // Remove the two cards with the same front side
            cards.erase(cards.begin() + i);
            cards.erase(cards.begin() + i);
            i--;
        } else if (B[cards[i].second] == B[cards[i + 1].second]) {
            // Remove the two cards with the same back side
            cards.erase(cards.begin() + i);
            cards.erase(cards.begin() + i);
            i--;
        } else {
            takahashiWins = false;
            break;
        }
    }

    cout << (takahashiWins ? "Takahashi" : "Aoki") << endl;

    return 0;
}