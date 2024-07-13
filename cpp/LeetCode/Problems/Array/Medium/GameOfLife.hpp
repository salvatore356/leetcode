//
//  GameOfLife.hpp
//  LeetCode
//
//  Created by Salvatore on 13/7/24.
//

#ifndef GameOfLife_hpp
#define GameOfLife_hpp

#include <stdio.h>

namespace GameOfLife {
    int countAlive(vector<vector<int>>& board, int r, int c, int rows, int cols) {
        int count = 0;

        int r0 = r - 1;
        int r1 = r + 1;

        int c0 = c - 1;
        int c1 = c + 1;

        if (r0 >= 0) {
            count += board[r0][c];

            if (c0 >= 0)
                count += board[r0][c0];
            
            if(c1 < cols)
                count += board[r0][c1];
        }

        if (r1 < rows) {
            count += board[r1][c];
            
            if(c0 >= 0)
                count += board[r1][c0];
            
            if(c1 < cols)
                count += board[r1][c1];
        }
        
        if(c0 >= 0)
            count += board[r][c0];
        
        if(c1 < cols)
            count += board[r][c1];

        return count;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board.front().size();

        auto copy = board;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                int alive = countAlive(copy, r, c, rows, cols);

                if (board[r][c] == 0)
                    board[r][c] = alive == 3;
                else board[r][c] = alive == 3 || alive == 2;
            }
        }
    }

    void test(){
        vector<vector<vector<int>>> board = {
            {{0,1,0},{0,0,1},{1,1,1},{0,0,0}},
            {{1,1},{1,0}}
        };
        
        vector<vector<vector<int>>> expected = {
            {{0,0,0},{1,0,1},{0,1,1},{0,1,0}},
            {{1,1},{1,1}}
        };
        
        for (int i = 0; i < board.size(); ++i) {
            gameOfLife(board[i]);
            assert(board[i] == expected[i], board[i], expected[i]);
        }
        
    }
}

#endif /* GameOfLife_hpp */
