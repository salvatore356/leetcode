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
void convertTreeToArray(TreeNode<T> *root, std::vector<T> &arr, int index) {
    if (root == nullptr) {
        return; // Skip null nodes
    }

    // Expand the array if needed
    if (index >= arr.size()) {
        arr.resize(index + 1);
    }

    arr[index] = root->val;
    convertTreeToArray(root->left, arr, 2 * index + 1);
    convertTreeToArray(root->right, arr, 2 * index + 2);
}

template <typename T>
std::vector<T> treeToArray(TreeNode<T> *root) {
    std::vector<T> arr;
    convertTreeToArray(root, arr, 0);
    return arr;
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
        printf("%d ", arr[i]);
    printf("\n");
    
}
#endif /* Utils_hpp */
