//
//  VerifyPreorderSerializationOfABinaryTree.hpp
//  LeetCode
//
//  Created by Salvatore on 4/10/23.
//

#ifndef VerifyPreorderSerializationOfABinaryTree_hpp
#define VerifyPreorderSerializationOfABinaryTree_hpp

#include <stdio.h>
#include <sstream>

#include "../../../Utils/Utils.hpp"

namespace VerifyPreorderSerializationOfABinaryTree {
    
    bool isValidSerialization(string preorder) {
        stringstream str(preorder);
        string node;
        int count = 1;

        while(getline(str, node, ',')){
            --count;
            if(count < 0) return false;
            if(node != "#") count = count + 2;
        }
        return count == 0;
    }
    
    vector<string> cases = {
         "9,3,4,#,#,1,#,#,2,#,6,#,#" ,
         "1,#" ,
         "9,#,#,1"
    };

    vector<int> expected = { true, false, false };

    
    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            
            
            auto solution = isValidSerialization(cases[i]);
             
            bool passed = solution == expected[i];
            
            
            printf("Case %d passed %d\n", (i + 1), passed );
            printf("input:\n");
            printf("\tp:\t%s\n", cases[i].c_str());
            printf("expected:\t%d\n", expected[i]);
            
            printf("solution:\t%d\n", solution);
            
            printf("\n");
        }
    }

}

#endif /* VerifyPreorderSerializationOfABinaryTree_hpp */
