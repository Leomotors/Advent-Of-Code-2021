#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("1.in");

    const int last = 10983;

    vector<int> data;

    while (true) {
        int n;
        in >> n;

        data.push_back(n);

        if (n == last)
            break;
    }

    int count{0};

    int slidingSum = data[0] + data[1] + data[2];
    for (int i = 3; i < data.size(); i++) {
        int newSum = slidingSum + data[i] - data[i - 3];

        if (newSum > slidingSum) {
            count++;
        }

        slidingSum = newSum;
    }

    cout << count << "\n";
}