#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("input.in");

    int N, M;
    in >> N >> M;

    int cave[N + 2][M + 2];

    for (int i = 0; i <= N + 1; i++) {
        cave[i][0] = 10;
        cave[i][M + 1] = 10;
    }

    for (int j = 0; j <= M + 1; j++) {
        cave[0][j] = 10;
        cave[N + 1][j] = 10;
    }

    for (int i = 1; i <= N; i++) {
        string l;
        in >> l;
        for (int j = 1; j <= M; j++) {
            cave[i][j] = l[j - 1] - '0';
        }
    }

    int weaksum = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (cave[i][j] < cave[i - 1][j] && cave[i][j] < cave[i + 1][j] &&
                cave[i][j] < cave[i][j - 1] && cave[i][j] < cave[i][j + 1]) {
                weaksum += 1 + cave[i][j];
            }
        }
    }

    cout << weaksum << "\n";
}
