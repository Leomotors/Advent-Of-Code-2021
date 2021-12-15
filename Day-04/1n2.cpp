#include <bits/stdc++.h>
using namespace std;

const int INPUT_SIZE = 100;

struct Board {
    map<int, pair<int, int>> numToPos;
    map<pair<int, int>, int> posToNum;
    bool marked[5][5]{false};
    bool ended = false;

    Board(map<int, pair<int, int>> ntp, map<pair<int, int>, int> ptn)
        : numToPos(ntp), posToNum(ptn) {}

    bool isBingo() {
        for (int i = 0; i < 5; i++) {
            // * for each row
            bool bingoRow{true};
            bool bingoCol{true};
            for (int j = 0; j < 5; j++) {
                if (!marked[i][j]) {
                    bingoRow = false;
                }
                if (!marked[j][i]) {
                    bingoCol = false;
                }
            }

            if (bingoRow || bingoCol)
                return true;
        }

        return false;
    }

    bool mark(int n) {
        if (ended)
            return false;

        if (numToPos.find(n) == numToPos.end())
            return false;

        auto pos = numToPos.find(n)->second;
        marked[pos.first][pos.second] = true;

        if (isBingo()) {
            ended = true;
            return true;
        }
        return false;
    }

    int calcScore(int called) {
        int sumrem = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (!marked[i][j]) {
                    sumrem += posToNum[{i, j}];
                }
            }
        }
        return sumrem * called;
    }
};

void part1(vector<Board> boards, vector<int> bingo) {
    for (int called : bingo) {
        for (auto &board : boards) {
            bool res = board.mark(called);

            if (res) {
                cout << board.calcScore(called) << "\n";
                return;
            }
        }
    }
}

void part2(vector<Board> boards, vector<int> bingo) {
    int won = 0;
    for (int called : bingo) {
        for (auto &board : boards) {
            bool res = board.mark(called);

            if (res) {
                won++;
            }

            if (won == boards.size()) {
                cout << board.calcScore(called) << "\n";
                return;
            }
        }
    }
}

int main() {
    ifstream in("1.in");

    vector<int> bingo;
    for (int i = 0; i < INPUT_SIZE; i++) {
        int n;
        in >> n;
        bingo.push_back(n);
    }

    vector<Board> boards;

    for (int b = 0; b < INPUT_SIZE; b++) {
        map<int, pair<int, int>> ntp;
        map<pair<int, int>, int> ptn;

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                int n;
                in >> n;
                ntp[n] = {i, j};
                ptn[{i, j}] = n;
            }
        }
        boards.push_back(Board(ntp, ptn));
    }

    part1(boards, bingo);
    part2(boards, bingo);
}
