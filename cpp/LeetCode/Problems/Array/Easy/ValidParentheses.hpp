//
//  ValidParentheses.hpp
//  LeetCode
//
//  Created by Salvatore on 6/5/24.
//

#ifndef ValidParentheses_hpp
#define ValidParentheses_hpp

#include <stdio.h>

namespace ValidParentheses {
    bool isValid(string s) {
        string ans;
        
        for (int i = 0; i < s.size(); ++i) {
            if(ans.empty()) {
                ans.push_back(s[i]);
                continue;
            }
            
            switch (s[i]) {
                case ')' :
                    if (ans.back() != '(') return false;
                    ans.pop_back();
                    break;
                
                case ']' :
                    if (ans.back() != '[') return false;
                    ans.pop_back();
                    break;
                case '}' :
                    if (ans.back() != '{') return false;
                    ans.pop_back();
                    break;
                default:
                    ans.push_back(s[i]);
            }
        }
        return ans.size() == 0;
    }

    void test() {
        vector<string> s = {"()", "()[]{}", "(]"};
        vector<bool> expected = {true, true, false};
        
        for (int i = 0; i < s.size(); ++i) {
            bool result = isValid(s[i]);
            assert(result == expected[i], result, expected[i]);
        }
        
    }
}

#endif /* ValidParentheses_hpp */
