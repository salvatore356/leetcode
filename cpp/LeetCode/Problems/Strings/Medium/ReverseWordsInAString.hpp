//
//  ReverseWordsInAString.hpp
//  LeetCode
//
//  Created by Salvatore on 17/6/24.
//

#ifndef ReverseWordsInAString_hpp
#define ReverseWordsInAString_hpp

#include <stdio.h>

namespace ReverseWordsInAString {
    
    string reverseWords(string s) {
       string ans;

       int i = 0;
       while (i<s.size()) {
           while(s[i] == ' ') ++i;

           string word;
           while (s[i] != ' ' && i < s.size()) {
               word.push_back(s[i]);
               ++i;
           }

           if (!word.empty())
               ans = word + (ans.empty() ? "": " ") + ans;
       }
       return ans;
   }

    void test() {
        vector<string> s = {"the sky is blue", "  hello world  ", "a good   example"};
        vector<string> expected = {"blue is sky the", "world hello", "example good a"};
        
        for (int i = 0; i < s.size(); ++i) {
            string result = reverseWords(s[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* ReverseWordsInAString_hpp */
