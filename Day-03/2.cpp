#include <bits/stdc++.h>
using namespace std;

const int BITS = 12;
const int TWOPOW[]{2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
const int LINES = 1000;

int getRate(vector<string> numbers, char c1, char c2) {
    int bits = 0;

    while (numbers.size() > 1) {
        int oneCount = 0;
        for (auto &num : numbers) {
            if (num[bits] == '1') {
                oneCount++;
            }
        }

        char toKeep;
        if (oneCount >= numbers.size() / 2)
            toKeep = c1;
        else
            toKeep = c2;

        vector<string> newNumbers;
        copy_if(numbers.begin(), numbers.end(), back_inserter(newNumbers),
                [toKeep, bits](const string &s) { return s[bits] == toKeep; });
        numbers = newNumbers;
        bits++;
    }

    int rate = 0;
    for (int i = 0; i < BITS; i++) {
        if (numbers[0][i] == '1') {
            rate += TWOPOW[i];
        }
    }

    return rate;
}

int main() {

    vector<string> numbers;

    ifstream in("1.in");
    for (int i = 0; i < LINES; i++) {
        string bits;
        in >> bits;
        numbers.push_back(bits);
    }

    int o2 = getRate(numbers, '1', '0');
    int co2 = getRate(numbers, '0', '1');

    cout << o2 << " * " << co2 << " = " << o2 * co2 << "\n";
}
