#include <bits/stdc++.h>
using namespace std;

int main() {
    //ifstream in("sample.in");
    ifstream in("input.in");

    int N;
    in >> N;

    vector<int> crabs;
    for (int i = 0; i < N; i++) {
        int x;
        in >> x;
        crabs.push_back(x);
    }

    sort(crabs.begin(), crabs.end());

    int currE = 0;
    for (auto crab : crabs) {
        currE += crab - crabs[0];
    }
    int minE = currE;

    for (int i = 1; i < crabs.size(); i++) {
        int traveled = crabs[i] - crabs[i - 1];
        currE += i * traveled;
        currE -= (crabs.size() - i) * traveled;

        minE = min(minE, currE);
    }

    cout << minE << "\n";
}
