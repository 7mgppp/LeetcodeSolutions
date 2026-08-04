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
    int dfs(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);

        if(root->left == NULL){
            return right+1;
        }

        if(root->right == NULL){
            return left + 1;
        }

        return 1 + min(left, right);
    }

public:
    int minDepth(TreeNode* root) {

        return dfs(root);

    }
};