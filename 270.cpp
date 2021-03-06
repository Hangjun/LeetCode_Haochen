/*
270. Closest Binary Search Tree Value

Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
Note:
Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        TreeNode* node = root;
        int res = node->val;
        while(node) {
            if(abs(target - node->val) < abs(target - res)) {
                res = node->val;
            }

            if(target < node->val) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        
        return res;
    }
};
