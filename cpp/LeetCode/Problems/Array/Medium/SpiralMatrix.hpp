//
//  SpiralMatrix.hpp
//  LeetCode
//
//  Created by Salvatore on 27/6/24.
//

#ifndef SpiralMatrix_hpp
#define SpiralMatrix_hpp

#include <stdio.h>

namespace SpiralMatrix {
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = (int)matrix.size();
        int cols = (int)matrix.front().size();
        
        vector<int> ans; // ( rows * cols);

        vector<bool> col (cols);
        vector<vector<bool>> m(rows, col);

        int r = 0; int c = 0;
        
        while (ans.size() < rows * cols) {
            for (; c < cols; ++c) {
                if (m[r][c]) break;
                ans.push_back(matrix[r][c]);
                m[r][c] = true;
                
            }
            --c;
            ++r;
            
            for (; r < rows; ++r) {
                if (m[r][c]) break;
                ans.push_back(matrix[r][c]);
                m[r][c] = true;
                
            }
            --r;
            --c;

            for (; c >= 0; --c) {
                if (m[r][c]) break;
                ans.push_back(matrix[r][c]);
                m[r][c] = true;
                
            }
            ++c;
            --r;
            for (; r >= 0; --r) {
                if (m[r][c]) break;
                ans.push_back(matrix[r][c]);
                m[r][c] = true;
            }
            ++r;
            ++c;
        }


        return ans;
    }
    
    void test() {
        vector<vector<vector<int>>> matrix = {
            {
                {1,2,3},
                {4,5,6},
                {7,8,9}
            },
            {
                {1,2,3,4},
                {5,6,7,8},
                {9,10,11,12}
            }
        };
        
        vector<vector<int>> expected = {
            {1,2,3,6,9,8,7,4,5},
            {1,2,3,4,8,12,11,10,9,5,6,7}
        };
        
        for (int i = 0; i < matrix.size(); ++i) {
            vector<int> result = spiralOrder(matrix[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* SpiralMatrix_hpp */
