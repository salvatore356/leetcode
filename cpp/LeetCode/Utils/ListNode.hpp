//
//  ListNode.hpp
//  LeetCode
//
//  Created by Salvatore on 14/9/23.
//

#ifndef ListNode_hpp
#define ListNode_hpp

#include <stdio.h>

template <typename T>
struct ListNode {
    T val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(T x) : val(x), next(nullptr) {}
    ListNode(T x, ListNode *next) : val(x), next(next) {}
};

#endif /* ListNode_hpp */
