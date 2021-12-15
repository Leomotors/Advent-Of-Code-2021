#include <bits/stdc++.h>
using namespace std;

int main() {
    const int INPUT_LINES = 1000;

    int horizontal = 0;
    int depth = 0;

    ifstream in("1.in");

    for (int i = 0; i < INPUT_LINES; i++) {
        string command;
        int arg;
        in >> command >> arg;

        if (command == "forward") {
            horizontal += arg;
        } else if (command == "down") {
            depth += arg;
        } else if (command == "up") {
            depth -= arg;
        } else {
            cerr << "UNKNOWN COMMAND: " << command << "\n";
        }

        if (depth < 0) {
            cerr << "Something is wrong, I can feel it\n";
        }
    }

    cout << horizontal << " * " << depth << " = " << horizontal * depth << "\n";
}
