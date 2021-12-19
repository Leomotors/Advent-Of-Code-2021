#include <bits/stdc++.h>
using namespace std;

int N, M;

int main() {
    ifstream in("input.in");

    in >> N >> M;
    int arr[N][M], dp[N][M]{0};

    for (int i = 0; i < N; i++) {
        string l;
        in >> l;
        for (int j = 0; j < M; j++) {
            arr[i][j] = l[j] - '0';
        }
    }

    for (int i = 1; i < N; i++) {
        dp[0][i] = arr[0][i] + dp[0][i - 1];
        dp[i][0] = arr[i][0] + dp[i - 1][0];
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            dp[i][j] = arr[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[N - 1][M - 1] << "\n";
}
