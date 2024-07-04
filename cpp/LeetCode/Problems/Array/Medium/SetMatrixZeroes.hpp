//
//  SetMatrixZeroes.hpp
//  LeetCode
//
//  Created by Salvatore on 4/7/24.
//

#ifndef SetMatrixZeroes_hpp
#define SetMatrixZeroes_hpp

#include <stdio.h>

namespace SetMatrixZeroes {

    void fill_row(vector<vector<int>>& matrix, int r, int cols) {
        for (int c = 0; c < cols; ++c)
            matrix[r][c] = 0;
    }

    void fill_col(vector<vector<int>>& matrix, int c, int rows) {
        for (int r = 0; r < rows; ++r)
            matrix[r][c] = 0;
    }

    void setZeroes(vector<vector<int>>& matrix) {

        int rows = (int)matrix.size();
        int cols = (int)matrix.front().size();
        
        unordered_map<int, bool> rr;
        unordered_map<int, bool> cc;

        for (int r = 0; r < rows; ++r)
            for (int c = 0; c < cols; ++c) {
                if (matrix[r][c] == 0) {
                    rr[r] = true;
                    cc[c] = true;
                }
            }

        for (auto &r : rr)
            fill_row(matrix, r.first, cols);

        for (auto &c : cc)
            fill_col(matrix, c.first, rows);
    }

    void test() {
        vector<vector<vector<int>>> matrix = {
            {{1,1,1},{1,0,1},{1,1,1}},
            {{0,1,2,0},{3,4,5,2},{1,3,1,5}}
        };
        vector<vector<vector<int>>> expected = {
            {{1,0,1},{0,0,0},{1,0,1}},
            {{0,0,0,0},{0,4,5,0},{0,3,1,0}}
        };
        
        for (int i = 0; i < matrix.size(); ++i) {
            setZeroes(matrix[i]);
            assert(matrix[i] == expected[i], matrix[i], expected[i]);
        }
    }
}

#endif /* SetMatrixZeroes_hpp */
