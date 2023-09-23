//
//  BinarySearchTreeIterator.hpp
//  LeetCode
//
//  Created by Salvatore on 23/9/23.
//

#ifndef BinarySearchTreeIterator_hpp
#define BinarySearchTreeIterator_hpp

#include <stdio.h>
#include <queue>

#include "../../../Utils/Utils.hpp"

namespace BinarySearchTreeIterator {
    
    class BSTIterator {
        queue<int> nodes;

        public:
            BSTIterator(TreeNode<int>* root) {
                nodes.push(-1);
                fillNodes(root);
            }
            
            int next() {
                nodes.pop();
                return nodes.front();
            }
            
            bool hasNext() {
                return  nodes.size() > 1;
            }
            
            void fillNodes(TreeNode<int>* root) {
                if (root == NULL) return;
                fillNodes(root->left);
                nodes.push(root->val);
                fillNodes(root->right);
            }

    };


    vector<vector<int>> cases = {
        { 7, 3, 15, INT_MIN, INT_MIN, 9, 20 },
    };

    vector<vector<string>> orders = {
        { "BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext" },
    };

    vector<vector<int>> expected = {
        { INT_MIN, 3, 7, true, 9, true, 15, true, 20, false },
    };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            vector<int> solution;
            solution.push_back(INT_MIN);
            auto iterator = BSTIterator(tree);
            bool passed = true;
            for(int k = 0; k < orders[i].size(); ++k){
                
                if (orders[i][k] == "next" ) {
                    int next = iterator.next();
                    solution.push_back(next);
                    passed &= next == expected[i][k];
                    
                }else if (orders[i][k] == "hasNext" ) {
                    int hasNext = iterator.hasNext();
                    solution.push_back(hasNext);
                    passed &= hasNext == expected[i][k];
                }
                    
            }
             
            printf("Case %d passed %d\n", (i + 1), passed );
            printf("input:\n");
            printf("\tp:\t");
            printArray(cases[i]);
            printf("expected:\t");
            printArray(expected[i]);
            
            printf("solution:\t");
            printArray(solution);
            
            printf("\n");
        }
    }
}

#endif /* BinarySearchTreeIterator_hpp */
