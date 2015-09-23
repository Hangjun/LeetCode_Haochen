/*
103. Binary Tree Zigzag Level Order Traversal

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},

   3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> record;
        queue<TreeNode*> q;
        if(root == NULL) return res;
        TreeNode* node;
        q.push(root);
        q.push(NULL);
        while(!q.empty()) {
            node = q.front();
            q.pop();
            if(node == NULL) {
                res.push_back(record);
                record.clear();
                if(!q.empty()) {
                    q.push(NULL);
                } else {
                    break;
                }
            } else {
                record.push_back(node->val);
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
        }
        for(int i = 1; i < res.size(); i += 2) {
            reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
};
