#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream in("1.in");

    int count{0};
    int prev{INT_MAX};

    const int last = 10983;

    while (true) {
        int n;
        in >> n;

        if (n > prev) {
            count++;
        }
        prev = n;

        if (n == last)
            break;
    }

    cout << count << "\n";
}