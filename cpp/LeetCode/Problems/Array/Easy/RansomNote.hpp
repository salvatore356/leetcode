//
//  RansomNote.hpp
//  LeetCode
//
//  Created by Salvatore on 23/4/24.
//

#ifndef RansomNote_hpp
#define RansomNote_hpp

#include <stdio.h>

namespace RansomNote {
    
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> letters(26);

        for(auto &letter: magazine)
            ++letters[letter - 'a'];

        for(auto &letter: ransomNote){
            if(--letters[letter - 'a'] < 0) return false;
        }

        return true;
    }

    void test() {
        vector<string> ransomNote = { "a", "aa", "aa" };
        vector<string> magazine = { "b", "ab", "aab" };
        vector<bool> expected = { false, false, true };
        
        for(int i = 0; i < ransomNote.size(); ++i){
            bool result = canConstruct(ransomNote[i], magazine[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* RansomNote_hpp */
