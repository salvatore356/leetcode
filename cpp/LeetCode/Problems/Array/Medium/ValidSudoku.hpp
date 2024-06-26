//
//  ValidSudoku.hpp
//  LeetCode
//
//  Created by Salvatore on 26/6/24.
//

#ifndef ValidSudoku_hpp
#define ValidSudoku_hpp

#include <stdio.h>

namespace ValidSudoku {
    
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<unordered_map<char, bool>> rows(9);
        vector<unordered_map<char, bool>> cols(9);

        vector<unordered_map<char, bool>> cross(9);
        
        for (int r = 0; r < board.size(); ++r) {
            
            for (int c = 0; c < board.front().size(); ++c) {
                char &value = board[r][c];
                
                if (value == '.') continue;
                int index = (r / 3) * 3 + (c / 3);
                if (cols[c][value] || rows[r][value] || cross[index][value])
                    return false;
                
                cross[index][value] = true;
                cols[c][value] = true;
                rows[r][value] = true;
            }

        }

        return true;
    }

    void test() {
        vector<vector<vector<char>>> board = {
            {
                {'5','3','.','.','7','.','.','.','.'},
                {'6','.','.','1','9','5','.','.','.'},
                {'.','9','8','.','.','.','.','6','.'},
                {'8','.','.','.','6','.','.','.','3'},
                {'4','.','.','8','.','3','.','.','1'},
                {'7','.','.','.','2','.','.','.','6'},
                {'.','6','.','.','.','.','2','8','.'},
                {'.','.','.','4','1','9','.','.','5'},
                {'.','.','.','.','8','.','.','7','9'}
            },
            {
                {'8','3','.','.','7','.','.','.','.'},
                {'6','.','.','1','9','5','.','.','.'},
                {'.','9','8','.','.','.','.','6','.'},
                {'8','.','.','.','6','.','.','.','3'},
                {'4','.','.','8','.','3','.','.','1'},
                {'7','.','.','.','2','.','.','.','6'},
                {'.','6','.','.','.','.','2','8','.'},
                {'.','.','.','4','1','9','.','.','5'},
                {'.','.','.','.','8','.','.','7','9'}
            }
        };
        
        vector<bool> expected = {true, false};
        
        for (int i = 0; i < board.size(); ++i) {
            bool result = isValidSudoku(board[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* ValidSudoku_hpp */
