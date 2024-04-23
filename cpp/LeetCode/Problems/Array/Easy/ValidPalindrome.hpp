//
//  ValidPalindrome.hpp
//  LeetCode
//
//  Created by Salvatore on 22/4/24.
//

#ifndef ValidPalindrome_hpp
#define ValidPalindrome_hpp

#include <stdio.h>

namespace ValidPalindrome {
    
    bool isPalindrome(string s) {
        int lastIndex = s.size() - 1;
        int firstIndex = 0;
        char first, last;
        while(lastIndex > firstIndex){
            
            for(; firstIndex < s.size(); ++firstIndex){
                first = tolower(s[firstIndex]);
                if(isalnum(first)) break;
            }
                
            for(; lastIndex >= 0; --lastIndex){
                last = tolower(s[lastIndex]);
                if(isalnum(last)) break;
            }
            
            printf("%c %c\n", first, last);
            if (!isalnum(last) && !isalnum(first)) return true;
            if(first != last) return false;
            ++firstIndex;
            --lastIndex;
        }

        return true;
    }

    void test() {
        vector<string> cases = {
            "A man, a plan, a canal: Panama",
            "race a car",
            " ",
            ".,",
            "0P"
        };
        vector<bool> expected = {true, false, true, true, false};
        
        for(int i = 0; i < cases.size(); ++i) {
            bool result = isPalindrome(cases[i]);
            assert(result == expected[i], result, expected[i]);
        }
        
        
    }
}

#endif /* ValidPalindrome_hpp */
