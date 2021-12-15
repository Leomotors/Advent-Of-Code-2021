#include <bits/stdc++.h>
using namespace std;

int main() {
    const int BITS = 12;
    const int TWOPOW[]{2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
    const int LINES = 1000;

    int heatmap[BITS]{0};

    ifstream in("1.in");
    for (int i = 0; i < LINES; i++) {
        string bits;
        in >> bits;

        for (int j = 0; j < BITS; j++) {
            if (bits[j] == '1') {
                heatmap[j] += 1;
            }
        }
    }

    int gamma = 0;
    int epsilon = 0;
    for (int i = 0; i < BITS; i++) {
        if (heatmap[i] > LINES / 2) {
            gamma += TWOPOW[i];
        } else {
            epsilon += TWOPOW[i];
        }
    }

    cout << gamma << " * " << epsilon << " = " << gamma * epsilon << "\n";
}
