//
//  GenerateParentheses.hpp
//  LeetCode
//
//  Created by Salvatore on 30/9/24.
//

#ifndef GenerateParentheses_hpp
#define GenerateParentheses_hpp

#include <stdio.h>

namespace GenerateParentheses {
    
    void generateParenthesisHelper(
        vector<string> &ans, string path, int n, int total, int open, int close
    ) {
        if (path.size() == total) {
            ans.push_back(path);
            return;
        }
        
        if (open < n) {
            path.push_back('(');
            generateParenthesisHelper(ans, path, n, total, open + 1, close);
            path.pop_back();
        }

        if (close < open) {
            path.push_back(')');
            generateParenthesisHelper(ans, path, n, total, open, close + 1);
            path.pop_back();
        }
        
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generateParenthesisHelper(ans, "", n, n * 2, 0, 0);
        return ans;
    }

    void test(){
        vector<int> n = {3, 1};
        vector<vector<string>> expected = {
            {"((()))","(()())","(())()","()(())","()()()"},
            {"()"}
        };
        
        for (int i = 0; i < n.size(); ++i) {
            auto result = generateParenthesis(n[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* GenerateParentheses_hpp */
