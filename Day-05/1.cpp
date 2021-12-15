#include <bits/stdc++.h>
using namespace std;

const int LINES = 500;

int field[1000][1000]{0};

int main() {
    ifstream in("1.in");

    for (int l = 0; l < LINES; l++) {
        int a, b, c, d;
        in >> a >> b >> c >> d;

        // * (a, b) -> (c, d)
        if (a != c && b != d)
            continue;

        if (b != d) {
            for (int i = min(b, d); i <= max(b, d); i++)
                field[a][i] += 1;
        } else {
            for (int i = min(a, c); i <= max(a, c); i++) {
                field[i][b] += 1;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            if (field[i][j] >= 2) {
                count++;
            }
        }
    }
    cout << count << "\n";
}
