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

    bool seen[N + 2][M + 2]{false};
    priority_queue<int, vector<int>, greater<int>> topCaves;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (seen[i][j] || cave[i][j] >= 9)
                continue;

            seen[i][j] = true;
            int size = 1;
            queue<pair<int, int>> toCheck(
                {{i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}});

            while (!toCheck.empty()) {
                auto [x, y] = toCheck.front();
                toCheck.pop();

                if (seen[x][y] || cave[x][y] >= 9)
                    continue;

                seen[x][y] = true;
                size++;

                toCheck.push({x - 1, y});
                toCheck.push({x + 1, y});
                toCheck.push({x, y - 1});
                toCheck.push({x, y + 1});
            }

            topCaves.push(size);
            if (topCaves.size() > 3)
                topCaves.pop();
        }
    }

    int product = 1;
    while (!topCaves.empty()) {
        product *= topCaves.top();
        cout << topCaves.top() << "\n";
        topCaves.pop();
    }

    cout << product << "\n";
}
