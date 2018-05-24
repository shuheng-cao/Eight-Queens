//
//  Second.cpp
//  Eight Queens
//
//  Created by shuster on 2018/5/23.
//  Copyright © 2018 曹书恒. All rights reserved.
//

#include "Second.hpp"
#include <iostream>
int count = 0;
int board[8][8];
int soln[8][8];

void print(void) {
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j){
            std::cout << soln[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool valid(int x1, int y1, int x2, int y2) {
    bool row = (x1 == x2);
    bool col = (y1 == y2);
    bool dia = (abs(x1 - x2) == abs(y1 - y2));
    return (row || col || dia);
}

void PlaceQueens(int ith){
    if(ith == 8) {
        count ++;
        print();
        return;
    }
    for(int i = 0; i < 8; i++){
        if(board[i][ith] == -1) {
            board[i][ith] = ith;
            soln[i][ith] = ith + 1;
            for(int k = 0; k < 8; k++) {
                for(int r = 0; r < 8; r++) {
                    if(board[k][r] == -1 && valid(k, r, i, ith)) {
                        board[k][r] = ith;
                    }
                }
            }
            PlaceQueens(ith + 1);
            for(int k = 0; k < 8; k++) {
                for(int r = 0; r < 8; r++) {
                    if(board[k][r] == ith) board[k][r] = -1;
                    if(soln[k][r] == ith + 1) soln[k][r] = 0;
                }
            }
        }
    }
}


int main() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            board[i][j] = -1;
        }
    }
    PlaceQueens(0);
    std::cout << count << std::endl;
}

