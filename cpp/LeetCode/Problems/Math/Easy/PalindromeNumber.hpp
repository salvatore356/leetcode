//
//  PalindromeNumber.hpp
//  LeetCode
//
//  Created by Salvatore on 15/5/24.
//

#ifndef PalindromeNumber_hpp
#define PalindromeNumber_hpp

#include <stdio.h>

namespace PalindromeNumber {
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;
    
        int reversed = 0;
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
       
        return x == reversed || x == reversed / 10;
    }

    void test() {
        vector<int> x = {0, -121, 10, 0, 1000021};
        vector<bool> expected = {true, false, false, true, false};
        
        for (int i = 0; i < x.size(); ++i) {
            bool result = isPalindrome(x[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* PalindromeNumber_hpp */
