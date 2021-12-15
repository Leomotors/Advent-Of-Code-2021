#include <bits/stdc++.h>
using namespace std;

//const int INPUT_SIZE = 5;
const int INPUT_SIZE = 300;

struct Fish {
    int timeLeft;
    Fish(int t1);

    void update();
};

vector<Fish> fishes;

Fish::Fish(int t1) : timeLeft(t1) {}

void Fish::update() {
    timeLeft--;

    if (timeLeft < 0) {
        timeLeft = 6;
        fishes.push_back(Fish(8));
    }
}

int main() {
    //ifstream in("sample.in");
    ifstream in("1.in");

    for (int i = 0; i < INPUT_SIZE; i++) {
        int n;
        in >> n;
        fishes.push_back(Fish(n));
    }

    for (int d = 1; d <= 80; d++) {
        cerr << "Before Day #" << d << " " << fishes.size() << "\n";
        int64_t currSize = fishes.size();
        for (int j = 0; j < currSize; j++) {
            fishes[j].update();
        }
    }

    cout << fishes.size() << "\n";
}
