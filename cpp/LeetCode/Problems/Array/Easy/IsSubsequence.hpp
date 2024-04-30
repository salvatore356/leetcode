//
//  IsSubsequence.hpp
//  LeetCode
//
//  Created by Salvatore on 30/4/24.
//

#ifndef IsSubsequence_hpp
#define IsSubsequence_hpp

#include <stdio.h>

namespace IsSubsequence {
    bool isSubsequence(string s, string t) {
        int currentIndex = 0;

        for (int i = 0; i < t.size(); ++i) {
            currentIndex += s[currentIndex] == t[i];
        }
        
        return currentIndex == s.size();
    }

    void test() {
        vector<string> s = {"axc", "abc"};
        vector<string> t = {"ahbgdc", "ahbgdc"};
        vector<bool> expected = {false, true};
        
        for (int i = 0; i < s.size(); ++i) {
            bool result = isSubsequence(s[i], t[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* IsSubsequence_hpp */
