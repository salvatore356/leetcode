//
//  RomanToInteger.hpp
//  LeetCode
//
//  Created by Salvatore on 15/4/24.
//

#ifndef RomanToInteger_hpp
#define RomanToInteger_hpp

#include <stdio.h>
#include "../../../Utils/Utils.hpp"

namespace RomanToInteger {
    unordered_map<char, int> values = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100},
        {'D', 500}, {'M', 1000}
    };


    int romanToInt(string s) {

        int currentValue, lastValue = values[s.back()];
        int ans = lastValue;

        for(int i = s.size() - 2; i >= 0; --i) {
            currentValue = values[s[i]];

            if (currentValue >= lastValue) ans += currentValue;
            else  ans -= currentValue;

            lastValue = currentValue;
        }

        return ans;
    }

    void test() {
        vector<string> cases = {
            "III", "LVIII", "MCMXCIV"
        };
        
        vector<int> expected = {
            3, 58, 1994
        };
        
        for (int i = 0; i < cases.size(); ++i){
            int result = romanToInt(cases[i]);
            
            assert(result == expected[i], result, expected[i]);
        }
            
    }

}

#endif /* RomanToInteger_hpp */
