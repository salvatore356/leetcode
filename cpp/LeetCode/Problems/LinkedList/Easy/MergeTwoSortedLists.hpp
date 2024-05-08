//
//  MergeTwoSortedLists.hpp
//  LeetCode
//
//  Created by Salvatore on 8/5/24.
//

#ifndef MergeTwoSortedLists_hpp
#define MergeTwoSortedLists_hpp

#include <stdio.h>
#include "../../../Utils/Utils.hpp"

namespace MergeTwoSortedLists {
    
    ListNode<int>* mergeTwoLists(ListNode<int>* list1, ListNode<int>* list2) {
       if (list1 == NULL || list2 == NULL) return list1 == NULL ? list2 : list1;

        if (list1->val > list2->val) return mergeTwoLists(list2, list1);
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }

    ListNode<int>* mergeTwoLists2(ListNode<int>* list1, ListNode<int>* list2) {
        
        ListNode<int> *root = new ListNode(0);
        ListNode<int> *cur = root;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }

        cur->next = list1 ? list1 : list2;
        
        return root->next;
    }

    void test() {
        vector<vector<int>> list1 = {
            {1,2,4},
            {},
            {}
        };
        vector<vector<int>> list2 = {
            {1,3,4},
            {},
            {0}
        };
        
        vector<vector<int>> expected = {
            {1,1,2,3,4,4},
            {},
            {0}
        };
        
        for (int i = 0; i < list1.size(); ++i) {
            ListNode<int> *l1 = loadList(list1[i]);
            ListNode<int> *l2 = loadList(list2[i]);
            
            ListNode<int> *r = mergeTwoLists(l1, l2);
            
            auto result = listToVector(r);
            
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* MergeTwoSortedLists_hpp */
