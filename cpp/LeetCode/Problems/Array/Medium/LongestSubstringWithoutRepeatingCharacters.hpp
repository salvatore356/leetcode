//
//  LongestSubstringWithoutRepeatingCharacters.hpp
//  LeetCode
//
//  Created by Salvatore on 25/6/24.
//

#ifndef LongestSubstringWithoutRepeatingCharacters_hpp
#define LongestSubstringWithoutRepeatingCharacters_hpp

#include <stdio.h>

namespace LongestSubstringWithoutRepeatingCharacters {
    
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> count;
        int maxSub = 0;
        
        int idx0 = 0, idx1 = 0;
        
        while (idx1 < s.size()) {
            
            ++count[s[idx1]];

            while (count[s[idx1]] > 1) {
                --count[s[idx0]];
                ++idx0;
            }
            maxSub = max(maxSub, idx1 - idx0 + 1);
            ++idx1;
        }
        
        return maxSub;
    }

    void test() {
        vector<string> s = {"abcabcbb", "bbbbb", "pwwkew", "au", "aab"};
        vector<int> expected = {3, 1, 3, 2, 2};
        
        for (int i = 0; i < s.size(); ++i) {
            int result = lengthOfLongestSubstring(s[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* LongestSubstringWithoutRepeatingCharacters_hpp */
