#include <string>
#include<list>
#include <algorithm>
#include <iostream>

using namespace std;

int sudoky[9][9];

void swapCollumn_segments(int c1, int c2) {
    int x = 0;
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 9; i++) {
            x = sudoky[i][j + c1 * 3];
            sudoky[i][j + c1 * 3] = sudoky[i][j + c2 * 3];
            sudoky[i][j + c2 * 3] = x;
        }
    }
}

void swapRow_segments(int s1, int s2) {
    int x = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 9; j++) {
            x = sudoky[i + 3 * s1][j];
            sudoky[i + 3 * s1][j] = sudoky[i + 3 * s2][j];
            sudoky[i + 3 * s2][j] = x;
        }
    }
}

void transpose() {
    int x = 0;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++) {
            x = sudoky[i][j];
            sudoky[i][j] = sudoky[j][i];
            sudoky[j][i] = x;
        }
}

pair<int, int> random(int n) {
    int a = 0, b = 0;
    while (a == b) {
        a = rand() % 3 + 3 * n;
        b = rand() % 3 + 3 * n;
    }
    return make_pair(a, b);
}

void swapCollumns(int j1, int j2) {
    int x;
    for (int i = 0; i < 9; i++) {
        x = sudoky[i][j1];
        sudoky[i][j1] = sudoky[i][j2];
        sudoky[i][j2] = x;
    }
}

void swapRows(int i1, int i2) {
    int x;
    for (int j = 0; j < 9; j++) {
        x = sudoky[i1][j];
        sudoky[i1][j] = sudoky[i2][j];
        sudoky[i2][j] = x;
    }
}

void printMatrix() {
    for (int i = 0; i < 9; i++) {
        if (i % 3 == 0)
            cout << "----------------------" << endl;
        for (int j = 0; j < 9; j++) {
            if (j % 3 == 0)
                cout << "|";
            cout << sudoky[i][j] << " ";
        }
        cout << "|";
        cout << endl;
    }
    cout << "----------------------" << endl << endl;
}

void shift(int i) {
    int x = sudoky[i][0];
    for (int j = 0; j < 8; j++) {
        sudoky[i][j] = sudoky[i][j + 1];
    }
    sudoky[i][8] = x;
}

void mix() {
    pair<int, int> p;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            p = random(i);
            swapRows(p.first, p.second);
            transpose();
            p = random(j);
            swapCollumns(p.first, p.second);
            transpose();
        }
    }
    p = random(0);
    swapRow_segments(p.first, p.second);
    p = random(0);
    swapCollumn_segments(p.first, p.second);
}

void generate() {
    for (int j = 1; j < 10; j++) {
        sudoky[0][j - 1] = j;
    }
    cout << endl;
    for (int i = 1; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            sudoky[i][j] = sudoky[i - 1][(j + 3) % 9];
        }
        if (i % 3 == 0) {
            shift(i);
        }
    }
    mix();
    printMatrix();
}

int main()
{
    generate();
}
