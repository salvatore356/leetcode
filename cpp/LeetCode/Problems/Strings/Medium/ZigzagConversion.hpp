//
//  ZigzagConversion.hpp
//  LeetCode
//
//  Created by Salvatore on 18/6/24.
//

#ifndef ZigzagConversion_hpp
#define ZigzagConversion_hpp

#include <stdio.h>

namespace ZigzagConversion {

    string convert(string s, int numRows) {
        
        if (numRows < 2) return s;
        
        vector<string> words(numRows);
        
        int sum = 1;
        int row = 0;
        for (int i = 0; i < s.size(); ++i) {
            words[row].push_back(s[i]);
            
            row += sum;
            if (row == 0) sum = 1;
            else if (row == numRows - 1) sum = -1;
        }
        
        string ans;
        for(int i = 0; i < words.size(); ++i) {
            ans.append(words[i]);
        }
        

        return ans;
    }
    void test() {
        vector<string> s = {"PAYPALISHIRING", "PAYPALISHIRING", "A", "AB"};
        vector<int> numRows = {3, 4, 1, 1};
        vector<string> expected = {"PAHNAPLSIIGYIR", "PINALSIGYAHRPI", "A", "AB"};
        
        for (int i = 0; i < s.size(); ++i) {
            string result = convert(s[i], numRows[i]);

            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* ZigzagConversion_hpp */
