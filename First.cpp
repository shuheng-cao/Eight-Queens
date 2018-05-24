//
//  First.cpp
//  Eight Queens
//
//  Created by shuster on 2018/5/23.
//  Copyright © 2018 曹书恒. All rights reserved.
//

#include "First.hpp"
#include <iostream>

using namespace std;
static int cnt = 0;

bool invalid(int posn1, int posn2) {
    int x1 = posn1 % 8;
    int x2 = posn2 % 8;
    int y1 = posn1 / 8;
    int y2 = posn2 / 8;
    bool row = (x1 == x2);
    bool column = (y1 == y2);
    bool diagonal = abs(x1-x2) == abs(y1 - y2);
    return row || column || diagonal;
}

bool member(int x, int arr[8]) {
    for (int i = 0; i < 8; ++i) {
        if (x == arr[i]) return true;
    }
    return false;
}

void print(int queens[8]) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (member(8 * i + j, queens)) {
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

bool validqueen(int x, int queens[], int length) {
    for (int i = 0; i < length; ++i) {
        if (invalid(x, queens[i])) {
            return false;
        }
    }
    return true;
}

void check(int row, int queens[8]) {
    if (row > 7) {
        cnt++;
        print(queens);
        return;
    }
    for (int col = 0; col < 8; ++col){
        if (validqueen(8 * row + col, queens, row)) {
            queens[row] = row * 8 + col;
            check(row + 1, queens);
        }
    }
}

int main(int argc, const char * argv[]) {
    int queens[8] = { 0 };
    check(0, queens);
    cout << cnt << endl;
    return 0;
}
