#include <bits/stdc++.h>
using namespace std;

inline int cvt(int i) {
    return i >= 10 ? (i + 1) % 10 : i;
}

int main() {
    ifstream in("input.in");

    int N, M;
    in >> N >> M;
    int arr[N][M], bigarr[5 * N][5 * M], dp[5 * N + 1][5 * M + 1]{0};

    for (int i = 0; i < N; i++) {
        string l;
        in >> l;
        for (int j = 0; j < M; j++) {
            arr[i][j] = l[j] - '0';
        }
    }

    for (int k1 = 0; k1 < 5; k1++) {
        for (int k2 = 0; k2 < 5; k2++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    bigarr[k1 * N + i][k2 * M + j] = cvt(k1 + k2 + arr[i][j]);
                }
            }
        }
    }

    for (int i = 1; i < 5 * N; i++) {
        dp[0][i] = bigarr[0][i] + dp[0][i - 1];
        dp[i][0] = bigarr[i][0] + dp[i - 1][0];
    }

    for (int i = 1; i <= 5 * N; i++) {
        for (int j = 1; j <= 5 * M; j++) {
            dp[i][j] = INT_MAX / 2;
        }
    }

    // ! Method in Part 1 does not work for all cases
    // ! The problem does not specify that you can't move upward or left
    for (int l = 0; l < 5 * N; l++)
        for (int i = 1; i < 5 * N; i++) {
            for (int j = 1; j < 5 * M; j++) {
                dp[i][j] =
                    bigarr[i][j] +
                    min(dp[i - 1][j],
                        min(dp[i][j - 1], min(dp[i + 1][j], dp[i][j + 1])));
            }
        }

    cout << dp[5 * N - 1][5 * M - 1] << "\n";
}
