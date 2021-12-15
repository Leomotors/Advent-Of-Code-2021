#include <bits/stdc++.h>
using namespace std;

vector<int> crabs;

inline int64_t sigmaI(int n) {
    n = (n > 0) ? n : -n;
    return n * (n + 1) / 2;
}

int64_t calcFuel(int pos) {
    int currE = 0;
    for (auto crab : crabs) {
        currE += sigmaI(crab - pos);
    }
    return currE;
}

int main() {
    //ifstream in("sample.in");
    ifstream in("input.in");

    int N;
    in >> N;

    int maxele = 0;
    for (int i = 0; i < N; i++) {
        int x;
        in >> x;
        maxele = max(maxele, x);
        crabs.push_back(x);
    }

    int64_t minE = LONG_MAX;
    for (int i = 0; i < maxele; i++) {
        minE = min(minE, calcFuel(i));
    }

    cerr << "Max Element: " << maxele << "\n";
    cout << "Answer: " << minE << "\n";
}
