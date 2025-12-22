//
//  ReverseString.h
//  LeetCode
//
//  Created by Salvatore on 22/12/25.
//

#ifndef ReverseString_hpp
#define ReverseString_hpp


#include <stdio.h>

namespace ReverseString {
    
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            swap(s[left], s[right]);
            ++left;
            --right;
        }
    }
    
    void test(){
        vector<vector<char>> input = {
            {'h','e','l','l','o'},
            {'H','a','n','n','a','h'}
        };
        
        
        vector<vector<char>> expected = {
            {'o','l','l','e','h'},
            {'h','a','n','n','a','H'}
        };
        
        for (int i = 0; i < input.size(); ++i) {
            reverseString(input[i]);
            assert(input[i] == expected[i], input[i], expected[i]);
        }
    }
}


#endif /* ReverseString_hpp */
