//
//  LengthOfLastWord.hpp
//  LeetCode
//
//  Created by Salvatore on 17/4/24.
//

#ifndef LengthOfLastWord_hpp
#define LengthOfLastWord_hpp

#include <stdio.h>

namespace LengthOfLastWord {

    int lengthOfLastWord(string s) {
        int ans = 0;
        for(int i = (int)s.size() - 1; i >= 0; --i )
            if(s[i] != ' ') ++ans;
            else if(ans > 0) break;

        return ans;
    }

    void test() {
        vector<string> cases = { "Hello World", "   fly me   to   the moon  ", "luffy is still joyboy" };
        
        vector<int> expected = {5, 4, 6};
        
        for(int i = 0; i < cases.size(); ++i){
            int result = lengthOfLastWord(cases[i]);
            assert(result == expected[i], result, expected[i]);
        }
            
    }
}

#endif /* LengthOfLastWord_hpp */
