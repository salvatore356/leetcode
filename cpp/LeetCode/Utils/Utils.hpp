//
//  Utils.hpp
//  LeetCode
//
//  Created by Salvatore on 5/8/23.
//

#ifndef Utils_hpp
#define Utils_hpp

#include <stdio.h>
#include "TreeNode.hpp"
#include "ListNode.hpp"

template <typename T>
inline TreeNode<T>* loadNode(vector<T> &arr, int index){
    if(index >= arr.size() || arr[index] == INT_MIN) return nullptr;
    
    TreeNode<T> *root = new TreeNode<T>(arr[index]);
    root->left = loadNode(arr, 2 * index + 1);
    root->right = loadNode(arr, 2 * index + 2);
    
    return root;
}

template <typename T>
inline TreeNode<T>* loadTree(vector<T> &arr){
    TreeNode<T> *root = loadNode(arr, 0);
    return root;
}

template <typename T>
void convertTreeToArray(TreeNode<T> *root, std::vector<T> &arr, int index, bool mandatory) {
    if (root == nullptr) {
        return; // Skip null nodes
    }

    // Expand the array if needed
    while (index >= arr.size()) {
        arr.push_back(INT_MIN); // Initialize with default value
    }

    arr[index] = root->val;
    convertTreeToArray(root->left, arr, 2 * index + 1, root->right != nullptr);
    convertTreeToArray(root->right, arr, 2 * index + 2, false);
}

template <typename T>
std::vector<T> treeToArray(TreeNode<T> *root) {
    std::vector<T> arr;
    convertTreeToArray(root, arr, 0, false);
    return arr;
}

void parseVector(vector<int> &v) {
    for(int i = 0; i < v.size(); ++i)
        if(v[i] == 0) v[i] = INT_MIN;
}

template <typename T>
bool compareArrays(vector<T> &A, vector<T> &B) {
    
    if(A.size() != B.size()) return false;
    
    for(int i = 0; i < A.size(); ++i)
        if(A[i] != B[i]) return false;
    return true;
}

void printArray(vector<int> &arr) {
    for(int i = 0; i < arr.size(); ++i)
        if(arr[i] == INT_MIN) printf("null ");
        else printf("%d ", arr[i]);
    printf("\n");
    
}

void printArray(vector<double> &arr) {
    for(int i = 0; i < arr.size(); ++i)
        printf("%f ", arr[i]);
    printf("\n");
    
}

void printArray(vector<string> &arr) {
    
    for(int i = 0; i < arr.size(); ++i)
        printf("%s ", arr[i].c_str());
    printf("\n");
    
}

template <typename T>
ListNode<T>* loadList(const vector<T>& items) {
    if (items.empty()) {
        return nullptr;
    }

    ListNode<T>* list = new ListNode<T>(items[0]);
    auto head = list;

    for (int i = 1; i < items.size(); ++i) {
        head->next = new ListNode<T>(items[i]);
        head = head->next;
    }

    return list;
}

template <typename T>
vector<T> listToVector(ListNode<T>* head) {
    vector<T> result;
    while (head) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

#endif /* Utils_hpp */
