//
//  IntegerToRoman.hpp
//  LeetCode
//
//  Created by Salvatore on 14/6/24.
//

#ifndef IntegerToRoman_hpp
#define IntegerToRoman_hpp

#include <stdio.h>

namespace IntegerToRoman {

    string intToRoman(int num) {
        string ans = "";
        vector<int> values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> roman = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int index = 0;

        while (num > 0) {
            if (num >= values[index]) {
                num -= values[index];
                ans += roman[index];
            } else {
                ++index;
            }
        }
        return ans;
    }

    void test() {
        
        vector<int> num = {3749, 58, 1994, 400};
        vector<string> expected = {"MMMDCCXLIX", "LVIII", "MCMXCIV", "CD"};
        
        for (int i = 0; i < num[i]; ++i) {
            string result = intToRoman(num[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* IntegerToRoman_hpp */
