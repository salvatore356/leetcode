//
//  ConvertSortedListToBinarySearchTree.hpp
//  LeetCode
//
//  Created by Salvatore on 14/9/23.
//

#ifndef ConvertSortedListToBinarySearchTree_hpp
#define ConvertSortedListToBinarySearchTree_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace ConvertSortedListToBinarySearchTree {

    TreeNode<int>* sortedListToBST(ListNode<int>* head) {
        if (head == nullptr) return nullptr;

        if (head->next == nullptr) return new TreeNode<int>(head->val);

        ListNode<int> *slow = head, *fast = head, *prev = nullptr;

        while( fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev != nullptr) prev->next = nullptr;

        TreeNode<int> *node = new TreeNode<int>(slow->val);
        node->left = sortedListToBST(head);
        node->right = sortedListToBST(slow->next);

        return node;
    }

    vector<vector<int>> cases = {
        { -10, -3, 0, 5, 9 },
        {}
    };

    vector<vector<int>> expected = {
        { 0, -3, 9, -10, INT_MIN, 5 },
        {},
        
    };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            ListNode<int> *list =  loadList(cases[i]);
            auto solutionTree = sortedListToBST(list);
            
            auto solution = treeToArray(solutionTree);
            
            bool passed = compareArrays(solution, expected[i]);
            
            
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

#endif /* ConvertSortedListToBinarySearchTree_hpp */
