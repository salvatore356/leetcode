//
//  FindTheIndexOfTheFirstOccurrenceInAString.hpp
//  LeetCode
//
//  Created by Salvatore on 19/4/24.
//

#ifndef FindTheIndexOfTheFirstOccurrenceInAString_hpp
#define FindTheIndexOfTheFirstOccurrenceInAString_hpp

#include <stdio.h>

namespace FindTheIndexOfTheFirstOccurrenceInAString {
    int strStr(string haystack, string needle) {
        
        int limit = (int)(haystack.size() - needle.size() + 1);
        if(limit < 0) return -1;
        int equal = 0;
        int pos = -1;

        for(int i = 0; i < limit; ++i){
            equal = 0;
            for(int j = 0; j < needle.size(); ++j){
                if(haystack[i + j] != needle[j]) break;
                else ++equal;
            }
            
            if(equal == needle.size()) {
                pos = i;
                break;
            }
        }

        return pos;
    }

    void test() {
        vector<string> haystack = {"sadbutsad", "mississippi", "mississippi", "abc", "abb"};
        vector<string> needle = {"sad", "mississippii", "issip", "c", "abaaa"};
        vector<int> expected = {0, -1, 4, 2, -1};
        
        for(int i = 0; i < haystack.size(); ++i){
            int result = strStr(haystack[i], needle[i]);
            assert(result == expected[i], result, expected[i]);
        }
        
    }
}

#endif /* FindTheIndexOfTheFirstOccurrenceInAString_hpp */
