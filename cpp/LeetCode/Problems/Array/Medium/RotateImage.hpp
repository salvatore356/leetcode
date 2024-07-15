//
//  RotateImage.hpp
//  LeetCode
//
//  Created by Salvatore on 3/7/24.
//

#ifndef RotateImage_hpp
#define RotateImage_hpp

#include <stdio.h>

namespace RotateImage {
    void rotate(vector<vector<int>>& matrix) {
        
        int w = (int)matrix.size();
        for (int r = 0; r < w - 1; ++r)
            for (int c = r + 1; c < w; ++c)
                swap(matrix[r][c], matrix[c][r]);
            
        for (int i = 0; i < w; ++i)
            reverse(matrix[i].begin(), matrix[i].end());
    }

    void test() {
        vector<vector<vector<int>>> matrix = {
            {{1,2,3},{4,5,6},{7,8,9}},
            {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}}
        };
        
        vector<vector<vector<int>>> expected = {
            {{7,4,1},{8,5,2},{9,6,3}},
            {{15,13,2,5},{14,3,4,1},{12,6,8,9},{16,7,10,11}}
        };
        
        for (int i = 0; i < matrix.size(); ++i) {
            rotate(matrix[i]);
            
            assert(matrix[i] == expected[i], matrix[i], expected[i]);
        }
        
    }
}

#endif /* RotateImage_hpp */
