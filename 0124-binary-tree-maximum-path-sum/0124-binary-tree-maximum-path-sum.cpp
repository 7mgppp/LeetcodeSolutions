/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int maxPath = INT_MIN;

    int dfs(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);

        left = max(0, left);
        right = max(0, right);

        maxPath = max(maxPath, root->val + left + right);

        return root->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxPath;

        
    }
};