#include <bits/stdc++.h>
using namespace std;

//const int INPUT_SIZE = 5;
const int INPUT_SIZE = 300;

int main() {
    //ifstream in("sample.in");
    ifstream in("1.in");

    int64_t DP[260]{0};

    for (int i = 0; i <= 6; i++)
        DP[i] = 2;
    DP[7] = 3;
    DP[8] = 3;

    for (int i = 9; i <= 256; i++) {
        DP[i] = DP[i - 7] + DP[i - 9];
    }

    int64_t fishes = 0;

    for (int i = 0; i < INPUT_SIZE; i++) {
        int n;
        in >> n;
        fishes += DP[256 - n - 1];
    }

    cout << fishes << "\n";
}
