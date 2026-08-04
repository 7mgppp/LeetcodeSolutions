/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    bool dfs(TreeNode* root, int remaining) {
        if (root == NULL)
            return false;

        // at leaf
        if (root->left == NULL && root->right == NULL) {
            return root->val == remaining;
        }

        return dfs(root->left, remaining - root->val) ||
               dfs(root->right, remaining - root->val);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {

        return dfs(root, targetSum);
    }

};