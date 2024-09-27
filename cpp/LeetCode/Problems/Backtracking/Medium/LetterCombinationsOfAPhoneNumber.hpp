//
//  LetterCombinationsOfAPhoneNumber.hpp
//  LeetCode
//
//  Created by Salvatore on 27/9/24.
//

#ifndef LetterCombinationsOfAPhoneNumber_hpp
#define LetterCombinationsOfAPhoneNumber_hpp

#include <stdio.h>

namespace LetterCombinationsOfAPhoneNumber {
    unordered_map<char, vector<char>> pad = {
        {'2', {'a', 'b', 'c'} },
        {'3', {'d', 'e', 'f'} },
        {'4', {'g', 'h', 'i'} },
        {'5', {'j', 'k', 'l'} },
        {'6', {'m', 'n', 'o'} },
        {'7', {'p', 'q', 'r', 's'} },
        {'8', {'t', 'u', 'v'} },
        {'9', {'w', 'x', 'y', 'z'} }
    };

    void letterCombinationHelper(
        vector<string> &ans,  string &digits, int position,  string combination
    ) {
        if (position > digits.size()) return;
        if (combination.size() > digits.size()) return;

        if (combination.size() == digits.size() && !combination.empty()) {
            ans.push_back(combination);
            return;
        }

        for (int i = 0; i < pad[digits[position]].size(); ++i) {
            letterCombinationHelper(ans, digits, position + 1, combination + pad[digits[position]][i]);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        letterCombinationHelper(ans, digits, 0, "");
        return ans;
    }
    void test(){
        vector<string> digits = {"23", "", "2"};
        vector<vector<string>> expected = {
            {"ad","ae","af","bd","be","bf","cd","ce","cf"},
            {},
            {"a","b","c"}
        };
        
        for (int i = 0; i < digits.size(); ++i) {
            auto result = letterCombinations(digits[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* LetterCombinationsOfAPhoneNumber_hpp */
